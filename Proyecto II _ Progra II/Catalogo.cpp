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
	listSistemas = new Lista<Sistema>();
}

Catalogo::~Catalogo() {
	delete listClients;
	delete listSistemas;
}

//Metodos Varios
void Catalogo::agregarCliente(Cliente* c) {
	listClients->insertarFinal(c);
}

void Catalogo::agregarSistema(Sistema* s) {
	listSistemas->insertarFinal(s);
	notify(); //Al insertar un sistema, se notifica a los clientes.
}

std::string Catalogo::mostrarClientes() {
	return listClients->toString();
}

std::string Catalogo::mostrarSistemas() {
	return listSistemas->toString();
}

void Catalogo::notify() { //Notifica a los clientes que hubo cambios en el catalogo.
	listClients->notificarObservers();
}