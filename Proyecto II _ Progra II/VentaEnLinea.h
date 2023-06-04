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

#ifndef VENTAENLINEA_H
#define VENTAENLINEA_H
#include "Venta.h"

class VentaEnLinea : public Venta {
private:
	int direccionEnvio; //Aqui va el codigo del lugar al que se envia
	double costoEnvio; //Puede que no hafa falta

public:
	//Constructor y Destructor
	VentaEnLinea(Fecha*, Cliente*, std::string, double, int, double);
	virtual ~VentaEnLinea();

	//Getters
	int getDireccionEnvio();
	virtual double getPrecio();

	//Setters
	void setDireccionEnvio(int);

	//Metodos Varios
	virtual std::string toString();
	virtual bool esVentaDirecta();
	double determinaCostoEnvio(int);

};

#endif // !VENTAENLINEA_H
