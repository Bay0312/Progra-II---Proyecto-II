#ifndef VENTAENLINEA_H
#define VENTAENLINEA_H
#include "Venta.h"

class VentaEnLinea : public Venta {
private:
	int direccionEnvio; //Aqui va el codigo del lugar al que se envia
	double costoEnvio; //Puede que no hafa falta

public:
	VentaEnLinea(Fecha*, Cliente*, std::string, char, double, int, double);
	virtual ~VentaEnLinea();
	virtual double getPrecio();
	virtual std::string toString();
	double determinaCostoEnvio(int);

};

#endif // !VENTAENLINEA_H
