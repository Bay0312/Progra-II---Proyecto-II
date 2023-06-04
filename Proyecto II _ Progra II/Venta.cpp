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
Venta::Venta(){}
Venta::~Venta(){}

//Getters
Fecha* Venta::getFechaDeVenta() { return fechaDeVenta; }
Cliente* Venta::getCliente() { return cliente; }
std::string Venta::getVendido() { return vendido; }

//Setters
void Venta::setFechaDeVenta(Fecha* ptr) { fechaDeVenta = ptr; }
void Venta::setCliente(Cliente* ptr) { cliente = ptr; }
void Venta::setVendido(std::string ven) { vendido = ven; }
void Venta::setPrecio(double prec) { precio = prec; }