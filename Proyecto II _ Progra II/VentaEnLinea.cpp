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
VentaEnLinea::VentaEnLinea(Fecha* fec, Cliente* cli, std::string ven, double prec, int direc, double costEnv) {
	fechaDeVenta = fec;
	cliente = cli;
	vendido = ven;
	precio = prec;
	direccionEnvio = direc;
	costoEnvio = costEnv;
}
VentaEnLinea::~VentaEnLinea() {}

//Getters
double VentaEnLinea::getPrecio() {
	return precio + determinaCostoEnvio(direccionEnvio); //Buscar forma de determinar si lo que se vende es un sistema para agregarle el 35%
}

int VentaEnLinea::getDireccionEnvio() {
	return direccionEnvio;
}

//Setters
void VentaEnLinea::setDireccionEnvio(int direc) {
	direccionEnvio = direc;
}

std::string VentaEnLinea::toString() {
	std::stringstream s;
	s << "----------VENTA EN LINEA----------\n"
		<< "Fecha de Venta: " << fechaDeVenta->toString()
		<< "Cliente: \n"
		<< cliente->toString() << '\n'
		<< "Articulos vendidos: \n"
		<< "Direccion de envio: " << direccionEnvio << '\n'
		<< "Costo de envio: " << determinaCostoEnvio(direccionEnvio) << " colones.\n"
		<< "Precio Final: " << precio << " colones.";
	return s.str();
}

bool VentaEnLinea::esVentaDirecta() { return false; }

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