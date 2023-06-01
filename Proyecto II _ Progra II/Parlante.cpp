#include "Parlante.h"

Parlante::Parlante() : Componente(), categoria{ "" }, tipo{ "" }, caracteristicas{ "" } {}
Parlante::Parlante(std::string cat, std::string tip, std::string car, std::string cod, double pre) : categoria{ cat }, tipo{ tip }, caracteristicas{ car } {
	codigo = cod;
	precio = pre;
}
Parlante::~Parlante() {}

std::string Parlante::toString() const {
	std::stringstream s;
	s << "Parlante: " << codigo << " " << precio << " " << categoria << " " << tipo << " " << caracteristicas << std::endl;
	return s.str();
}

double Parlante::obtenerPrecio() const {
	return precio;
}

void Parlante::agregar() { throw new std::string("No se supone que la clase parlante agregue."); }

std::string Parlante::getCategoria() const {
	return categoria;
}

std::string Parlante::getTipo() const {
	return tipo;
}

std::string Parlante::getCaracteristicas() const {
	return caracteristicas;
}

void Parlante::setCategoria(std::string categoria) {
	this->categoria = categoria;
}

void Parlante::setTipo(std::string componente) {
	this->tipo = componente;
}

void Parlante::setCaracteristicas(std::string caracteristicas) {
	this->caracteristicas = caracteristicas;
}