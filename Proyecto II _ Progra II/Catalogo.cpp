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

#include "Catalogo.h"
// Actualizado

//Constructor y Destructor
Catalogo::Catalogo() {
	listClients = new Lista<Cliente>();
	listProductos = new Lista<Componente>();
}

Catalogo::~Catalogo() {
	delete listClients;
	delete listProductos;
}

//Getters
Lista<Cliente>* Catalogo::getListClients() {
	return listClients;
}

Lista<Componente>* Catalogo::getListProductos() {
	return listProductos;
}

//Metodos Varios
void Catalogo::agregarCliente(Cliente* c) {
	listClients->insertarFinal(c);
}

void Catalogo::agregarProducto(Componente* s) {
	listProductos->insertarFinal(s);
	notify(); //Al insertar un producto, se notifica a los clientes.
}

std::string Catalogo::mostrarClientes() {
	return listClients->toString();
}

std::string Catalogo::mostrarSoloSistemas() {
	IteradorLista<Componente>* iterador = listProductos->getIterador();
	std::stringstream s;
	bool hayProducto = false;
	s << "----------------------------------SISTEMAS----------------------------------\n";

	while (iterador->getActual() != nullptr) {
		if (iterador->getActual()->getInfo()->esSistema()) {
			s << iterador->getActual()->getInfo()->toString() << std::endl;
			if (!hayProducto) hayProducto = true;
		}
		iterador->operator++();
	}
	if (!hayProducto) return "No hay ningun sistema en el catálogo.";
	return s.str();
}

std::string Catalogo::mostrarSoloComponentes() {
	IteradorLista<Componente>* iterador = listProductos->getIterador();
	std::stringstream s;
	bool hayProducto = false;
	s << "----------------------------------COMPONENTES----------------------------------\n";
	s << "CATEGORIA\t\tTIPO\t\tCODIGO\t\tPRECIO($)\t\tCARACT.\n";
	s << "-------------------------------------------------------------------------------\n";

	while (iterador->getActual() != nullptr) {
		if (!iterador->getActual()->getInfo()->esSistema()) { //Si no es sistema, es componente.
			s << iterador->getActual()->getInfo()->toString() << '\n';
			if (!hayProducto) hayProducto = true;
		}
		iterador->operator++();
	}
	if (!hayProducto) return "No hay ningún componente en el catálogo.";
	return s.str();
}

std::string Catalogo::mostrarFuentes(){
	IteradorLista<Componente>* iterador = listProductos->getIterador();
	std::stringstream s;
	bool hayProducto = false;
	s << "------------------------------------FUENTES------------------------------------\n";
	s << "CATEGORIA\t\tTIPO\t\tCODIGO\t\tPRECIO($)\t\tCARACT.\n";
	s << "-------------------------------------------------------------------------------\n";

	while (iterador->getActual() != nullptr) {
		if (dynamic_cast<Fuente*>(iterador->getActual()->getInfo()) != nullptr) { 
			s << iterador->getActual()->getInfo()->toString() << '\n';
			if (!hayProducto) hayProducto = true;
		}
		iterador->operator++();
	}
	if (!hayProducto) return "No hay Fuentes de Audio en el catálogo.";
	return s.str();
}

std::string Catalogo::mostrarProcesadores(){
	IteradorLista<Componente>* iterador = listProductos->getIterador();
	std::stringstream s;
	bool hayProducto = false;
	s << "---------------------------------PROCESADORES----------------------------------\n";
	s << "CATEGORIA\t\tTIPO\t\tCODIGO\t\tPRECIO($)\t\tCARACT.\n";
	s << "-------------------------------------------------------------------------------\n";
	
	while (iterador->getActual() != nullptr) { 
		if (dynamic_cast<Procesador*>(iterador->getActual()->getInfo()) != nullptr) { 
			s << iterador->getActual()->getInfo()->toString() << '\n';
			if (!hayProducto) hayProducto = true;
		}
		iterador->operator++();
	}
	if (!hayProducto) return "No hay Procesadores de Señal en el catálogo.";
	return s.str();
}
std::string Catalogo::mostrarParlantes(){
	IteradorLista<Componente>* iterador = listProductos->getIterador();
	std::stringstream s;
	bool hayProducto = false;
	s << "-----------------------------------PARLANTES-----------------------------------\n";
	s << "CATEGORIA\t\tTIPO\t\tCODIGO\t\tPRECIO($)\t\tCARACT.\n";
	s << "-------------------------------------------------------------------------------\n";

	while (iterador->getActual() != nullptr) { 
		if (dynamic_cast<Parlante*>(iterador->getActual()->getInfo()) != nullptr) {
			s << iterador->getActual()->getInfo()->toString() << '\n';
			if (!hayProducto) hayProducto = true;
		}
		iterador->operator++();
	}
	if (!hayProducto) return "No hay parlantes en el catálogo.";
	return s.str();
}

std::string Catalogo::mostrarTodo() {
	return listProductos->toString();
}

std::string Catalogo::guardarDatos() {
	std::stringstream s;
	s << listClients->guardarDatos();
	s << listProductos->guardarDatos();
	return s.str();
}

void Catalogo::notify() { //Notifica a los clientes que hubo cambios en el catalogo.
	listClients->notificarObservers();
}