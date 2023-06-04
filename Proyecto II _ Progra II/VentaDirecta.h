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

#ifndef VENTADIRECTA_H
#define VENTADIRECTA_H
#include "Venta.h"

class VentaDirecta: public Venta {
public:
	//Constructor y Destructor
	VentaDirecta(Fecha*, Cliente*, std::string, double);
	virtual ~VentaDirecta();

	//Getter
	virtual double getPrecio();

	//Metodos Varios
	virtual std::string toString();
	virtual bool esVentaDirecta();

};


#endif // !VENTADIRECTA_H
