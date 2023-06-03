#include "Persona.h"
// Actualizado

Persona::Persona(std::string _nomPais, std::string _ciudad, std::string _id, std::string _correo, std::string _nac, std::string _nombre) : Cliente(_nomPais, _ciudad) {
	id = _id;
	correo = _correo;
	nacionalidad = _nac;
	nombre = _nombre;
}

Persona::~Persona() {
}

std::string Persona::getId() {
	return id;
}

std::string Persona::getCorreo() {
	return correo;
}

std::string Persona::getNacionalidad() {
	return nacionalidad;
}

std::string Persona::getNombre() {
	return nombre;
}

std::string Persona::getNomPais() {
	return nomPais;
}

std::string Persona::getCiudad() {
	return ciudad;
}

std::string Persona::toString() {
	std::stringstream s;
	s << "-------Datos del cliente-------" << std::endl;
	s << "Cedula: " << id << std::endl;
	s << "Nombre: " << nombre << std::endl;
	s << "Nacionalidad: " << nacionalidad << std::endl;
	s << "Pais de residencia: " << nomPais << std::endl;
	s << "Ciudad de envio: " << ciudad << std::endl;
	s << "Correo electronico: " << correo << std::endl;
	s << "-------------------------------" << std::endl;
	return s.str();
}

void Persona::update() {
	std::cout << "Se han agregado nuevos sistemas al Catalogo" << std::endl;
}