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

#include "Persona.h"
// Actualizado

Persona::Persona(std::string _nomPais, std::string _ciudad, std::string _id, std::string _correo, std::string _nac, std::string _nombre, Catalogo* _catalogo)
	: Cliente(_nomPais, _ciudad, _id, _catalogo) {
	correo = _correo;
	nacionalidad = _nac;
	nombre = _nombre;
}

Persona::~Persona() {
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