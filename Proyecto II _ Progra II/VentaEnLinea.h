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
	Cliente* cliente; //Persona a la que se le vendió.
	int direccionEnvio; //Aqui va el codigo del lugar al que se envia
	double costoEnvio; //Puede que no hafa falta

public:
	//Constructor y Destructor
	VentaEnLinea(Fecha*, Cliente*, Lista<Componente>*, int);
	virtual ~VentaEnLinea();

	//Getters
	Cliente* getCliente();
	int getDireccionEnvio();
	virtual double getPrecio();
	double getCostoEnvio();

	//Setters
	void setCliente(Cliente*);
	void setDireccionEnvio(int); //Con este setters es posible settear también al costoEnvio.

	//Metodos Varios
	virtual std::string toString();
	virtual bool esVentaDirecta();
	double determinaCostoEnvio(int);

};

#endif // !VENTAENLINEA_H
