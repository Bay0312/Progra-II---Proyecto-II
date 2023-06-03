#include "Venta.h"

Venta::Venta(){}
Venta::~Venta(){}
Fecha* Venta::getFechaDeVenta() { return fechaDeVenta; }
void Venta::setFechaDeVenta(Fecha* ptr) { fechaDeVenta = ptr; }
std::string Venta::getVendido() { return vendido; }
void Venta::setVendido(std::string ven) { vendido = ven; }
void Venta::setPrecio(double prec) { precio = prec; }