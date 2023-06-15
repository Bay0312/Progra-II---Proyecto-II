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
	return VentaEnLinea::mostrarPDirecciones();
}

double Tienda::determinaCostoEnvio(int cod) {
	return VentaEnLinea::determinaCostoEnvio(cod);
}

std::string Tienda::reporteVentas() {
	std::stringstream s;
	s << "------------------REPORTE DE VENTAS------------------\n";
	listaVentas->toString();

	return s.str();
}

std::string Tienda::reporteMasVendido() {
	std::stringstream s;
	s << "------------------REPORTE DE MAS VENDIDO------------------\n";
	//Venta* masVendido = listaVentas->getMasRepetido();
	return s.str();
}

std::string Tienda::guardarDatos(){
	std::stringstream s;
	s << catalogo->guardarDatos() << DELIMITA_REGISTRO;
	s << listaVentas->guardarDatos() << DELIMITA_REGISTRO;
	return s.str();
}
