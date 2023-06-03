#include "Catalogo.h"
// Actualizado

Catalogo::Catalogo() {
	listClients = new Lista<Cliente>();
	listSistemas = new Lista<Sistema>();
}

Catalogo::~Catalogo() {
	delete listClients;
	delete listSistemas;
}

void Catalogo::agregarCliente(Cliente* c) {
	listClients->insertarFinal(c);
}

void Catalogo::agregarSistema(Sistema* s) {
	listSistemas->insertarFinal(s);
	notify();
}

void Catalogo::notify() {
	listClients->notificarObservers();
}

std::string Catalogo::mostrarClientes() {
	return listClients->toString();
}

std::string Catalogo::mostrarSistemas() {
	return listSistemas->toString();
}