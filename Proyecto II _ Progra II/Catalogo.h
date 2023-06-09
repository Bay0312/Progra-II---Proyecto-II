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

class Cliente; //Declaracion previa

class Catalogo {
private:
	Lista<Cliente>* listClients; //Observers //Clientes subscritos al catalogo
	Lista<Componente>* listProductos; //Pueden entrar componentes o sistemas

public:
	//Constructor y Destructor
	Catalogo();
	virtual ~Catalogo();

	//Getters
	Lista<Cliente>* getListClients();
	Lista<Componente>* getListProductos();

	//Metodos Varios
	void agregarCliente(Cliente*);
	void agregarProducto(Componente*);
	std::string mostrarClientes();
	std::string mostrarSoloSistemas();
	std::string mostrarSoloComponentes();
	std::string mostrarFuentes();
	std::string mostrarProcesadores();
	std::string mostrarParlantes();
	std::string mostrarTodo();
	void notify();

};

#endif // !CATALOGO_H
