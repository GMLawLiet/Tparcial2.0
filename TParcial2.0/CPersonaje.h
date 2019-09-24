#pragma once
#include"CMovimiento.h"
#include<vector>
#include<stdio.h>

enum TypeMovimiento {Estatico,Movimiento};

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;


class CPersonaje {
private:
	int X, Y;
	int indice;
	vector<CMovimiento*>* arrMovimiento;
	TypeMovimiento TipoMovimiento;



public:
	CPersonaje(int x, int y);
	~CPersonaje();

	void Dibujar(Graphics^g , Bitmap^imgPersonaje);
	void Set_Movimiento(TypeMovimiento TipoMovimiento);
	

	
	int Get_X();
	int Get_Y();
	int Get_Ancho();
	int Get_Largo();



};

CPersonaje::CPersonaje(int X, int Y) {
	//inicializacion 
	this->X = X;
	this->Y = Y;
	this->indice = 0;
	this->arrMovimiento = new vector<CMovimiento*>();
	Set_Movimiento(TypeMovimiento::Estatico);


}

CPersonaje::~CPersonaje() {}

void CPersonaje::Dibujar(Graphics^g, Bitmap^imgPersonaje) {

	// destino donde estara la imagen obtenida de los datos obtenidos de los archivos de texto
	// y almacenada en el arreglo arrmovimiento
	Rectangle Origen = Rectangle(arrMovimiento->at(indice)->Get_X(),
		arrMovimiento->at(indice)->Get_Y(),
		arrMovimiento->at(indice)->Get_Ancho(),
		arrMovimiento->at(indice)->Get_Largo()   );

	Rectangle Destino = Rectangle(X,arrMovimiento->at(indice)->Get_Largo(),
		arrMovimiento->at(indice)->Get_Ancho(),
		arrMovimiento->at(indice)->Get_Largo()   );

	g->DrawImage(imgPersonaje, Destino, Origen, GraphicsUnit::Pixel);


	// para el efecto estatico cuando no se ejecuta ningun key event

	if (indice == arrMovimiento->size() - 1) {
		if (TipoMovimiento != TypeMovimiento::Estatico)
			Set_Movimiento(TypeMovimiento::Estatico);

		indice = 0;
	}
	else
		indice++;



}

void CPersonaje::Set_Movimiento(TypeMovimiento TipoMovimiento) {

	// obtencion de los datos para los tipos de movimiento del cualquier imagen agregada
	// (personaje/enemigo ,etc)
	this->TipoMovimiento = TipoMovimiento;
	
	char* Archivo = new char[100];

	switch(TipoMovimiento)
	{
	case TypeMovimiento::Estatico: strcpy(Archivo, "Estatico.txt"); break;
	case TypeMovimiento::Movimiento: strcpy(Archivo, "Movimiento.txt"); break;

	}

	int NroMovimiento, X, Y, Ancho, Largo, dX, dY;
	freopen(Archivo, "r", stdin);

	scanf("%d", &NroMovimiento);
	arrMovimiento->clear();


	for (int i = 0; i < NroMovimiento; i++) {
		scanf("%d %d %d %d %d %d", &X, &Y, &Ancho, &Largo, &dX, &dY);
		arrMovimiento->push_back(new CMovimiento(X,Y,Ancho,Largo,dX,dY));

	}
	

}

int CPersonaje::Get_X(){
	return this->X;
}

int CPersonaje::Get_Y(){
	return this->Y;
}

int CPersonaje::Get_Ancho(){
	return arrMovimiento->at(indice)->Get_Ancho();
}

int CPersonaje::Get_Largo(){
	return arrMovimiento->at(indice)->Get_Largo();

}



