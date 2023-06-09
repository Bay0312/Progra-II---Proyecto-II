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

#ifndef COMPONENTE_H
#define COMPONENTE_H
#include <sstream>

class Componente { //<<Abs>>
protected:
	std::string codigo; //Modelo del componente o codigo del sistema
	double precio;

public:
	Componente() : codigo{ "" }, precio{ 0.0 } {}
	virtual ~Componente(){}
	virtual std::string getCodigo() const { return codigo; }
	virtual void setCodigo(std::string _codigo) { codigo = _codigo; }
	virtual void setPrecio(double _precio) { precio = _precio; }
	virtual double getPrecio() const { return precio; }
	virtual void agregar(Componente*) = 0;
	virtual double obtenerPrecio() const = 0;
	virtual std::string toString() const = 0;
	virtual bool esSistema() const = 0;
	
};


#endif // !COMPONENTE_H
