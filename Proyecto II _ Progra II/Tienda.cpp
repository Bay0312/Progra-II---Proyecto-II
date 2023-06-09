#include "Tienda.h"

Tienda::Tienda(Catalogo* cat) {
	catalogo = cat;
	listaVentas = new Lista<Venta>();
}

Tienda::~Tienda() {
	delete catalogo;
	delete listaVentas;
}

Catalogo* Tienda::getCatalogo() {
	return catalogo;
}

Lista<Venta>* Tienda::getListaVentas() {
	return listaVentas;
}

void Tienda::agregarClienteCat(Cliente* _cliente) { //Para suscribir los clientes al catalogo
	catalogo->agregarCliente(_cliente);
}

void Tienda::agregarProductosCat(Componente* producto) {
	catalogo->agregarProducto(producto);
}

std::string Tienda::mostrarClientesCat() {
	return catalogo->mostrarClientes();
}

std::string Tienda::mostrarProductosCat() {
	return catalogo->mostrarTodo();
}

void Tienda::agregarVenta(Venta* venta) {
	listaVentas->insertarFinal(venta);
}

std::string Tienda::mostrarVentas() {
	return listaVentas->toString();
}

std::string Tienda::mostrarPDirecciones() {
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

double Tienda::determinaCostoEnvio(int cod) {
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
