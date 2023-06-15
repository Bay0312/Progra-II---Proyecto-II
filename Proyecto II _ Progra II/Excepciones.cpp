#include "Excepciones.h"

std::string ExcepcionValor::toString() {
	std::stringstream s;
	s << "ERROR: El valor ingresado no es v�lido." << std::endl;
	return s.str();
}

std::string ExcepcionDeExistencia::toString() {
	std::stringstream s;
	s << "ERROR: Ya existe un elemento con ese identificador." << std::endl;
	return s.str();
}