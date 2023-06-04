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

Empresa::Empresa(std::string _nomPais, std::string _ciudad, std::string _nomEmpresa, std::string _cedJurid) : Cliente(_nomPais, _ciudad) {
	nomEmpresa = _nomEmpresa;
	cedJurid = _cedJurid;
}

Empresa::~Empresa() {
}

std::string Empresa::getCedJurid() {
	return cedJurid;
}

std::string Empresa::getNomEmpresa() {
	return nomEmpresa;
}

std::string Empresa::getNomPais() {
	return nomPais;
}

std::string Empresa::getCiudad() {
	return ciudad;
}

std::string Empresa::toString() {
	std::stringstream s;
	s << "-------Datos de la Empresa-------" << std::endl;
	s << "Cedula Juridica: " << cedJurid << std::endl;
	s << "Nombre: " << nomEmpresa << std::endl;
	s << "Pais donde se ubica: " << nomPais << std::endl;
	s << "Ciudad de envio: " << ciudad << std::endl;
	s << "---------------------------------" << std::endl;
	return s.str();
}

void Empresa::update() {
	std::cout << "Se han agregado nuevos sistemas al Catalogo" << std::endl;
}