#ifndef VENTADIRECTA_H
#define VENTADIRECTA_H
#include "Venta.h"

class VentaDirecta: public Venta {
public:
	VentaDirecta(Fecha*, Cliente*, std::string, char, double);
	virtual ~VentaDirecta();
	virtual double getPrecio();
	virtual std::string toString();

};


#endif // !VENTADIRECTA_H
