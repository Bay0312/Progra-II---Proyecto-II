#include "VentaDirecta.h"

VentaDirecta::VentaDirecta(Fecha* fec, Cliente* cli, std::string ven, char tip, double prec) {
	fechaDeVenta = fec;
	cliente = cli;
	vendido = ven;
	tipo = tip;
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
		<< "Articulos vendidos: \n"
		<< "Precio Final: " << precio << " colones.";
	return s.str();
}