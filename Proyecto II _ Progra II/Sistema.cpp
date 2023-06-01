#include "Sistema.h"


Sistema::Sistema(int tamannio) : Componente() {
	cant = 0;
	tam = tamannio;
	vec = new Componente * [tam];
	for (int i = 0; i < tam; i++) {
		vec[i] = nullptr;
	}
}

Sistema::~Sistema() {
	for (int i = 0; i < this->cant; i++) {
		delete vec[i];
	}
	delete[] vec;
}

void Sistema::obtenerPrecio() {
	double precio = 0;
	for (int i = 0; i < this->cant; i++) {
		precio += vec[i]->obtenerPrecio();
	}
	this->precio = precio;
}

std::string Sistema::toString() {
	std::stringstream s;
	s << "Sistema : " << codigo << "\n";
	for (int i = 0; i < this->cant; i++) {
		s << vec[i]->toString() << "\n";
	}
	s << "Precio Total: " << precio << "\n";
	return s.str();
}

void Sistema::agregar(Componente* c) {
	if (cant < tam) {
		vec[cant++] = c;
		this->obtenerPrecio(); //Actualiza el precio
	}
	else {
		throw new std::string("No se pueden agregar mas componentes.");
	}
}


