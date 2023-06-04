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
	//Constructor y Destructor
	Catalogo();
	virtual ~Catalogo();

	//Metodos Varios
	void agregarCliente(Cliente*);
	void agregarSistema(Sistema*);
	std::string mostrarClientes();
	std::string mostrarSistemas();
	void notify();

};

#endif // !CATALOGO_H
