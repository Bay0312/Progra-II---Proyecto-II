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

#include "VentaEnLinea.h"

//Constructor y Destructor
VentaEnLinea::VentaEnLinea(Fecha* fec, Cliente* cli, Lista<Componente>* _ven, int direc)
	: Venta(fec, _ven), direccionEnvio{ direc }, cliente{ cli } {
	costoEnvio = this->determinaCostoEnvio(direc);
	precio = listaDeVendido->getPrecioTotal();
}
VentaEnLinea::~VentaEnLinea() {}

//Getters
Cliente* VentaEnLinea::getCliente() {
	return cliente;
}

double VentaEnLinea::getPrecio() {
	return precio + determinaCostoEnvio(direccionEnvio); //Buscar forma de determinar si lo que se vende es un sistema para agregarle el 35%
}

int VentaEnLinea::getDireccionEnvio() {
	return direccionEnvio;
}

double VentaEnLinea::getCostoEnvio() {
	return costoEnvio;
}

//Setters
void VentaEnLinea::setCliente(Cliente* _cliente) {
	cliente = _cliente;
}

void VentaEnLinea::setDireccionEnvio(int direc) {
	direccionEnvio = direc;
}

std::string VentaEnLinea::toString() {
	std::stringstream s;
	s << "----------VENTA EN LINEA----------\n"
		<< "Fecha de Venta: " << fechaDeVenta->toString() << '\n'
		<< "Cliente: \n"
		<< cliente->toString() << '\n'
		<< "Articulos vendidos: \n"
		<< listaDeVendido->toString() << '\n'
		<< "Direccion de envio: " << direccionEnvio << '\n'
		<< "Costo de envio: " << determinaCostoEnvio(direccionEnvio) << " dolares.\n"
		<< "Precio Final: " << precio << " dolares.";
	return s.str();
}

std::string VentaEnLinea::guardarDatos() {
	std::stringstream s;
	s << "Linea" << DELIMITA_CAMPO;
	s << fechaDeVenta->guardarDatos();
	s << cliente->getId() << DELIMITA_CAMPO;
	s << direccionEnvio << DELIMITA_CAMPO;
	s << precio << DELIMITA_CAMPO;
	s << listaDeVendido->guardarIdentificadores();
	return s.str();
}

bool VentaEnLinea::esVentaDirecta() { return false; }

std::string VentaEnLinea::mostrarPDirecciones() {
	std::stringstream s;
	s << "----------DIRECCIONES DE ENVIO----------\n"
		<< "Código\tPaís\tCiudad\tCosto Traslado"
		<< "010\tArgentina\tBuenos Aires\t$175.00\n"
		<< "020\tBrasil\tBrasilia\t$150.00\n"
		<< "030\tCanada\tOntario\t$160.00\n"
		<< "031\tEEUU\tCalifornia\t$150.00\n"
		<< "032\tEEUU\tNew York\t$100.00\n"
		<< "040\tFrancia\tParis\t$200.00\n"
		<< "050\tInglaterra\tLondres\t$200.00\n"
		<< "060\tItalia\tMilan\t$250.00\n"
		<< "090\tCosta Rica(local)\tGAM\t$50.00\n"
		<< "091\tCosta Rica(local)\tFuera de la GAM\t$80.00\n";
	return s.str();
}

double VentaEnLinea::determinaCostoEnvio(int cod) {
	switch (cod) { //Se devuelve un costo en dolares
	case 10: return 175.00; //Argentina //Buenos Aires
		break;
	case 20: return 150.00; //Brasil //Brasilia
		break;
	case 30: return 160.00; //Canada //Ontario
		break;
	case 31: return 150.00; //EEUU //California
		break;
	case 32: return 100.00; //EEUU //New York
		break;
	case 40: return 200.00; //Francia //Paris
		break;
	case 50: return 200.00; //Inglaterra //Londres
		break;
	case 60: return 250.00; //Italia //Milan
		break;
	case 90: return 50.00; //Costa Rica(local) //GAM(Gran Area Metropolitana)
		break;
	case 91: return 80.00; //Costa Rica(local) //Fuera de la GAM
		break;
	default: return 0.00;
		break;
	}
	return 0.00;
}