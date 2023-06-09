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
	std::string categoria;
	std::string tipo;
	std::string caracteristicas;

public:
	//Constructores y Destructor
	Procesador();
	Procesador(std::string, std::string, std::string, std::string, double);
	Procesador(const Procesador&);
	virtual ~Procesador();
	
	//Getters
	std::string getCategoria() const;
	std::string getTipo() const;
	std::string getCaracteristicas() const;

	//Setters
	void setCategoria(std::string);
	void setTipo(std::string);
	void setCaracteristicas(std::string);

	//Metodos Varios
	virtual void agregar(Componente* = nullptr);
	virtual double obtenerPrecio() const;
	virtual std::string toString() const;
	virtual bool esSistema() const;
	
	

};

#endif // !PROCESADOR_H
