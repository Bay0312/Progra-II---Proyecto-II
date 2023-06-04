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

#include "VentaDirecta.h"

VentaDirecta::VentaDirecta(Fecha* fec, Cliente* cli, std::string ven, double prec) {
	fechaDeVenta = fec;
	cliente = cli;
	vendido = ven;
	precio = prec;
}

VentaDirecta::~VentaDirecta() {}

double VentaDirecta::getPrecio() { return precio; }

std::string VentaDirecta::toString() {
	std::stringstream s;
	s << "----------VENTA DIRECTA----------\n"
		<< "Fecha de Venta: " << fechaDeVenta->toString()
		<< "Cliente: \n"
		<< cliente->toString() << '\n'
		<< "Articulos vendidos: \n" << vendido << '\n'
		<< "Precio Final: " << precio << " colones.";
	return s.str();
}

bool VentaDirecta::esVentaDirecta() { return true; }