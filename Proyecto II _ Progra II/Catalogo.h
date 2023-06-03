#ifndef CATALOGO_H
#define CATALOGO_H
#include "Cliente.h"
#include "Sistema.h"
// Actualizado

class Catalogo {
private:
	Lista<Cliente>* listClients;
	Lista<Sistema>* listSistemas;
public:
	Catalogo();
	virtual ~Catalogo();
	void agregarCliente(Cliente*);
	void agregarSistema(Sistema*);
	void notify();
	std::string mostrarClientes();
	std::string mostrarSistemas();
};

#endif // !CATALOGO_H
