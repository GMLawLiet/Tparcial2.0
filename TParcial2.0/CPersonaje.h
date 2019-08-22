#pragma once
#include<vector>
#include<stdio.h>

//enum TypeMovimiento {Estatico};

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;


class CPersonaje {
private:
	int X, Y;



public:
	CPersonaje(int x, int y);
	~CPersonaje();

	void dibujar(Graphics^g , Bitmap^imgPersonaje);
	
	


};

CPersonaje::CPersonaje(int X, int Y) {
	this->X = X;
	this->Y = Y;



}

CPersonaje::~CPersonaje() {}

void CPersonaje::dibujar(Graphics^g, Bitmap^imgPersonaje) {



}
