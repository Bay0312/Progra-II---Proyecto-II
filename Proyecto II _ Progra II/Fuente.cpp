#include "Fuente.h"

Fuente::Fuente() : Componente(), categoria{ "" }, tipo{ "" }, caracteristicas{ "" } {}
Fuente::Fuente(std::string cat, std::string tip, std::string car, std::string cod, double pre) : categoria{ cat }, tipo{ tip }, caracteristicas{ car } {
	codigo = cod;
	precio = pre;
}
Fuente::~Fuente() {}

std::string Fuente::toString() const {
	std::stringstream s;
	s << "Fuente: " << codigo << " " << precio << " " << categoria << " " << tipo << " " << caracteristicas << std::endl;
	return s.str();
}

double Fuente::obtenerPrecio() const {
	return precio;
}

void Fuente::agregar() { throw new std::string("No se supone que la clase fuente agregue."); }

std::string Fuente::getCategoria() const {
	return categoria;
}

std::string Fuente::getTipo() const {
	return tipo;
}

std::string Fuente::getCaracteristicas() const {
	return caracteristicas;
}

void Fuente::setCategoria(std::string categoria) {
	this->categoria = categoria;
}

void Fuente::setTipo(std::string componente) {
	this->tipo = componente;
}

void Fuente::setCaracteristicas(std::string caracteristicas) {
	this->caracteristicas = caracteristicas;
}
