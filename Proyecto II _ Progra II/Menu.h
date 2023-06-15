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

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <sstream>
#include <fstream>
#include "Tienda.h"
#include "Persona.h"
#include "Empresa.h"
#include "VentaDirecta.h"
#include "VentaEnLinea.h"
#include "Fuente.h"
#include "Procesador.h"
#include "Parlante.h"
#include "Excepciones.h"

class Menu {
private:
	Tienda* tienda;
	Lista<Componente>* carrito; //Lista de componentes que se van a comprar

public:
	Menu();
	virtual ~Menu();
	//Metodos Principales
	void menuPrincipal();
	void ventaDirecta();
	void ventaEnLinea();
	void mantenimiento();

	//Metodos de Ayuda
	void compraSistema();
	void personalizarSistema(bool);
	void compraComponente();
	void confirmaCarrito(std::string); 
	void registroCliente(int);
	void actualizarItem(); 

	//Agregacion y Eliminacion de Componentes y Sistemas
	void ingresarComponente();
	void eliminarItem();

	//Metodos de Archivos
	void guardarDatos();
	void cargarDatos();

	//Metodos de Excepciones
	void existenciaExcepcion(std::string, bool = true);



};
#endif // !MENU_H
