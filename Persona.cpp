#include "Persona.h"
// Actualizado

Persona::Persona(string _nomPais, string _ciudad, string _id, string _correo, string _nac, string _nombre) : Cliente(_nomPais, _ciudad) {
	id = _id;
	correo = _correo;
	nacionalidad = _nac;
	nombre = _nombre;
}

Persona::~Persona() {
}

string Persona::getId() {
	return id;
}

string Persona::getCorreo() {
	return correo;
}

string Persona::getNacionalidad() {
	return nacionalidad;
}

string Persona::getNombre() {
	return nombre;
}

string Persona::getNomPais() {
	return nomPais;
}

string Persona::getCiudad() {
	return ciudad;
}

string Persona::toString() {
	stringstream s;
	s << "-------Datos del cliente-------" << endl;
	s << "Cedula: " << id << endl;
	s << "Nombre: " << nombre << endl;
	s << "Nacionalidad: " << nacionalidad << endl;
	s << "Pais de residencia: " << nomPais << endl;
	s << "Ciudad de envio: " << ciudad << endl;
	s << "Correo electronico: " << correo << endl;
	s << "-------------------------------" << endl;
	return s.str();
}

void Persona::update() {
	cout << "Se han agregado nuevos sistemas al Catalogo" << endl;
}
