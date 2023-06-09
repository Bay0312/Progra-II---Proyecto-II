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
	tienda = new Tienda(new Catalogo());
	carrito = nullptr;
}

Menu::~Menu() {
	delete tienda;
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
			system("CLS");
			break;
		default:
			std::cout << "Opcion invalida. Intentelo de nuevo\n";
			break;
		}
	} while (opcion != 4);
	std::cout << "Gracias!\n";
}

void Menu::ventaDirecta(){
	int opcion = 0;

	do {
		system("CLS");
		std::cout << "----------MENU VENTA DIRECTA----------\n"
			<< "1. Agregar Componentes Individuales al Carrito\n"
			<< "2. Agregar Sistemas de Sonido Pre-Configurados al Carrito \n"
			<< "3. Agregar Sistemas de Sonido Personalizados al Carrito\n"
			<< "4. Ver Carrito de Compras.\n"
			<< "5 Volver\n"
			<< "--------------------------------------\n"
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
			personalizarSistema(false);
			break;
		case 4:
			confirmaCarrito("null");
			break;
		case 5:
			system("CLS");
			break;
		default:
			std::cout << "Opcion invalida. Intentelo de nuevo\n";
			break;
		}
	} while (opcion != 5);
}

void Menu::ventaEnLinea(){ 
	int opcion = 0, aux;
	std::string cod;
	bool sigue = false;

	do {
		system("CLS");
		std::cout << "----------MENU DE VENTA EN LINEA----------\n"
			<< "1. Registrarse.\n"
			<< "2. Comprar Sistema.\n"
			<< "3. Ver Carrito de Compras.\n"
			<< "4. Volver\n"
			<< "------------------------------------------\n"
			<< "Ingrese una opcion: ";
		std::cin >> opcion;

		switch (opcion) {
		case 1:
			system("CLS");
			std::cout << "¿Que tipo de cliente va a registrar?\n"
				<< "1. Cliente Fisico (Persona)\n"
				<< "2. Cliente Juridico (Empresa)\n"
				<< "-----------------------------------\n"
				<< "Ingrese una opcion: ";
			std::cin >> aux;
			if ((aux != 1 && aux != 2)) {
				std::cout << "Opcion invalida. Intentelo de nuevo\n";
			}
			else {
				registroCliente(aux);
			}
			break;

		case 2:
			system("CLS");
			do {
				system("CLS");
				std::cout << "Cliente, ingrese el número de cedula: ";
				std::cin >> cod;
				if (tienda->getCatalogo()->getListClients()->existeCliente(cod)) {
					std::cout << "\nCliente encontrado!\n";
					Sleep(2000);
					sigue = true;
				}
				else {
					std::cout << "El cliente no existe. Intentelo de nuevo.\n";
					system("PAUSE");
				}
			} while (!sigue);
			compraSistema();
			sigue = true;
			break;

		case 3:
			confirmaCarrito(cod);
			break;

		case 4:
			system("cls");
			if (carrito != nullptr) {
				std::cout << "Nota: Si no se confirma el carrito, se perdera la informacion. ¿Desea Continuar? (1. Si || 0. No): \n";
				std::cin >> sigue;
				if (sigue) delete carrito; //Si es nullptr
			}
			else { //Si el carrito es null es porque la compra se concretó.
				system("CLS");
			}
		default:
			std::cout << "Opcion invalida. Intentelo de nuevo\n";
			break;
		}
	} while (sigue);
}

void Menu::mantenimiento(){
	int opcion = 0;
	//También se podrá actualizar cualquier otra información disponible en el sistema.
	//Aquí debería estar tambien la inclusion de clientes.
	do {
		system("CLS");
		std::cout << "----------MENU DE MANTENIMIENTO----------\n"
			<< "1. Suscribir un Cliente al Catalogo\n"
			<< "2. Actualizar Informacion de un Item\n"
			<< "3. Ingresar Componentes al Catalogo\n"
			<< "4. Ingresar Sistemas al Catalogo.\n"
			<< "5. Eliminar un Item del Catalogo\n"
			<< "6. Volver\n"
			<< "-----------------------------------\n"
			<< "Ingrese una opcion: ";
		std::cin >> opcion;

		switch (opcion) {
		case 1:
			//nana
			break;
		case 2:
			//actualizarItem();
			break;
		case 3:
			ingresarComponente();
			break;
		case 4:
			personalizarSistema(true);
			break;
		case 5:
			eliminarItem();
			break;
		case 6:
			system("CLS");
			break;
		default:
			std::cout << "Opcion invalida. Intentelo de nuevo\n";
			break;
		}
	} while (opcion != 6);
}

void Menu::compraSistema() {
	std::string cod;
	bool sigue = true;
	carrito = new Lista<Componente>; //Actua como carrito de compras


	do {
		system("CLS");
		std::cout << tienda->getCatalogo()->mostrarSoloSistemas();
		std::cout << "Ingrese el codigo del sistema que desea comprar: ";
		std::cin >> cod;

		if (tienda->getCatalogo()->getListProductos()->existeElemento(cod)) {
			Componente* compPtr = tienda->getCatalogo()->getListProductos()->obtenerElemento(cod);
			// Se confirma que sea un sistema, para evitar agregaciones de otros componentes en pantallas donde no corresponde.
			if (compPtr->esSistema()) {
				int can;
				std::cout << "¿Cuantas unidades desea?: ";
				std::cin >> can;
				//Se clona el sistema, así, si se llega a eliminar del catalogo, este no se elimina de los datos de la venta.
				//Haciendo que se repita la clonacion, logramos qué en el carrito se agreguen sistemas diferentes, aunque sean el mismo, así es posible evitar confusiones en caso de revertir una compra.
				for (int i = 0; i < can; i++) carrito->insertarFinal(new Sistema(*dynamic_cast<Sistema*>(compPtr))); //Se agrega el componente al carrito
				std::cout << "Se ha agregado al carrito de compras correctamente!\n\n";
				std::cout << "Desea agregar otro sistema preconfigurado al carrito? (1. Si || 0. No): ";
				std::cin >> sigue;
			}
			else {
				std::cout << "El código ingresado no corresponde a un sistema preconfigurado.\n¿Desea probar con otro? (1. Si || 0. No): ";
				std::cin >> sigue;
			}
		}
		else {
			std::cout << "El código ingresado no existe.\n¿Desea probar con otro? (1. Si || 0. No): ";
			std::cin >> sigue;
		}
	} while (sigue);
	if (carrito->getActual() == nullptr) delete carrito;
}

void Menu::personalizarSistema(bool donde) { //El bool 'donde' indica si se llama desde el menu de compra o desde el menu de mantenimiento.
	std::string cod;
	int cambia = 1;
	bool comp = true, rep = true;
	Sistema* personalizado = new Sistema();

	do {
		switch (cambia) {
		case 1:
			do {
				system("CLS");
				std::cout << "----------PERSONALIZANDO SISTEMA----------\n";
				std::cout << tienda->getCatalogo()->mostrarFuentes() << '\n';
				std::cout << "Digite el modelo de la fuente que desea agregar al sistema: ";
				std::cin >> cod;

				if (tienda->getCatalogo()->getListProductos()->existeElemento(cod)) {
					Componente* compPtr = tienda->getCatalogo()->getListProductos()->obtenerElemento(cod);
					if (!compPtr->esSistema() && dynamic_cast<Fuente*>(compPtr) != nullptr) {
						personalizado->agregar(new Fuente(*dynamic_cast<Fuente*>(compPtr)));
						std::cout << "Se ha agregado la fuente de audio al sistema personalizado!\n\n";
						comp = false; //Para salir del bucle
						cambia++; //Se cambia a la siguiente etapa de personalizacion
						system("PAUSE");
					}
					else {
						std::cout << "El codigo ingresado no pertenece a un producto de la familia de fuentes de audio.\n¿Desea probar con otro? (1. Si || 0. No): ";
						std::cin >> comp;
						rep = comp;
					}
				}
				else {
					std::cout << "El codigo ingresado no pertenece a ninguna fuente de audio.\n¿Desea probar con otro? (1. Si || 0. No): ";
					std::cin >> comp;
					rep = comp;
				}
			} while (comp);
			break;

		case 2:
			comp = true; //Se reinicia la variable para la siguiente etapa
			do {
				system("CLS");
				std::cout << "----------PERSONALIZANDO SISTEMA----------\n";
				std::cout << tienda->getCatalogo()->mostrarProcesadores() << '\n';
				std::cout << "Digite el modelo del procesador de señal que desea agregar al sistema: ";
				std::cin >> cod;

				if (tienda->getCatalogo()->getListProductos()->existeElemento(cod)) {
					Componente* compPtr = tienda->getCatalogo()->getListProductos()->obtenerElemento(cod);
					if (!compPtr->esSistema() && dynamic_cast<Procesador*>(compPtr) != nullptr) {
						personalizado->agregar(new Procesador(*dynamic_cast<Procesador*>(compPtr)));
						std::cout << "Se ha agregado el procesador de señal al sistema personalizado!\n\n";
						cambia++; //Se cambia a la siguiente etapa de personalizacion 
						comp = false;
						system("PAUSE");
					}
					else {
						std::cout << "El codigo ingresado no pertenece a ningún producto de la familia de procesadores de señal.\n¿Desea probar con otro? (1. Si || 0. No): ";
						std::cin >> comp; 
						rep = comp;
					}
				}
				else {
					std::cout << "El codigo ingresado no pertenece a ningun procesador de señal.\n¿Desea probar con otro? (1. Si || 0. No): ";
					std::cin >> comp;
					rep = comp;
				}
			} while (comp);
			break;

		case 3:
			comp = true; //Se reinicia la variable para la siguiente etapa
			do {
				system("CLS");
				std::cout << "----------PERSONALIZANDO SISTEMA----------\n";
				std::cout << tienda->getCatalogo()->mostrarParlantes() << '\n';
				std::cout << "Digite el modelo del parlante que desea agregar al sistema: ";
				std::cin >> cod;

				if (tienda->getCatalogo()->getListProductos()->existeElemento(cod)) {
					Componente* compPtr = tienda->getCatalogo()->getListProductos()->obtenerElemento(cod);
					if (!compPtr->esSistema() && dynamic_cast<Parlante*>(compPtr) != nullptr) {
						personalizado->agregar(new Parlante(*dynamic_cast<Parlante*>(compPtr)));
						std::cout << "Se ha agregado el parlante al sistema personalizado!\n\n";
						cambia++;
						comp = false;
						rep = false;
					}
					else {
						std::cout << "El codigo ingresado no pertenece a ningún producto de la familia de parlentes.\n¿Desea probar con otro? (1. Si || 0. No): ";
						std::cin >> comp; 
						rep = comp;
					}
				}
				else {
					std::cout << "El codigo ingresado no pertenece a ningún parlante.\n¿Desea probar con otro? (1. Si || 0. No): ";
					std::cin >> comp;
					rep = comp;
				}
			} while (comp);
			break;

		default:
			break;
		}
	} while (rep);

	system("CLS");
	if (donde) {
		tienda->getCatalogo()->agregarProducto(personalizado);
		std::cout << "El sistema ha sido agregado al catálogo exitosamente!\n\n";
	}
	else {
		if (cambia == 4) { //Si es 4, se tiene un sistema completo.
			if (carrito == nullptr) carrito = new Lista<Componente>;
			carrito->insertarFinal(personalizado);
			std::cout << "Listo! Tu sistema personalizado ha sido creado. Ahora puedes encontrarlo en tu carrito de compras!\n\n";
			system("PAUSE");
		}
		else {
			delete personalizado; //Se descarta el sistema personalizado, pues se cancelo la operacion a media personalizacion.
			std::cout << "El sistema personalizado se ha descartado...\n";
			system("PAUSE");
		}
	}
	
}

void Menu::compraComponente(){
	std::string cod;
	bool sigue = true;
	carrito = new Lista<Componente>; //Actua como carrito de compras


	do {
		system("CLS");
		std::cout << tienda->getCatalogo()->mostrarSoloSistemas();
		std::cout << "Ingrese el codigo del componente que desea agregar al carrito: ";
		std::cin >> cod; 

		if (tienda->getCatalogo()->getListProductos()->existeElemento(cod)) {
			Componente* compPtr = tienda->getCatalogo()->getListProductos()->obtenerElemento(cod);

			if (!compPtr->esSistema()) { // Se confirma que sea un componente, para evitar agregaciones de otros componentes en pantallas donde no corresponde.
				int can;
				std::cout<<"¿Cuantas unidades desea?: ";
				std::cin >> can;

				if (dynamic_cast<Fuente*>(compPtr) != nullptr) {
					for (int i = 0; i < can; i++) carrito->insertarFinal(new Fuente(*dynamic_cast<Fuente*>(compPtr)));
				}
				else {
					if (dynamic_cast<Procesador*>(compPtr) != nullptr) {
						for (int i = 0; i < can; i++) {
							carrito->insertarFinal(new Procesador(*dynamic_cast<Procesador*>(compPtr)));
						}
					}
					else {
						if (dynamic_cast<Parlante*>(compPtr) != nullptr) {
							for (int i = 0; i < can; i++) {
								carrito->insertarFinal(new Parlante(*dynamic_cast<Parlante*>(compPtr)));
							}
						}
					}
				}

				std::cout << "Se ha agregado al carrito de compras correctamente!\n\n";
				std::cout << "Desea agregar algun otro componente al carrito? (1. Si || 0. No): ";
				std::cin >> sigue;
			}
			else {
				std::cout << "El código ingresado no corresponde a ningún componente. ¿Desea probar con otro? (1. Si || 0. No): ";
				std::cin >> sigue;
			}
		}
		else {
			std::cout << "El código ingresado no existe. ¿Desea probar con otro? (1. Si || 0. No): ";
			std::cin >> sigue;
		}
	} while (sigue);
	if (carrito->getActual() == nullptr) delete carrito;
}

void Menu::confirmaCarrito(std::string _cliente) {
	bool sigue = false;

	system("CLS");
	if (carrito != nullptr) {
		std::cout << "----------CARRITO DE COMPRAS----------\n";
		std::cout << carrito->toString() << '\n';
		std::cout << "¿Desea confirmar la compra? Digite '0' para volver. (1. Si || 0. No): ";
		std::cin >> sigue;
	}
	else {
		std::cout << "El carrito está vacio...\n";
		system("PAUSE");
	}
	
	system("CLS");

	if (sigue) {
		Fecha* fecha = new Fecha(); 
		fecha->actualizarPorActual();

		if (_cliente != "null") { //Si el cliente trae esa prescripcion significa que es una venta directa.
			Cliente* cliente = tienda->getCatalogo()->getListClients()->obtenerCliente(_cliente);
			int envio; //Para ingresar el codigo del lugar al cual enviar los productos.

			do {
				system("CLS");
				std::cout << tienda->mostrarPDirecciones() << '\n';
				std::cout << "Digite el código de la direccion de envío: ";
				std::cin >> envio;
				
				//if((envio != 10) && (envio != 20) && (envio != 30) && (envio != 31) && (envio != 32) && (envio != 40) && (envio != 40) && (envio != 50) && (envio != 60) && (envio != 90) && (envio != 91))
				if (tienda->determinaCostoEnvio(envio) == 0) {
					std::cout << "El código ingresado no corresponde a niguna de las direcciones de envío. Intentelo de nuevo.\n";
				}
				else {
					sigue = false;
				}
			} while (sigue);
			tienda->agregarVenta(new VentaEnLinea(fecha, cliente, carrito, envio));
			std::cout << "La compra se ha realizado con exito!\n";
			carrito = nullptr; //Se vacia el carrito
			system("PAUSE");
			
		}
		else {
			if (sigue) {
				std::string nomFactura;
				std::cout << "Digite el nombre al que debe ir dirigida la factura: ";
				std::getline(std::cin, nomFactura);
				tienda->agregarVenta(new VentaDirecta(fecha, carrito, nomFactura));
				carrito = nullptr; //Se vacia el carrito
			}
		}


	}
}

void Menu::registroCliente(int tipo) {
	std::string nomPais, ciudad, cedula, nombre;
	
	system("CLS");
	if (tipo == 1) {
		std::string correo, nacionalidad;
		std::cout << "----------Ingrese los Datos del Cliente----------\n";
		std::cout << "Cedula: ";
		std::cin >> cedula;
		std::cin.ignore();
		std::cout << "Nombre: ";
		getline(std::cin, nombre);
		std::cout << "Correo: ";
		std::cin >> correo;
		std::cout << "Nacionalidad: ";
		std::cin >> nacionalidad;
		std::cin.ignore();
		std::cout << "Pais: ";
		getline(std::cin, nomPais); 
		std::cout << "Ciudad: ";
		getline(std::cin, ciudad);
		tienda->agregarClienteCat(new Persona(nomPais, ciudad, cedula, correo, nacionalidad, nombre, tienda->getCatalogo()));
		std::cout << "\nCliente Fisico (Persona) subscrito con exito!\n";

	}
	else {
		std::cout << "----------Ingrese los Datos de la Empresa----------\n";
		std::cout << "Cedula Juridica: ";
		std::cin >> cedula;
		std::cout << "Nombre: ";
		std::cin >> nombre;
		std::cin.ignore();
		std::cout << "Pais: ";
		getline(std::cin, nomPais);
		std::cin.ignore();
		std::cout << "Ciudad: ";
		getline(std::cin, ciudad);
		tienda->agregarClienteCat(new Empresa(nomPais, ciudad, nombre, cedula, tienda->getCatalogo()));
		std::cout << "\nEmpresa subscrita con exito!\n";
	}
	system("PAUSE");
}

void Menu::ingresarComponente() {
	int opcion;

	std::cout << "--¿Qué categoría de componente desea ingresar?--\n"
		<< "1- Fuente de Audio\n"
		<< "2- Procesador De Señal\n"
		<< "3- Parlante\n"
		<< "4- Volver\n"
		<< "------------------------------------------------\n"
		<< "Ingrese una opción: ";
	std::cin >> opcion;

	std::string codig, categ, tipo, caract; 
	double precio; 
	if (opcion >= 1 && opcion <= 3) {
		if (opcion == 1) std::cout << "-----Creando Fuente de Audio-----\n";
		else if (opcion == 2) std::cout << "-----Creando Procesador de Señal-----\n";
		else if (opcion == 3) std::cout << "-----Creando Parlante-----\n";

		std::cout << "Digite el código: ";
		std::cin >> codig;
		std::cout << "Digite el precio: ";
		std::cin >> precio;
		std::cout << "Indique el tipo de componente que es: ";
		std::cin >> tipo;
		std::cout << "Indique las caracteristicas que posee: ";
		std::cin >> caract;

		if (opcion == 1) tienda->agregarProductosCat(new Fuente("Fuente de Audio", tipo, caract, codig, precio));
		else if (opcion == 2) tienda->agregarProductosCat(new Procesador("Procesador de Señal", tipo, caract, codig, precio));
		else if (opcion == 3) tienda->agregarProductosCat(new Parlante("Parlante", tipo, caract, codig, precio));
	}
	else {
		if (opcion == 4) {
			system("CLS");
		}
		else {
			std::cout << "La opción ingresada no es valida. Intentelo de nuevo.\n";
			system("PAUSE");
		}
	}
}

void Menu::eliminarItem(){
	std::string cod;
	std::cout << "Nota: La eliminacion de un componente implica la eliminacion de los sistemas donde esté incluido.\n\n";
	std::cout << "----------ELIMINACION DE ITEM----------\n"
		<< "Digite el codigo del item que desea eliminar (Componente o Sistema): ";
	std::cin >> cod;
	
	if (tienda->getCatalogo()->getListProductos()->eliminarElemento(cod)) std::cout << "El elemento ha sido eliminado con exito.";
	else std::cout << "No existe ningun elemento con el código indicado.\n";
	system("PAUSE");
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
