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
private:
	std::string facturaNombre; //El nombre de la persona al que debe estar la factura

public:
	//Constructor y Destructor
	VentaDirecta(Fecha*, Lista<Componente>*, std::string);
	virtual ~VentaDirecta();

	//Getter
	std::string getFacturaNombre();
	virtual double getPrecio();

	//Setter
	void setFacturaNombre(std::string);
	
	//Metodos Varios
	virtual std::string toString();
	virtual std::string guardarDatos();
	virtual bool esVentaDirecta();

};


#endif // !VENTADIRECTA_H
