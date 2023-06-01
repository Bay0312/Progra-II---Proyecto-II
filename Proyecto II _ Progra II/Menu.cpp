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
		default:
			std::cout << "Opcion invalida. Intentelo de nuevo\n";
			break;
		}
	} while (opcion != 3);
}
void Menu::ventaEnLinea(){ compraSistema(); }
void Menu::mantenimiento(){
	//COMPLETAR
}
void Menu::compraSistema(){
	//COMPLETAR
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
