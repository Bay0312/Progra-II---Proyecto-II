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

#ifndef CLIENTE_H
#define CLIENTE_H
#include <sstream>
#include <iostream>
#include "Catalogo.h"
// Actualizado

class Catalogo; //Declaracion previa

class Cliente {  // Observer
protected:
	std::string id; //Ya sea cedula juridica o no.
	std::string nombre;
	std::string nomPais;
	std::string ciudad;
	Catalogo* catalogo;

public:
	Cliente(std::string _nomPais = " ", std::string _ciudad= " ", std::string _id = "", Catalogo* _catalogo = nullptr)
		: nomPais{ _nomPais }, ciudad{ _ciudad }, id{ _id }, catalogo { _catalogo } {}
	virtual ~Cliente() {}
	virtual void setCatalogo(Catalogo* _catalogo) { catalogo = _catalogo; }
	std::string getId() { return id; }
	std::string getNomPais() { return nomPais; }
	std::string getCiudad() { return ciudad; }
	virtual bool esEmpresa() = 0;
	virtual std::string toString() = 0;
	virtual std::string guardarDatos() = 0;
	virtual void update() = 0;
};

#endif // !CLIENTE_H
