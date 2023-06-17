#include "Tienda.h"

Tienda::Tienda(Catalogo* cat) {
	catalogo = cat;
	listaVentas = new Lista<Venta>();
}

Tienda::~Tienda() {
	delete catalogo;
	delete listaVentas;
}

Catalogo* Tienda::getCatalogo() {
	return catalogo;
}

Lista<Venta>* Tienda::getListaVentas() {
	return listaVentas;
}

void Tienda::agregarClienteCat(Cliente* _cliente) { //Para suscribir los clientes al catalogo
	catalogo->agregarCliente(_cliente);
}

void Tienda::agregarProductosCat(Componente* producto) {
	catalogo->agregarProducto(producto);
}

std::string Tienda::mostrarClientesCat() {
	return catalogo->mostrarClientes();
}

std::string Tienda::mostrarProductosCat() {
	return catalogo->mostrarTodo();
}

void Tienda::agregarVenta(Venta* venta) {
	listaVentas->insertarFinal(venta);
}

std::string Tienda::mostrarVentas() {
	return listaVentas->toString();
}

std::string Tienda::mostrarPDirecciones() {
	return VentaEnLinea::mostrarPDirecciones();
}

double Tienda::determinaCostoEnvio(int cod) {
	return VentaEnLinea::determinaCostoEnvio(cod);
}

std::string Tienda::reporteVentas() {
	IteradorLista<Venta>* iterador = listaVentas->getIterador();
	std::stringstream s;
	double ganancias = 0;
	int cantVentas = 0;
	if (iterador->getActual() == nullptr) {
		s << "No hay ventas registradas.";
	}
	else {
		s << "------------------REPORTE DE VENTAS------------------\n";
		s << "-----------------------------------------------------\n";

		while (iterador->getActual() != nullptr) {
			ganancias += iterador->getActual()->getInfo()->getPrecio();
			cantVentas++;
			iterador->operator++();
		}
		s << "Cantidad de ventas: " << cantVentas << "\n";
		s << "Ganancias totales: $" << ganancias << "\n";
		s << "Ganancia Bruta: N/A\n"; //No hay datos para saber estos datos, no se sabe a cuanto compra la tienda los productos, ni cuanto 
		s << "Ganancia Neta: N/A\n"; //se gana por envios, excepto por datos que si se saben que son ganancia total, como el 35% por ventas en linea.

	}
	return s.str();
}

std::string Tienda::reporteMasVendido() {
	IteradorLista<Componente>* iterador1 = catalogo->getListProductos()->getIterador();
	IteradorLista<Venta>* iterador2 = listaVentas->getIterador();
	Componente* guardado = nullptr;
	std::stringstream s;
	int contador1 = 0, contador2 = 0;

	if (iterador1->getActual() == nullptr) {
		s << "No hay ventas registradas.";
	}
	else {
		s << "------------------REPORTE DE MAS VENDIDO------------------\n";
		while (iterador1->getActual() != nullptr) {
			while (iterador2->getActual() != nullptr) {											
						 //iterador //trae nodo //trae obj //trae list.vend   //determina repeticion //se envia el id del producto actual  
				contador1 += iterador2->getActual()->getInfo()->getVendido()->obtenerCuantoRepite(iterador1->getActual()->getInfo()->getId());
				iterador2->operator++();
			}
			if (contador1 > contador2) {
				contador2 = contador1;
				guardado = iterador1->getActual()->getInfo();
			}
			iterador1->operator++();
			iterador2 = listaVentas->getIterador(); //Se reinicia el iterador para que vuelva a recorrer la lista de ventas.
		}
		s << "El producto más vendido de la tienda es: \n";
		s << "------------------------------------------------------------\n";
		s << guardado->toString() << '\n\n'; //Ignorar la advertencia, si se llega a este punto, guardado no es nulo.
		s << "Cantidad de veces vendido (Individualmente) : " << contador2 << '\n';
		s << "A raíz de su venta, es posible contabilizar una ganancia total de: $" << guardado->getPrecio() * contador2 << '\n';
	}
	
	return s.str();
}

bool Tienda::hayCompParaSistema() { //Determina si existe al menos una fuente, procesador y parlante para hacer un sistema.
	int hay = 0;
	//"existeTipoElemento()" necesita un entero, del 3 al 5 corresponden fuente, procesador y parlante.
	for (int i = 3; i <= 5; i++) {
		if (catalogo->getListProductos()->existeTipoElemento(i)) {
			hay++;
		}
	} //Al terminar el ciclo, si existen de los 3 tipos de componente para un sistema, "hay" debe valer 3.
	if (hay == 3) return true;
	else return false;
}

std::string Tienda::facturar(Venta* _vendido) {
	std::stringstream s;
	s << "---------------FACTURA---------------\n";
	s << _vendido->toString() << '\n';
	s << "---------------------------------------\n";
	return s.str();
}

std::string Tienda::guardarDatos(){
	std::stringstream s;
	s << catalogo->guardarDatos();
	s << listaVentas->guardarDatos();
	return s.str();
}

void Tienda::cargarDatos(std::string guardar[50], int cant) {
	if (cant == 6) { //Se verifica si la cantidad de datos es igual a la cantidad de datos que tiene un cliente fisico.
		this->agregarClienteCat(new Persona(guardar[3], guardar[4], guardar[0], guardar[5], guardar[2], guardar[1]));
	}
	else { //Se verifica si la cantidad de datos es igual a la cantidad de datos que tiene un cliente empresarial.
		if (cant == 4) {
			this->agregarClienteCat(new Empresa(guardar[2], guardar[3], guardar[1], guardar[0], catalogo));
		}
		else {
			if (cant == 7) {
				ayudaCargaComponente(guardar, true);
			}
			else {
				if (cant == 22) {
					ayudaCargaComponente(guardar, false); 
				}
				else {
					if (cant > 7 && cant != 22) {

						Componente* aux = nullptr;
						Lista<Componente>* agrega = new Lista<Componente>; //Aqui se va a poner la restaurada lista de lo vendido.
						if (guardar[0] == "Directa") {
							int _dia = stoi(guardar[1]);
							int _mes = stoi(guardar[2]);
							int _annio = stoi(guardar[3]);
							Fecha* fecha = new Fecha(_dia, _mes, _annio);
							IteradorLista<Componente>* iterador = catalogo->getListProductos()->getIterador();

							for (int i = 6; i < cant; i++) { //En el txt, la lista de lo guardado empieza en 5
								while (iterador->getActual() != nullptr) {
									if (iterador->getActual()->getInfo()->getId() == guardar[i]) { //Si el codigo es igual
										if (iterador->getActual()->getInfo()->esSistema()) {
											aux = new Sistema(*dynamic_cast<Sistema*>(iterador->getActual()->getInfo()));
										}
										else {
											if (iterador->getActual()->getInfo()->getCategoria() == "Fuente de Audio") {
												aux = new Fuente(*dynamic_cast<Fuente*>(iterador->getActual()->getInfo()));
											}
											else {
												if (iterador->getActual()->getInfo()->getCategoria() == "Procesador") {
													aux = new Procesador(*dynamic_cast<Procesador*>(iterador->getActual()->getInfo()));
												}
												else {
													if (iterador->getActual()->getInfo()->getCategoria() == "Parlante") {
														aux = new Parlante(*dynamic_cast<Parlante*>(iterador->getActual()->getInfo()));
													}
												}
											}
										}
										if (aux != nullptr) agrega->insertarFinal(aux); //Entonces se ingresa a la lista de restablecidos.
										aux = nullptr;
									}
									iterador->operator++(); //Se avanza a la siguiente posicion.
								}
								iterador = catalogo->getListProductos()->getIterador(); //Se reinicia el iterador, para volver a comprobar los datos
							}
							this->agregarVenta(new VentaDirecta(fecha, agrega, guardar[4]));
						}
						else {
							if (guardar[0] == "Linea") {
								IteradorLista<Componente>* iterador = catalogo->getListProductos()->getIterador();
								int _dia = stoi(guardar[1]);
								int _mes = stoi(guardar[2]);
								int _annio = stoi(guardar[3]);
								int _direc = stoi(guardar[5]); //Esta es la direccion de envio.
								Fecha* fecha = new Fecha(_dia, _mes, _annio);
								Cliente* cliente = catalogo->getListClients()->obtenerElemento(guardar[4]);

								for (int i = 6; i < cant; i++) { //En el txt, la lista de lo guardado empieza en 5
									while (iterador->getActual() != nullptr) {
										if (iterador->getActual()->getInfo()->getId() == guardar[i]) { //Si el codigo es igual
											if (iterador->getActual()->getInfo()->esSistema()) {
												aux = new Sistema(*dynamic_cast<Sistema*>(iterador->getActual()->getInfo()));
											}
											else {
												if (iterador->getActual()->getInfo()->getCategoria() == "Fuente de Audio") {
													aux = new Fuente(*dynamic_cast<Fuente*>(iterador->getActual()->getInfo()));
												}
												else {
													if (iterador->getActual()->getInfo()->getCategoria() == "Procesador") {
														aux = new Procesador(*dynamic_cast<Procesador*>(iterador->getActual()->getInfo()));
													}
													else {
														if (iterador->getActual()->getInfo()->getCategoria() == "Parlante") {
															aux = new Parlante(*dynamic_cast<Parlante*>(iterador->getActual()->getInfo()));
														}
													}
												}
											}
											if (aux != nullptr) agrega->insertarFinal(aux); //Entonces se ingresa a la lista de restablecidos.
											aux = nullptr;
										}
										iterador->operator++(); //Se avanza a la siguiente posicion.
									}
									iterador = catalogo->getListProductos()->getIterador(); //Se reinicia el iterador, para volver a comprobar los datos
								}
								this->agregarVenta(new VentaEnLinea(fecha, cliente, agrega, _direc));
							}
						}
						
					}
					
				}
			}
		}
	}
}

void Tienda::ayudaCargaComponente(std::string guardar[50], bool esComponente) { //esComponente para saber si es sistema o componente lo que se carga
	if (esComponente) {
		if (guardar[0] == "F") {
			this->agregarProductosCat(new Fuente(guardar[1], guardar[2], guardar[3], guardar[5], guardar[4], stod(guardar[6])));
		}
		else {
			if (guardar[0] == "P") { 
				this->agregarProductosCat(new Procesador(guardar[1], guardar[2], guardar[3], guardar[5], guardar[4], stod(guardar[6])));
			}
			else {
				if (guardar[0] == "A") { 
					this->agregarProductosCat(new Parlante(guardar[1], guardar[2], guardar[3], guardar[5], guardar[4], stod(guardar[6])));
				}
			}
		}
	}
	else {
		Sistema* nuevo = new Sistema();
		//IF INTERNO
		if (guardar[1] == "F") {
			nuevo->agregar(new Fuente(guardar[2], guardar[3], guardar[4], guardar[6], guardar[5], stod(guardar[7])));
		}
		else {
			if (guardar[1] == "P") {
				nuevo->agregar(new Procesador(guardar[2], guardar[3], guardar[4], guardar[6], guardar[5], stod(guardar[7])));
			}
			else {
				if (guardar[1] == "A") {
					nuevo->agregar(new Parlante(guardar[2], guardar[3], guardar[4], guardar[6], guardar[5], stod(guardar[7])));
				}
			}
		}
		//FIN IF INTERNO

		//IF INTERNO
		if (guardar[8] == "F") {
			nuevo->agregar(new Fuente(guardar[9], guardar[10], guardar[11], guardar[13], guardar[12], stod(guardar[14])));
		}
		else {
			if (guardar[8] == "P") {
				nuevo->agregar(new Procesador(guardar[9], guardar[10], guardar[11], guardar[13], guardar[12], stod(guardar[14])));
			}
			else {
				if (guardar[8] == "A") {
					nuevo->agregar(new Parlante(guardar[9], guardar[10], guardar[11], guardar[13], guardar[12], stod(guardar[14])));
				}
			}
		}
		//FIN IF INTERNO

		//IF INTERNO
		if (guardar[15] == "F") {
			nuevo->agregar(new Fuente(guardar[16], guardar[17], guardar[18], guardar[20], guardar[19], stod(guardar[21])));
		}
		else {
			if (guardar[15] == "P") {
				nuevo->agregar(new Procesador(guardar[16], guardar[17], guardar[18], guardar[20], guardar[19], stod(guardar[21])));
			}
			else {
				if (guardar[15] == "A") {
					nuevo->agregar(new Parlante(guardar[16], guardar[17], guardar[18], guardar[20], guardar[19], stod(guardar[21])));
				}
			}
		}
		//FIN IF INTERNO
		nuevo->setCodigo(guardar[0]); //Lo primero que se guarda de un sistema es su codigo
		this->agregarProductosCat(nuevo); //Se agrega el sistema que se acaba de crear
	}
}
