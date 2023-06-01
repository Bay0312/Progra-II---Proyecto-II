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
	void menuPrincipal();
	void ventaDirecta();
	void ventaEnLinea();
	void mantenimiento();
	void compraSistema();
	void compraComponente();
	void guardarDatos();
	void cargarDatos();
	void buscaExcepcion();



};
#endif // !MENU_H
