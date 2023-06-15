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

	while (iterador->getActual() != nullptr) {
		if (iterador->getActual()->getInfo()->esSistema()) {
			s << iterador->getActual()->getInfo()->toString() << std::endl;
		}
		iterador->operator++();
	}
	return s.str();
}

std::string Catalogo::mostrarSoloComponentes() {
	IteradorLista<Componente>* iterador = listProductos->getIterador();
	std::stringstream s;

	while (iterador->getActual() != nullptr) {
		if (!iterador->getActual()->getInfo()->esSistema()) { //Si no es sistema, es componente.
			s << iterador->getActual()->getInfo()->toString() << '\n';
		}
		iterador->operator++();
	}
	return s.str();
}

std::string Catalogo::mostrarFuentes(){
	std::stringstream s;
	IteradorLista<Componente>* iterador = listProductos->getIterador();
	Fuente* compPtr = nullptr;

	while (iterador->getActual() != nullptr) {
		//compPtr = dynamic_cast<Fuente*>(iterador->getActual()->getInfo());
		if (dynamic_cast<Fuente*>(iterador->getActual()->getInfo()) != nullptr) { 
			s << iterador->getActual()->getInfo()->toString() << '\n';
		}
		iterador->operator++();
	}
	return s.str();
}

std::string Catalogo::mostrarProcesadores(){
	std::stringstream s;
	IteradorLista<Componente>* iterador = listProductos->getIterador();

	while (iterador->getActual() != nullptr) { 
		if (dynamic_cast<Procesador*>(iterador->getActual()->getInfo()) != nullptr) { 
			s << iterador->getActual()->getInfo()->toString() << '\n';
		}
		iterador->operator++();
	}
	return s.str();
}
std::string Catalogo::mostrarParlantes(){
	std::stringstream s;
	IteradorLista<Componente>* iterador = listProductos->getIterador(); 

	while (iterador->getActual() != nullptr) { 
		if (dynamic_cast<Parlante*>(iterador->getActual()->getInfo()) != nullptr) {
			s << iterador->getActual()->getInfo()->toString() << '\n';
		}
		iterador->operator++();
	}
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