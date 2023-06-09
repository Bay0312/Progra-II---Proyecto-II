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

VentaDirecta::VentaDirecta(Fecha* fec, Lista<Componente>* _ven, std::string _factNom) : Venta(fec, _ven), facturaNombre{ _factNom } {
}
VentaDirecta::~VentaDirecta() {}

//Getters
std::string VentaDirecta::getFacturaNombre() { return facturaNombre; }
double VentaDirecta::getPrecio() { return precio; }

//Setters
void VentaDirecta::setFacturaNombre(std::string _factNom) { facturaNombre = _factNom; }

//Metodos Varios
std::string VentaDirecta::toString() {
	std::stringstream s;
	s << "----------VENTA DIRECTA----------\n"
		<< "Fecha de Venta: " << fechaDeVenta->toString()
		<< "Cliente: \n"
		<< facturaNombre << '\n'
		<< "Articulos vendidos: \n" << listaDeVendido->toString() << '\n'
		<< "Precio Final: " << precio << " colones.";
	return s.str();
}

bool VentaDirecta::esVentaDirecta() { return true; }