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
// Actualizado

class Cliente {  // Observer
protected:
	std::string nomPais;
	std::string ciudad;
public:
	Cliente(std::string = " ", std::string = " ") {}
	virtual ~Cliente() {}
	virtual std::string toString() = 0;
	virtual std::string getNomPais() = 0;
	virtual std::string getCiudad() = 0;
	virtual void update() = 0;
};

#endif // !CLIENTE_H
