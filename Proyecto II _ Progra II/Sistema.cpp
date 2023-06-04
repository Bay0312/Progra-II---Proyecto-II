/* --------------------------------------------------------------------
*
* EIF204 Programación 2
* Proyecto 2
*
* 4-0254-0670 David Calvo H. grupo 02
* 7-0300-0234 Bayron Vega A. grupo 03
*
* -------------------------------------------------------------------
*/

#include "Sistema.h"

//Constructor y Destructor
Sistema::Sistema() : Componente() {
	lista = new Lista<Componente>();
}

Sistema::~Sistema() {
	if(lista != nullptr) delete lista;
}

//Metodos Varios
void Sistema::agregar(Componente* c) { 
	lista->insertarFinal(c);
}

void Sistema::obtenerPrecio() {
	this->precio = lista->getPrecioTotal();
}

std::string Sistema::toString() {
	std::stringstream s;
	s << lista->toString();
	return s.str();
}