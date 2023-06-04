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

#include "Menu.h"

Menu::Menu() {
	//tienda = new TiendaEquipo();
}

Menu::~Menu() {
	//delete tienda;
}

void Menu::menuPrincipal() {
	int opcion = 0;

	do {
		std::cout << "----------MENU PRINCIPAL----------\n"
			<< "1. Venta Directa\n"
			<< "2. Venta en Linea\n"
			<< "3. Mantenimiento\n"
			<< "4. Salir\n"
			<< "-----------------------------------\n"
			<< "Ingrese una opcion: ";
		std::cin >> opcion;

		switch (opcion) {
		case 1:
			ventaDirecta();
			break;
		case 2:
			ventaEnLinea();
			break;
		case 3:
			mantenimiento();
			break;
		case 4:
			std::cout << "Gracias!\n";
			break;
		default:
			std::cout << "Opcion invalida. Intentelo de nuevo\n";
			break;
		}
	} while (opcion != 4);
}

void Menu::ventaDirecta(){
	int opcion = 0;

	do {
		std::cout << "----------MENU VENTA DIRECTA----------\n"
			<< "1. Comprar Componentes Individualmente\n"
			<< "2. Comprar Sistemas Completos\n"
			<< "3. Volver\n"
			<< "-----------------------------------\n"
			<< "Ingrese una opcion: ";
		std::cin >> opcion;

		switch (opcion) {
		case 1:
			compraComponente();
			break;
		case 2:
			compraSistema();
			break;
		case 3: 
			system("cls");
			break;
		default:
			std::cout << "Opcion invalida. Intentelo de nuevo\n";
			break;
		}
	} while (opcion != 3);
}
void Menu::ventaEnLinea(){ compraSistema(); }

void Menu::mantenimiento(){
	int opcion = 0;
	//También se podrá actualizar cualquier otra información disponible en el sistema.
	//Aquí debería estar tambien la inclusion de clientes.
	do {
		std::cout << "----------MENU DE MANTENIMIENTO----------\n"
			<< "1. Ingresar Componentes al Catalogo\n"
			<< "2. Ingresar Sistemas al Catalogo.\n"
			<< "3. Eliminar un Item del Catalogo\n"
			<< "4. Volver\n"
			<< "-----------------------------------\n"
			<< "Ingrese una opcion: ";
		std::cin >> opcion;

		switch (opcion) {
		case 1:
			//IngresarComponente();
			break;
		case 2:
			//IngresarSistema();
			break;
		case 3:
			//EliminarItem();
			break;
		case 4:
			system("cls");
			break;
		default:
			std::cout << "Opcion invalida. Intentelo de nuevo\n";
			break;
		}
	} while (opcion != 4);
}

void Menu::compraSistema(){
	//COMPLETAR //TOMAR EN CUENTA LA COMPRA EN LINEA, DONDE SOLO SE PUEDEN COMPRAR SISTEMAS PREARMADOS.
}
void Menu::compraComponente(){
	//COMPLETAR
}
void Menu::guardarDatos(){
	std::ofstream file; //ofstream abre el archivo para escritura

	file.open("guardadoArchivo.txt", std::ios::out); //Se abre el archivo y se usa la flag ios::out para sobreescribir.
	if (!file.is_open()) { //Si el archivo no está abierto (is_open() == false).
		std::cout << "Error al abrir el archivo...\n";
		system("PAUSE");
	}
	else {
		//file << tienda->guardarDatos();
	}
	file.close(); //Se cierra el archivo
}
void Menu::cargarDatos(){
	std::ifstream file; //ifstream permite abrir el archivo para lectura
	std::string buffer;
	std::string guardar[20];
	int cant = 0;
	system("CLS");

	
	file.open("Random.txt", std::ios::in); //Abre el archivo para lectura
	if (!file.is_open()) { //Si el archivo no está abierto (is_open() == false).
		std::cout << "Bienvenido, veo que es la primera vez que ingresa al programa, por lo que no hay datos guardados aun. Diviertase!\n";
		system("pause");
		system("cls");
	}
	else {
		size_t posicion = 0; //Se utiliza un size_t para guardar la posición del punto y coma.
		while (std::getline(file, buffer)) { //Se guarda en "buffer" la linea correspondiente hasta encontrar un salto de linea.
			while ((posicion = buffer.find('\t')) != std::string::npos) {
				guardar[cant++] = buffer.substr(0, posicion); //Se guarda en el arreglo "guardar" la cadena de caracteres hasta el punto y coma.
				buffer.erase(0, posicion + 1); //Se borra la cadena de caracteres hasta el punto y coma.
			}
			//tienda->cargarDatos(guardar, cant);
			cant = 0;
		}
	}
	file.close(); //Se cierra el archivo.
}

void Menu::buscaExcepcion(){
	//HACE FALTA
}
