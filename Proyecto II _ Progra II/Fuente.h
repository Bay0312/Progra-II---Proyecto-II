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
	std::string tipo; //Componente
	std::string modelo;
	std::string caracteristicas;

public:
	//Constructores y Destructor
	Fuente();
	Fuente(std::string, std::string, std::string, std::string, std::string, double);
	Fuente(const Fuente&);
	virtual ~Fuente();

	//Getters
	virtual std::string getTipo() const;
	virtual std::string getModelo() const;
	virtual std::string getCaracteristicas() const;

	//Setters
	virtual void setTipo(std::string);
	virtual void setModelo(std::string);
	virtual void setCaracteristicas(std::string);

	//Metodos Varios
	virtual void agregar(Componente* = nullptr);
	virtual double obtenerPrecio() const;
	virtual std::string toString() const;
	virtual std::string guardarDatos();
	virtual bool esSistema() const;
	
};

#endif // !FUENTE_H
