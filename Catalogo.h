#pragma once
#include "Cliente.h"
#include "SistemaPreConfigurado.h"
// Actualizado

class Catalogo {
private:
	Lista<Cliente>* listClients;
	Lista<SistemaPreConfigurado>* listSistemas;
public:
	Catalogo();
	virtual ~Catalogo();
	void agregarCliente(Cliente*);
	void agregarSistema(SistemaPreConfigurado*);
	void notify();
	string mostrarClientes();
	string mostrarSistemas();
};

