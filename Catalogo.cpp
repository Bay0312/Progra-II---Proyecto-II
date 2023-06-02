#include "Catalogo.h"
// Actualizado

Catalogo::Catalogo() {
	listClients = new Lista<Cliente>();
	listSistemas = new Lista<SistemaPreConfigurado>();
}

Catalogo::~Catalogo() {
	delete listClients;
	delete listSistemas;
}

void Catalogo::agregarCliente(Cliente* c) {
	listClients->insertarFinal(c);
}

void Catalogo::agregarSistema(SistemaPreConfigurado* s) {
	listSistemas->insertarFinal(s);
	notify();
}

void Catalogo::notify() {
	listClients->notificarObservers();
}
