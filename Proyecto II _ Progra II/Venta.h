#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"
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

#include "Cliente.h"

class Venta {
protected:
	Fecha* fechaDeVenta;
	Cliente* cliente; //Cliente que compró
	std::string vendido; //Listado de lo que se vendió
	double precio;

public:
	//Constructor y Destructor
	Venta();
	virtual ~Venta();

	//Getters
	Fecha* getFechaDeVenta();
	Cliente* getCliente();
	std::string getVendido();
	virtual double getPrecio() = 0;

	//Setters
	void setFechaDeVenta(Fecha*);
	void setCliente(Cliente*);
	void setVendido(std::string);
	void setPrecio(double);

	//Metodos Varios
	virtual std::string toString() = 0;
	virtual bool esVentaDirecta() = 0;


};

#endif // !VENTA_H
