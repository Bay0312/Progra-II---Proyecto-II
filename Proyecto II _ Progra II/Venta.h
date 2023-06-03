#ifndef VENTA_H
#define VENTA_H
#include "Fecha.h"
#include "Cliente.h"

class Venta {
protected:
	Fecha* fechaDeVenta;
	Cliente* cliente; //Cliente que compró
	std::string vendido; //Listado de lo que se vendió
	char tipo; //Tipo de venta (directa o en linea)
	double precio;

public:
	Venta();
	virtual ~Venta();
	Fecha* getFechaDeVenta();
	void setFechaDeVenta(Fecha*);
	std::string getVendido();
	void setVendido(std::string);
	virtual double getPrecio() = 0;
	void setPrecio(double);
	virtual std::string toString() = 0;


};

#endif // !VENTA_H
