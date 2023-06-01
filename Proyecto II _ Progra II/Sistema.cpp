#include "Sistema.h"


Sistema::Sistema() : Componente() {
	lista = new Lista<Componente>();
}

Sistema::~Sistema() {
	delete lista;
}

void Sistema::obtenerPrecio() {
	this->precio = lista->getPrecioTotal();
}

std::string Sistema::toString() {
	std::stringstream s;
	s << lista->toString();
	return s.str();
}

void Sistema::agregar(Componente* c) {
	lista->insertarFinal(c);
}


