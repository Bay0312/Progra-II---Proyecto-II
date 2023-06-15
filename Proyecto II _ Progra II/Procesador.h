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

#ifndef PROCESADOR_H
#define PROCESADOR_H
#include "Componente.h"

class Procesador : public Componente {
private:
	std::string tipo;
	std::string modelo;
	std::string caracteristicas;

public:
	//Constructores y Destructor
	Procesador();
	Procesador(std::string, std::string, std::string, std::string, std::string, double);
	Procesador(const Procesador&);
	virtual ~Procesador();
	
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

#endif // !PROCESADOR_H
