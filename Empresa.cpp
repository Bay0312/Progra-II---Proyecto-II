#include "Empresa.h"
// Actualizado

Empresa::Empresa(string _nomPais, string _ciudad, string _nomEmpresa, string _cedJurid) : Cliente(_nomPais, _ciudad) {
	nomEmpresa = _nomEmpresa;
	cedJurid = _cedJurid;
}

Empresa::~Empresa() {
}

string Empresa::getCedJurid() {
	return cedJurid;
}

string Empresa::getNomEmpresa() {
	return nomEmpresa;
}

string Empresa::getNomPais() {
	return nomPais;
}

string Empresa::getCiudad() {
	return ciudad;
}

string Empresa::toString() {
	stringstream s;
	s << "-------Datos de la Empresa-------" << endl;
	s << "Cedula Juridica: " << cedJurid << endl;
	s << "Nombre: " << nomEmpresa << endl;
	s << "Pais donde se ubica: " << nomPais << endl;
	s << "Ciudad de envio: " << ciudad << endl;
	s << "---------------------------------" << endl;
	return s.str();
}

void Empresa::update() {
	cout << "Se han agregado nuevos sistemas al Catalogo" << endl;
}
