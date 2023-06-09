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

#include "Venta.h"

//Constructor y Destructor
Venta::Venta(Fecha* _fecha, Lista<Componente>* _vendido)
	: fechaDeVenta{ _fecha }, listaDeVendido{ _vendido } {
	precio = listaDeVendido->getPrecioTotal();
}
Venta::~Venta(){}

//Getters
Fecha* Venta::getFechaDeVenta() { return fechaDeVenta; }
Lista<Componente>* Venta::getVendido() { return listaDeVendido; }

//Setters
void Venta::setFechaDeVenta(Fecha* ptr) { fechaDeVenta = ptr; }
void Venta::setPrecio(double prec) { precio = prec; }