#include "Procesador.h"

Procesador::Procesador() : Componente(), categoria{ "" }, tipo{ "" }, caracteristicas{ "" } {}
Procesador::Procesador(std::string cat, std::string tip, std::string car, std::string cod, double pre) : categoria{ cat }, tipo{ tip }, caracteristicas{ car } {
	codigo = cod;
	precio = pre;
}
Procesador::~Procesador() {}

std::string Procesador::toString() const {
	std::stringstream s;
	s << "Procesador: " << codigo << " " << precio << " " << categoria << " " << tipo << " " << caracteristicas << std::endl;
	return s.str();
}

double Procesador::obtenerPrecio() const {
	return precio;
}

void Procesador::agregar() { throw new std::string("No se supone que la clase procesador agregue."); }

std::string Procesador::getCategoria() const {
	return categoria;
}

std::string Procesador::getTipo() const {
	return tipo;
}

std::string Procesador::getCaracteristicas() const {
	return caracteristicas;
}

void Procesador::setCategoria(std::string categoria) {
	this->categoria = categoria;
}

void Procesador::setTipo(std::string componente) {
	this->tipo = componente;
}

void Procesador::setCaracteristicas(std::string caracteristicas) {
	this->caracteristicas = caracteristicas;
}


