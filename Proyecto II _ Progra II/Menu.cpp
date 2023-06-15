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
		system("CLS");
		try {
			std::cout << "----------MENU PRINCIPAL----------\n"
				<< "1. Venta Directa\n"
				<< "2. Venta en Linea\n"
				<< "3. Mantenimiento\n"
				<< "4. Guardar y Salir\n"
				<< "-----------------------------------\n"
				<< "Ingrese una opcion: ";
			if (!(std::cin >> opcion)) throw new ExcepcionValor();

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
				guardarDatos();
				system("CLS");
				break;
			default:
				std::cout << "Opcion invalida. Intentelo de nuevo\n";
				break;
			}
		}
		catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
			std::cout << e->toString() << '\n';
			std::cin.clear(); //Se limpia el buffer de entrada.
			std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
			system("PAUSE");
		}
		
	} while (opcion != 4);
	std::cout << "Gracias!\n";
}

void Menu::ventaDirecta(){
	int opcion = 0;
	bool decide;
	carrito = new Lista<Componente>();

	do {
		system("CLS");

		try {
			std::cout << "----------MENU VENTA DIRECTA----------\n"
				<< "1. Agregar Componentes Individuales al Carrito\n"
				<< "2. Agregar Sistemas de Sonido Pre-Configurados al Carrito \n"
				<< "3. Agregar Sistemas de Sonido Personalizados al Carrito\n"
				<< "4. Ver Carrito de Compras.\n"
				<< "5. Volver\n"
				<< "--------------------------------------\n"
				<< "Ingrese una opcion: ";
			if (!(std::cin >> opcion)) throw new ExcepcionValor();

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
				if (carrito->getCan() != 0) {
					std::cout << "Nota: Si no se confirma el carrito, se perdera la informacion.\n¿Desea Continuar? (1. Si || 0. No): ";
					if (!(std::cin >> decide)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
					if (decide) {
						delete carrito; //Si es nullptr
						carrito = nullptr;
					}
				}
				break;
			default:
				std::cout << "Opcion invalida. Intentelo de nuevo\n";
				break;
			}
		}
		catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
			std::cout << e->toString() << '\n';
			std::cin.clear(); //Se limpia el buffer de entrada.
			std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
			system("PAUSE");
		}
	} while (opcion != 5);
}

void Menu::ventaEnLinea(){ 
	int opcion = 0;
	std::string cod = "";
	bool sigue = false;

	system("CLS");
	std::cout << "Cliente, ingrese el número de cedula: ";
	std::cin >> cod;
	if (tienda->getCatalogo()->getListClients()->existeElemento(cod)) {
		std::cout << "\nCliente encontrado!\n";
		carrito = new Lista<Componente>;
		sigue = true;
		system("PAUSE");
	}
	else {
		std::cout << "El cliente no existe. Intentelo de nuevo.\n\n";
		system("PAUSE");
	}

	while (sigue) {
		system("CLS");
		try {
			std::cout << "----------MENU DE VENTA EN LINEA----------\n"
				<< "1. Agregar Sistema al carrito.\n"
				<< "2. Ver Carrito de Compras.\n"
				<< "3. Volver\n"
				<< "------------------------------------------\n"
				<< "Ingrese una opcion: ";
			if (!(std::cin >> opcion)) throw new ExcepcionValor();
			system("CLS");
			switch (opcion) {
			case 1:
				compraSistema();
				break;

			case 2:
				confirmaCarrito(cod);
				break;

			case 3:
				if (carrito != nullptr) {
					std::cout << "Nota: Si no se confirma el carrito, se perdera la informacion.\n¿Desea Continuar? (1. Si || 0. No): ";
					if (!(std::cin >> sigue)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
					if (sigue) {
						delete carrito; //Si es nullptr
						carrito = nullptr;
					}
				}
				else { //Si el carrito es null es porque la compra se concretó o bien porque no se ha agregado nada al mismo.
					system("CLS");
					sigue = false;
				}
				break;
			default:
				std::cout << "Opcion invalida. Intentelo de nuevo\n";
				break;
			}
		}
		catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
			std::cout << e->toString() << '\n';
			std::cin.clear(); //Se limpia el buffer de entrada.
			std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
			system("PAUSE");
		}
	}
}

void Menu::mantenimiento(){
	int opcion = 0, cual;
	do {
		try {
			system("CLS");
			std::cout << "----------MENU DE MANTENIMIENTO----------\n"
				<< "1. Mostrar Lista de Clientes\n"
				<< "2. Suscribir un Cliente al Catalogo\n"
				<< "3. Ingresar Componentes al Catalogo\n"
				<< "4. Ingresar Sistemas al Catalogo.\n"
				<< "5. Actualizar Informacion de un Item\n"
				<< "6. Eliminar un Item del Catalogo\n"
				<< "7. Volver\n"
				<< "-----------------------------------\n"
				<< "Ingrese una opcion: ";
			if (!(std::cin >> opcion)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.

			switch (opcion) {
				case 1:
				system("CLS");
				std::cout<<"¿Desea ver Clientes Fisicos o Empresariales?\n"
					<<"1. Clientes Fisicos\n"
					<<"2. Clientes Empresariales\n"
					<<"-----------------------------------\n"
					<<"Ingrese una opcion: ";
				if (!(std::cin >> cual)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
				system("CLS");
				if (cual == 1) {
					std::cout << tienda->getCatalogo()->getListClients()->muestraClientesFisicos() << "\n";
				}
				else if (cual == 2) {
					std::cout << tienda->getCatalogo()->getListClients()->muestraClientesEmpresariales() << "\n";
				}
				else {
					std::cout << "Opcion invalida. Intentelo de nuevo\n";
				}
				system("PAUSE");
				break;

			case 2:
				int aux;
				system("CLS");
				std::cout << "¿Que tipo de cliente va a registrar?\n"
					<< "1. Cliente Fisico (Persona)\n"
					<< "2. Cliente Juridico (Empresa)\n"
					<< "-----------------------------------\n"
					<< "Ingrese una opcion: ";
				if (!(std::cin >> aux)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
				if ((aux != 1 && aux != 2)) {
					std::cout << "Opcion invalida. Intentelo de nuevo\n";
				}
				else {
					registroCliente(aux);
				}
				break;
			case 3:
				ingresarComponente();
				break;
			case 4:
				personalizarSistema(true);
				break;

			case 5:
				actualizarItem();
				break;

			case 6:
				eliminarItem();
				break;
			case 7:
				system("CLS");
				break;
			default:
				std::cout << "Opcion invalida. Intentelo de nuevo\n";
				break;
			}
		}
		catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
			std::cout << e->toString() << '\n';
			std::cin.clear(); //Se limpia el buffer de entrada.
			std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
			system("PAUSE");
		}
		
	} while (opcion != 7);
}

void Menu::compraSistema() {
	std::string cod;
	bool sigue = true;

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
				try {
					std::cout << "¿Cuantas unidades desea?: ";
					if (!(std::cin >> can)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
					//Se clona el sistema, así, si se llega a eliminar del catalogo, este no se elimina de los datos de la venta.
					//Haciendo que se repita la clonacion, logramos qué en el carrito se agreguen sistemas diferentes, aunque sean el mismo, así es posible evitar confusiones en caso de revertir una compra.
					for (int i = 0; i < can; i++) carrito->insertarFinal(new Sistema(*dynamic_cast<Sistema*>(compPtr))); //Se agrega el componente al carrito
					std::cout << "Se ha agregado al carrito de compras correctamente!\n\n";
					std::cout << "Desea agregar otro sistema preconfigurado al carrito? (1. Si || 0. No): ";
					if (!(std::cin >> sigue)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
				}
				catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
					std::cout << e->toString() << '\n';
					std::cin.clear(); //Se limpia el buffer de entrada.
					std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
					system("PAUSE");
				}
			}
			else {
				try {
					std::cout << "El código ingresado no corresponde a un sistema preconfigurado.\n¿Desea probar con otro? (1. Si || 0. No): ";
					if (!(std::cin >> sigue)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
				}
				catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
					std::cout << e->toString() << '\n';
					std::cin.clear(); //Se limpia el buffer de entrada.
					std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
					system("PAUSE");
				}
			}
		}
		else {
			try {
				std::cout << "El código ingresado no existe.\n¿Desea probar con otro? (1. Si || 0. No): ";
				if (!(std::cin >> sigue)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
			}
			catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
				std::cout << e->toString() << '\n';
				std::cin.clear(); //Se limpia el buffer de entrada.
				std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
				system("PAUSE");
			}
		}
	} while (sigue);
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
				try {
					system("CLS");
					std::cout << "----------PERSONALIZANDO SISTEMA----------\n";
					std::cout << tienda->getCatalogo()->mostrarFuentes() << '\n';
					std::cout << "Digite el modelo de la fuente que desea agregar al sistema: ";
					std::cin >> cod;

					if (tienda->getCatalogo()->getListProductos()->existeElemento(cod)) {
						Componente* compPtr = tienda->getCatalogo()->getListProductos()->obtenerElemento(cod);
						if (compPtr->getCategoria() == "Fuente de Audio") {
							//if (!compPtr->esSistema() && dynamic_cast<Fuente*>(compPtr) != nullptr) {
							//Se agrega con dynamic cast, sino lo reconoce como componente, además, se agrega como clonacion usando el constructor copia.
							personalizado->agregar(new Fuente(*dynamic_cast<Fuente*>(compPtr)));
							std::cout << "Se ha agregado la fuente de audio al sistema personalizado!\n\n";
							comp = false; //Para salir del bucle
							cambia++; //Se cambia a la siguiente etapa de personalizacion
							system("PAUSE");
						}
						else {
							std::cout << "El codigo ingresado no pertenece a un producto de la familia de fuentes de audio.\n¿Desea probar con otro? (1. Si || 0. No): ";
							if (!(std::cin >> comp)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
							rep = comp;
						}
					}
					else {
						std::cout << "El codigo ingresado no pertenece a ninguna fuente de audio.\n¿Desea probar con otro? (1. Si || 0. No): ";
						if (!(std::cin >> comp)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
						rep = comp;
					}
				}
				catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
					std::cout << e->toString() << '\n';
					std::cin.clear(); //Se limpia el buffer de entrada.
					std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
					system("PAUSE");
				}
			} while (comp);
			break;

		case 2:
			comp = true; //Se reinicia la variable para la siguiente etapa
			do {
				try {
					system("CLS");
					std::cout << "----------PERSONALIZANDO SISTEMA----------\n";
					std::cout << tienda->getCatalogo()->mostrarProcesadores() << '\n';
					std::cout << "Digite el modelo del procesador de señal que desea agregar al sistema: ";
					std::cin >> cod;

					if (tienda->getCatalogo()->getListProductos()->existeElemento(cod)) {
						Componente* compPtr = tienda->getCatalogo()->getListProductos()->obtenerElemento(cod);
						if (compPtr->getCategoria() == "Procesador Señal") {
							//if (!compPtr->esSistema() && dynamic_cast<Procesador*>(compPtr) != nullptr) {
							//Se agrega con dynamic cast, sino lo reconoce como componente, además, se agrega como clonacion usando el constructor copia.
							personalizado->agregar(new Procesador(*dynamic_cast<Procesador*>(compPtr)));
							std::cout << "Se ha agregado el procesador de señal al sistema personalizado!\n\n";
							cambia++; //Se cambia a la siguiente etapa de personalizacion 
							comp = false;
							system("PAUSE");
						}
						else {
							std::cout << "El codigo ingresado no pertenece a ningún producto de la familia de procesadores de señal.\n¿Desea probar con otro? (1. Si || 0. No): ";
							if (!(std::cin >> comp)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
							rep = comp;
						}
					}
					else {
						std::cout << "El codigo ingresado no pertenece a ningun procesador de señal.\n¿Desea probar con otro? (1. Si || 0. No): ";
						if (!(std::cin >> comp)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
						rep = comp;
					}
				}
				catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
					std::cout << e->toString() << '\n';
					std::cin.clear(); //Se limpia el buffer de entrada.
					std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
					system("PAUSE");
				}
			} while (comp);
			break;

		case 3:
			comp = true; //Se reinicia la variable para la siguiente etapa
			do {
				try {
					system("CLS");
					std::cout << "----------PERSONALIZANDO SISTEMA----------\n";
					std::cout << tienda->getCatalogo()->mostrarParlantes() << '\n';
					std::cout << "Digite el modelo del parlante que desea agregar al sistema: ";
					std::cin >> cod;

					if (tienda->getCatalogo()->getListProductos()->existeElemento(cod)) {
						Componente* compPtr = tienda->getCatalogo()->getListProductos()->obtenerElemento(cod);
						if (compPtr->getCategoria() == "Parlante") {
							//if (!compPtr->esSistema() && dynamic_cast<Parlante*>(compPtr) != nullptr) {
							//Se agrega con dynamic cast, sino lo reconoce como componente, además, se agrega como clonacion usando el constructor copia.
							personalizado->agregar(new Parlante(*dynamic_cast<Parlante*>(compPtr)));
							std::cout << "Se ha agregado el parlante al sistema personalizado!\n\n";


							do {
								std::cout << "Agregue un codigo identificador al sistema que ha creado: ";
								std::cin >> cod;
								if (!(tienda->getCatalogo()->getListProductos()->existeElemento(cod))) {
									personalizado->setCodigo(cod);
									comp = false; //Para salir de este bucle y el que le sigue.
								}
								else {
									std::cout << "El codigo ingresado ya existe, por favor ingrese otro. ";
									system("CLS");
								}
							} while (comp);
							cambia++;
							rep = false; //Para salir del bucle principal
						}
						else {
							std::cout << "El codigo ingresado no pertenece a ningún producto de la familia de parlentes.\n¿Desea probar con otro? (1. Si || 0. No): ";
							if (!(std::cin >> comp)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
							rep = comp; //Para salir del bucle principal en caso de que el usuario no quiera seguir personalizando
						}
					}
					else {
						std::cout << "El codigo ingresado no pertenece a ningún parlante.\n¿Desea probar con otro? (1. Si || 0. No): ";
						if (!(std::cin >> comp)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
						rep = comp;
					}
				}
				catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
					std::cout << e->toString() << '\n';
					std::cin.clear(); //Se limpia el buffer de entrada.
					std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
					system("PAUSE");
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
			carrito->insertarFinal(personalizado);
			std::cout << "Listo! Tu sistema personalizado ha sido creado. Ahora puedes encontrarlo en tu carrito de compras!\n\n";
			system("PAUSE");
		}
		else {
			delete personalizado; //Se descarta el sistema personalizado, pues se cancelo la operacion.
			std::cout << "El sistema personalizado se ha descartado...\n";
			system("PAUSE");
		}
	}
	
}

void Menu::compraComponente(){
	std::string cod;
	bool sigue = true;

	do {
		try {
			system("CLS");
			std::cout << tienda->getCatalogo()->mostrarSoloSistemas();
			std::cout << "Ingrese el codigo del componente que desea agregar al carrito: ";
			std::cin >> cod;

			if (tienda->getCatalogo()->getListProductos()->existeElemento(cod)) {
				Componente* compPtr = tienda->getCatalogo()->getListProductos()->obtenerElemento(cod);

				if (!compPtr->esSistema()) { // Se confirma que sea un componente, para evitar agregaciones de otros componentes en pantallas donde no corresponde.
					int can;
					std::cout << "¿Cuantas unidades desea?: ";
					if (!(std::cin >> can)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.

					//if(compPtr->getCategoria() == "Fuente de Audio"){
					if (dynamic_cast<Fuente*>(compPtr) != nullptr) {
						for (int i = 0; i < can; i++) carrito->insertarFinal(new Fuente(*dynamic_cast<Fuente*>(compPtr)));
					}
					else {
						//if(compPtr->getCategoria() == "Procesador Señal"){
						if (dynamic_cast<Procesador*>(compPtr) != nullptr) {
							for (int i = 0; i < can; i++) {
								carrito->insertarFinal(new Procesador(*dynamic_cast<Procesador*>(compPtr)));
							}
						}
						else {
							//if(compPtr->getCategoria() == "Parlante"){
							if (dynamic_cast<Parlante*>(compPtr) != nullptr) {
								for (int i = 0; i < can; i++) {
									carrito->insertarFinal(new Parlante(*dynamic_cast<Parlante*>(compPtr)));
								}
							}
						}
					}

					std::cout << "Se ha agregado al carrito de compras correctamente!\n\n";
					std::cout << "Desea agregar algun otro componente al carrito? (1. Si || 0. No): ";
					if (!(std::cin >> sigue)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
				}
				else {
					std::cout << "El código ingresado no corresponde a ningún componente. ¿Desea probar con otro? (1. Si || 0. No): ";
					if (!(std::cin >> sigue)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
				}
			}
			else {
				std::cout << "El código ingresado no existe. ¿Desea probar con otro? (1. Si || 0. No): ";
				if (!(std::cin >> sigue)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
			}
		}
		catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
			std::cout << e->toString() << '\n';
			std::cin.clear(); //Se limpia el buffer de entrada.
			std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
			system("PAUSE");
		}
	} while (sigue);
}

void Menu::confirmaCarrito(std::string _cliente) {
	bool sigue = false;
	//SEGUIR CON EXCEPCIONES DESDE AQUÍ
	system("CLS");

	try {
		if (carrito != nullptr) {
			std::cout << "----------CARRITO DE COMPRAS----------\n";
			std::cout << carrito->toString() << '\n';
			std::cout << "¿Desea confirmar la compra? Digite '0' para volver. (1. Si || 0. No): ";
			if (!(std::cin >> sigue)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
		}
		else {
			std::cout << "El carrito está vacio...\n";
			system("PAUSE");
		}

		system("CLS");

		if (sigue) {
			Fecha* fecha = new Fecha();
			fecha->actualizarPorActual();

			if (_cliente != "null") { //Si "_cliente" no trae esa prescripcion significa que es una venta en linea.
				Cliente* cliente = tienda->getCatalogo()->getListClients()->obtenerElemento(_cliente);
				int envio; //Para ingresar el codigo del lugar al cual enviar los productos.

				do {
					system("CLS");
					std::cout << tienda->mostrarPDirecciones() << '\n';
					std::cout << "Digite el código de la direccion de envío: ";
					if (!(std::cin >> envio)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.

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
	catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
		std::cout << e->toString() << '\n';
		std::cin.clear(); //Se limpia el buffer de entrada.
		std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
		system("PAUSE");
	}
}

void Menu::registroCliente(int tipo) {
	std::string nomPais, ciudad, cedula, nombre;
	
	system("CLS");
	if (tipo == 1) {
		try {
			std::string correo, nacionalidad;
			std::cout << "----------Ingrese los Datos del Cliente----------\n";
			std::cout << "Cedula: ";
			std::cin >> cedula;
			existenciaExcepcion(cedula); //Verifica que la cedula no exista ya en el sistema.
			std::cin.ignore(1000, '\n');
			std::cout << "Nombre: ";
			std::getline(std::cin, nombre);
			std::cout << "Correo: ";
			std::cin >> correo;
			std::cin.ignore(1000, '\n');
			std::cout << "Nacionalidad: ";
			std::cin >> nacionalidad;
			std::cin.ignore(1000, '\n');
			std::cout << "Pais: ";
			std::getline(std::cin, nomPais);
			std::cout << "Ciudad: ";
			std::getline(std::cin, ciudad);
			Cliente* nuevo = new Persona(nomPais, ciudad, cedula, correo, nacionalidad, nombre, tienda->getCatalogo());
			bool decide; 
			system("CLS");
			std::cout << "Según los datos ingresados, verifique que no haya cometido errores en el ingreso: \n";
			std::cout << nuevo->toString() << '\n';

			std::cout << "¿Confirma que todos los datos se encuentran en orden? (1. Si || 0. No): ";
			if (!(std::cin >> decide)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.

			if (decide) {
				tienda->agregarClienteCat(nuevo);
				std::cout << "\nCliente Fisico (Persona) subscrito con exito!\n";
			}
			else {
				std::cout << "Se han descartado los datos del cliente. Puede volver a ingresarlos siguiendo la misma ruta...\n";
			}
		}
		catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
			std::cout << e->toString() << '\n';
			std::cin.clear(); //Se limpia el buffer de entrada.
			std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
		}
	}
	else {
		try {
			std::cout << "----------Ingrese los Datos de la Empresa----------\n";
			std::cout << "Cedula Juridica: ";
			std::cin >> cedula;
			existenciaExcepcion(cedula); //Se verifica que la cedula ingresada no exista en el catalogo.
			std::cin.ignore(1000, '\n');
			std::cout << "Nombre: ";
			std::getline(std::cin, nombre);
			std::cout << "Pais: ";
			getline(std::cin, nomPais);
			std::cout << "Ciudad: ";
			getline(std::cin, ciudad);
			
			Cliente* nuevo = new Empresa(nomPais, ciudad, nombre, cedula, tienda->getCatalogo());
			bool decide;
			system("CLS");
			std::cout << "Según los datos ingresados, verifique que no haya cometido errores en el ingreso: \n";
			std::cout << nuevo->toString() << '\n';

			std::cout << "¿Confirma que todos los datos se encuentran en orden? (1. Si || 0. No): ";
			if (!(std::cin >> decide)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.

			if (decide) {
				tienda->agregarClienteCat(nuevo);
				std::cout << "\nEmpresa subscrita con exito!\n";
			}
			else {
				std::cout << "Se han descartado los datos del cliente. Puede volver a ingresarlos siguiendo la misma ruta...\n";
			}
		}
		catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
			std::cout << e->toString() << '\n';
			std::cin.clear(); //Se limpia el buffer de entrada.
			std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
		}
	}
	system("PAUSE");
}

void Menu::actualizarItem(){
	std::string cod;
	int opcion;
	bool sigue = true;

	std::cout << "----------ACTUALIZACIÓN DE ITEM----------\n"
		<< "Digite el codigo del item que desea actualizar (Componente o Sistema): ";
	std::cin >> cod;
	system("CLS");

	if (tienda->getCatalogo()->getListProductos()->existeElemento(cod)) {
		Componente* compPtr = tienda->getCatalogo()->getListProductos()->obtenerElemento(cod);

		if (compPtr->esSistema()) {
			while (sigue) {
				system("CLS");
				try {
					std::cout << "----------ACTUALIZACIÓN DEL SISTEMA CODIGO <" << compPtr->getId() << ">----------\n"
						<< compPtr->toString() << '\n'
						<< "1. Código\n"
						<< "2. Componentes que lo Integran\n"
						<< "3. Salir" //No se actualiza la categoría, pues es un atributo que no se debe cambiar.
						<< "------------------------------------------\n"
						<< "Ingrese una opción: ";
					if (!(std::cin >> opcion)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.

					switch (opcion) {
					case 1:
						std::cout << "Ingrese el nuevo código que desea asignarle al producto: ";
						std::cin >> cod;
						existenciaExcepcion(cod);
						compPtr->setCodigo(cod);
						std::cout << "El codigo del sistema ha sido cambiado exitosamente!\n";
						system("PAUSE");
						break;

					case 2:
						//VA
						break;

					case 3:
						sigue = false;
						system("CLS");
						break;
					default: std::cout << "La opción ingresada no existe. Intentelo de nuevo.\n";
						system("PAUSE");
						break;
					}
				}
				catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
					std::cout << e->toString() << '\n';
					std::cin.clear(); //Se limpia el buffer de entrada.
					std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
					system("PAUSE");
				}
			}
		}
		else {

		}
		while (sigue) {
			try {
				system("CLS");
				std::cout << "----------ACTUALIZACIÓN DE COMPONENTE----------\n"
					<< compPtr->toString() << '\n'
					<< "¿Qué desea actualizar del producto?\n"
					<< "1. Codigo\n"
					<< "2. Precio\n"
					<< "3. Tipo de Componente\n"
					<< "4. Caracteristicas\n"
					<< "5. Modelo\n"
					<< "6. Salir\n" //No se actualiza la categoría, pues es un atributo que no se debe cambiar.
					<< "------------------------------------------\n"
					<< "Ingrese una opción: ";
				if (!(std::cin >> opcion)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
				system("CLS");
				switch (opcion) {
				case 1:
					std::cout << "Ingrese el nuevo código que desea asignarle al producto: ";
					std::cin >> cod;
					existenciaExcepcion(cod); //Se verifica que el codigo no pertenezca a otro producto del catalogo.
					compPtr->setCodigo(cod);
					std::cout << "El codigo del producto ha sido cambiado exitosamente!\n";
					system("PAUSE");
					break;

				case 2:
					double prec;
					std::cout << "Ingrese el nuevo precio que desea asignarle al producto: ";
					if (!(std::cin >> prec)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
					compPtr->setPrecio(prec);
					std::cout << "El precio del producto ha sido cambiado exitosamente!\n";
					system("PAUSE");
					break;

				case 3:
					std::cout << "Ingrese el nuevo tipo de componente que desea asignarle al producto: ";
					std::cin >> cod;
					compPtr->setTipo(cod);
					std::cout << "El tipo de componente del producto ha sido cambiado exitosamente!\n";
					system("PAUSE");
					break;

				case 4:
					std::cout << "Ingrese las nuevas caracteristicas que desea asignarle al producto: ";
					std::getline(std::cin, cod);
					compPtr->setCaracteristicas(cod);
					std::cout << "Las caracteristicas del producto han sido cambiadas exitosamente!\n";
					system("PAUSE");
					break;

				case 5:
					std::cout << "Ingrese el nuevo modelo que desea asignarle al producto: ";
					std::getline(std::cin, cod);
					compPtr->setModelo(cod);
					std::cout << "El modelo del producto ha sido cambiado exitosamente!\n";
					system("PAUSE");
					break;

				case 6:
					sigue = false;
					break;
				default:
					break;
				}
			}
			catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
				std::cout << e->toString() << '\n';
				std::cin.clear(); //Se limpia el buffer de entrada.
				std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
				system("PAUSE");
			}
		}
	} else {
		std::cout << "El codigo ingresado no pertenece a ningun componente o sistema del catalogo.\n";
		system("PAUSE");
	}
	system("CLS");
}

void Menu::ingresarComponente() {
	int opcion;
	bool sigue = true;
	std::string codig, categ, tipo, modelo, caract;
	double precio;

	while (sigue) {
		system("CLS");
		try {
			std::cout << "--¿Qué categoría de componente desea ingresar?--\n"
				<< "1- Fuente de Audio\n"
				<< "2- Procesador De Señal\n"
				<< "3- Parlante\n"
				<< "4- Volver\n"
				<< "------------------------------------------------\n"
				<< "Ingrese una opción: ";
			if (!(std::cin >> opcion)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.

			if (opcion >= 1 && opcion <= 3) {
				system("CLS");
				if (opcion == 1) std::cout << "-----Creando Fuente de Audio-----\n";
				else if (opcion == 2) std::cout << "-----Creando Procesador de Señal-----\n";
				else if (opcion == 3) std::cout << "-----Creando Parlante-----\n";

				std::cout << "Digite el código: ";
				std::cin >> codig;
				existenciaExcepcion(codig, false);
				std::cout << "Digite el precio: ";
				if (!(std::cin >> precio)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
				std::cin.ignore();
				std::cout << "Indique el modelo del componente: ";
				std::getline(std::cin, modelo);
				std::cout << "Indique el tipo de componente que es (radio, amplificador, audifono...): ";
				std::getline(std::cin, tipo);
				std::cout << "Indique las caracteristicas que posee: ";
				std::getline(std::cin, caract);

				if (opcion == 1) tienda->agregarProductosCat(new Fuente("Fuente de Audio", tipo, modelo, caract, codig, precio));
				else if (opcion == 2) tienda->agregarProductosCat(new Procesador("Procesador Señal", tipo, modelo, caract, codig, precio));
				else if (opcion == 3) tienda->agregarProductosCat(new Parlante("Parlante", tipo, modelo, caract, codig, precio));

				std::cout << "\nEl componente ha sido ingresado exitosamente!\n";
				system("PAUSE");
			}
			else {
				if (opcion == 4) {
					sigue = false;
					system("CLS");
				}
				else {
					std::cout << "\nLa opción ingresada no es valida. Intentelo de nuevo.\n";
					system("PAUSE");
				}
			}
		}
		catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
			std::cout << e->toString() << '\n';
			std::cin.clear(); //Se limpia el buffer de entrada.
			std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
			system("PAUSE");
		}
	}
}

void Menu::eliminarItem(){
	std::string cod;
	//std::cout << "Nota: La eliminacion de un componente implica la eliminacion de los sistemas donde esté incluido.\n\n";
	std::cout << "----------ELIMINACION DE ITEM----------\n"
		<< "Digite el codigo del item que desea eliminar (Componente o Sistema): ";
	std::cin >> cod;
	
	if (tienda->getCatalogo()->getListProductos()->existeElemento(cod)) {
		bool decide;
		std::cout << "Se ha encontrado el siguiente item: ";
		std::cout << tienda->getCatalogo()->getListProductos()->obtenerElemento(cod)->toString() << '\n';
		try {
			std::cout << "¿Desea continuar con la operacion de eliminacion? (1. Si || 0. No): ";
			if (!(std::cin >> decide)) throw new ExcepcionValor(); //Si se ingresa un valor no correspondiente se lanza una excepcion.
			if (decide) {
				tienda->getCatalogo()->getListProductos()->eliminarElemento(cod);
				std::cout << "El item ha sido eliminado con exito.\n";
			}
			else {
				std::cout << "Se ha cancelado la operacion de eliminacion del item.\n";
			}
		}
		catch (Excepcion* e) { //Si se ingresó un valor no correspondiente se recibe una excepcion y se muestra el mensaje de error.
			std::cout << e->toString() << '\n';
			std::cin.clear(); //Se limpia el buffer de entrada.
			std::cin.ignore(1000, '\n'); //Se ignora el resto de la linea.
			system("PAUSE");
		}
	}
	else {
		std::cout << "No existe ningun elemento con el código indicado.\n";
	}
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
		file << tienda->guardarDatos();
	}
	file.close(); //Se cierra el archivo
}
void Menu::cargarDatos(){
	std::ifstream file; //ifstream permite abrir el archivo para lectura
	std::string buffer;
	std::string guardar[20];
	int cant = 0;
	system("CLS");

	
	file.open("guardadoArchivo.txt", std::ios::in); //Abre el archivo para lectura
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

void Menu::existenciaExcepcion(std::string _identif, bool cual){
	if (cual) {
		if (tienda->getCatalogo()->getListClients()->existeElemento(_identif)) {
			throw new ExcepcionDeExistencia();
		}
	}
	else {
		if (tienda->getCatalogo()->getListProductos()->existeElemento(_identif)) {
			throw new ExcepcionDeExistencia();
		}
	}
}
