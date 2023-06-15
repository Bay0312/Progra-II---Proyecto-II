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
	Lista<Componente>* listaDeVendido; //Lista de productos que se vendieron
	double precio;

public:
	//Constructor y Destructor
	Venta(Fecha*, Lista<Componente>*);
	virtual ~Venta();

	//Getters
	Fecha* getFechaDeVenta();
	Lista<Componente>* getVendido();
	virtual double getPrecio() = 0;

	//Setters
	void setFechaDeVenta(Fecha*);
	void setPrecio(double);

	//Metodos Varios
	virtual std::string toString() = 0;
	virtual std::string guardarDatos() = 0;
	virtual bool esVentaDirecta() = 0;


};

#endif // !VENTA_H
