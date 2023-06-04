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
//#include "TiendaEquipo.h"

class Menu {
private:
	//TiendaEquipo* tienda;

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
	void compraComponente();

	//Metodos de Archivos
	void guardarDatos();
	void cargarDatos();

	//Metodos de Excepciones
	void buscaExcepcion();



};
#endif // !MENU_H
