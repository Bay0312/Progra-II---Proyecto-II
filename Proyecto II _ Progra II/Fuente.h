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

#ifndef FUENTE_H
#define FUENTE_H
#include "Componente.h"

class Fuente: public Componente {
private:
	std::string categoria;
	std::string tipo;
	std::string caracteristicas;

public:
	//Constructores y Destructor
	Fuente();
	Fuente(std::string, std::string, std::string, std::string, double);
	virtual ~Fuente();

	//Getters
	std::string getCategoria() const;
	std::string getTipo() const;
	std::string getCaracteristicas() const;

	//Setters
	void setCategoria(std::string);
	void setTipo(std::string);
	void setCaracteristicas(std::string);

	//Metodos Varios
	virtual void agregar();
	virtual double obtenerPrecio() const;
	virtual std::string toString() const;
	
};

#endif // !FUENTE_H
