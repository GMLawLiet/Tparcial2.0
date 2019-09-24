
#include"CPersonaje.h"

class CJuego {
private:
	CPersonaje* objPersonaje;

public:
	CJuego(int X, int Y);
	~CJuego();

	void Dibujar(Graphics^g, Bitmap^imgPersonaje);
	void Set_Movimiento(TypeMovimiento TipoMovimiento);
	void MoverPersonaje(Keys Tecla);


};

CJuego::CJuego(int X, int Y) {
	objPersonaje = new CPersonaje(X,Y);


}
CJuego::~CJuego() {}
void CJuego::Set_Movimiento(TypeMovimiento TipoMovimiento) {
	objPersonaje->Set_Movimiento(TipoMovimiento);

}

void CJuego::Dibujar(Graphics^g, Bitmap^imgPersonaje) {

	objPersonaje->Dibujar(g, imgPersonaje);

}
void CJuego::MoverPersonaje(Keys Tecla) {
	objPersonaje->Mover(Tecla);
}


