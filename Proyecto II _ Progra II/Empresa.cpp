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

#include "Empresa.h"
// Actualizado

Empresa::Empresa(std::string _nomPais, std::string _ciudad, std::string _nomEmpresa, std::string _cedJurid, Catalogo* _catalogo) 
	: Cliente(_nomPais, _ciudad, _cedJurid, _catalogo) {
	nombre = _nomEmpresa;
}

Empresa::~Empresa() {
}

bool Empresa::esEmpresa() { return true; }

std::string Empresa::toString() {
	std::stringstream s;
	s << "-----------Datos de la Empresa-----------" << std::endl;
	s << "-----------------------------------------" << std::endl;
	s << "Cedula Juridica: " << id << std::endl;
	s << "Nombre: " << nombre << std::endl;
	s << "Pais donde se ubica: " << nomPais << std::endl;
	s << "Ciudad donde se ubica: " << ciudad << std::endl;
	s << "-----------------------------------------" << std::endl;
	return s.str();
}

std::string Empresa::guardarDatos() {
	std::stringstream s;
	s << id << DELIMITA_CAMPO; //DELIMITA_CAMPO sirve como separador entre cada dato.
	s << nombre << DELIMITA_CAMPO;
	s << nomPais << DELIMITA_CAMPO;
	s << ciudad << DELIMITA_CAMPO;
	return s.str();
}

void Empresa::update() {
	std::cout << "Se han agregado nuevos sistemas al Catalogo" << std::endl;
}