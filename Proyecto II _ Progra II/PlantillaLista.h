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

#ifndef PLANTILLALISTA_H
#define PLANTILLALISTA_H
#include "Nodo.h"
#include "IteradorLista.h"
#include "Iterador.h"
// Actualizado

template <class T>

class Lista {
private:
	Nodo<T>* actual;
	Nodo<T>* primero;
	int can;

public:
	//Constructor y Destructor
	Lista();
	virtual ~Lista();

	//Getters
	int getCan();
	IteradorLista<T>* getIterador();

	//Metodos Varios
	Nodo<T>* getActual();
	void setActual(Nodo<T>*);
	void insertarFinal(T*);
	void notificarObservers();
	double getPrecioTotal();
	bool existeElemento(std::string);
	bool existeTipoElemento(int);
	T* obtenerElemento(std::string);
	int obtenerCuantoRepite(std::string);
	std::string muestraClientesFisicos();
	std::string muestraClientesEmpresariales();
	std::string toString();
	std::string guardarDatos();
	std::string guardarIdentificadores();
	bool eliminarElemento(std::string);
};

//Constructor y Destructor
template<class T>
Lista<T>::Lista() {
	primero = nullptr;
	actual = nullptr;
	can = 0;
}

template<class T>
Lista<T>::~Lista() {
	actual = primero;
	while (actual != nullptr) {
		Nodo<T>* siguiente = actual->getSig();
		delete actual;
		actual = siguiente;
	}
}

//Getters
template<class T>
int Lista<T>::getCan() {
	return can;
}

template<class T>
IteradorLista<T>* Lista<T>::getIterador() {
	return new IteradorLista<T>(primero);
}


//Metodos Varios
template<class T>
Nodo<T>* Lista<T>::getActual(){
	return actual;
}

template<class T>
void Lista<T>::setActual(Nodo<T>* act){ 
	actual = act;
}

template<class T>
void Lista<T>::insertarFinal(T* dato) {
	actual = primero;
	if (primero == nullptr) {
		primero = new Nodo<T>(dato, nullptr);
	}
	else {
		while (actual->getSig() != nullptr) {
			actual = actual->getSig();
		}
		actual->setSig(new Nodo<T>(dato, nullptr));
	}
	can++;
}

template<class Cliente>
void Lista<Cliente>::notificarObservers() {
	actual = primero;
	while (actual != nullptr) {
		actual->getInfo()->update();
		actual = actual->getSig();
	}
}

template<class T>
double Lista<T>::getPrecioTotal() {
	double precio = 0;
	actual = primero;
	while (actual != nullptr) {
		precio += actual->getInfo()->obtenerPrecio();
		actual = actual->getSig();
	}
	return precio;
}

template<class T>
bool Lista<T>::existeElemento(std::string cod){
	actual = primero;
	while (actual != nullptr) {
		if (actual->getInfo()->getId() == cod) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
bool Lista<T>::existeTipoElemento(int tipo) {
	actual = primero;

	//El dynamic_cast es la medida más fiable para saber de que tipo es el componente, pues si bien la categoria
	//no se puede cambiar, es mejor prevenir, así, un error no desencadena otro.
	switch (tipo) {
	case 1:  //Saber si hay sistemas en el catalogo
		while (actual != nullptr) {
			if (actual->getInfo()->esSistema()) {
				return true;
			}
			actual = actual->getSig();
		}
		break;

	case 2: //Saber si hay componentes en el catalogo
		while (actual != nullptr) {
			if (!(actual->getInfo()->esSistema())) {
				return true;
			}
			actual = actual->getSig();
		}
		break;

	case 3: //Saber si hay fuentes de audio en el catalogo
		while (actual != nullptr) {
			if (dynamic_cast<Fuente*>(actual->getInfo()) != nullptr) {
				return true;
			}
			actual = actual->getSig();
		}
		break;

	case 4: //Saber si hay procesadores de señal en el catalogo
		while (actual != nullptr) {
			if (dynamic_cast<Procesador*>(actual->getInfo()) != nullptr) {
				return true;
			}
			actual = actual->getSig();
		}
		break;

	case 5: //Saber si hay parlantes en el catalogo
		while (actual != nullptr) {
		if (dynamic_cast<Parlante*>(actual->getInfo()) != nullptr) {
			return true;
		}
		actual = actual->getSig();
	}
		break;

	default:
		break;
	}


	//if (tipo == 1) { //Saber si hay sistemas en el catalogo
	//	while (actual != nullptr) {
	//		if (actual->getInfo()->esSistema()) {
	//			return true;
	//		}
	//		actual = actual->getSig();
	//	}
	//}
	//else {
	//	if (tipo == 2) { //Saber si hay componentes en el catalogo
	//		while (actual != nullptr) {
	//			if (!(actual->getInfo()->esSistema())) {
	//				return true;
	//			}
	//			actual = actual->getSig();
	//		}
	//	}
	//	else {
	//		if (tipo == 3) { //Saber si hay fuentes de audio en el catalogo
	//			while (actual != nullptr) {
	//				if (dynamic_cast<Fuente*>(actual->getInfo()) != nullptr) {
	//					return true;
	//				}
	//				actual = actual->getSig();
	//			}
	//		}
	//		else {
	//			if (tipo == 4) { //Saber si hay procesadores de señal en el catalogo
	//				while (actual != nullptr) {
	//					if (dynamic_cast<Procesador*>(actual->getInfo()) != nullptr) {
	//						return true;
	//					}
	//					actual = actual->getSig();
	//				}
	//			}
	//			else {
	//				if (tipo == 5) { //Saber si hay parlentes en el catalogo
	//					while (actual != nullptr) {
	//						if (dynamic_cast<Parlante*>(actual->getInfo()) != nullptr) {
	//							return true;
	//						}
	//						actual = actual->getSig();
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
	return false; //Si no hay existencias del componente indicado, se devuelve false.
}

template<class T>
T* Lista<T>::obtenerElemento(std::string cod){
	actual = primero;
	while (actual != nullptr) {
		if (actual->getInfo()->getId() == cod) {
				return actual->getInfo();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

template<class T>
int Lista<T>::obtenerCuantoRepite(std::string _identif) {
	int contador = 0;
	actual = primero;
	while (actual != nullptr) {
		if (actual->getInfo()->getId() == _identif) {
			contador++;
		}
		actual = actual->getSig();
	}
	return contador;
	
}

template<class T>
std::string Lista<T>::muestraClientesFisicos() {
	std::stringstream s;
	bool hayClientes = false;
	actual = primero;
	while (actual != nullptr) {
		if (!(actual->getInfo()->esEmpresa())) {
			s << actual->getInfo()->toString() << "\n";
			if(!hayClientes) hayClientes = true;
		}
		actual = actual->getSig();
	}
	if (!hayClientes) {
		return "No hay clientes fisicos registrados";
	}
	else {
		return s.str();
	}
	
}

template<class T>
std::string Lista<T>::muestraClientesEmpresariales() {
	std::stringstream s;
	bool hayClientes = false;
	actual = primero;
	while (actual != nullptr) {
		if (actual->getInfo()->esEmpresa()) {
			s << actual->getInfo()->toString() << "\n";
			if (!hayClientes) hayClientes = true;
		}
		actual = actual->getSig();
	}
	if (!hayClientes) {
		return "No hay clientes empresariales registrados";
	}
	else {
		return s.str();
	}
}

template<class T>
std::string Lista<T>::toString() {
	std::stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getInfo()->toString() << std::endl;
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
std::string Lista<T>::guardarDatos() { //Activa los metodos guardarDatos() de los objetos para guardar los datos de cada uno en un archivo .txt
	std::stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getInfo()->guardarDatos() << DELIMITA_REGISTRO; //DELIMITA_REGISTRO sirve como separador entre cada registro.
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
std::string Lista<T>::guardarIdentificadores() {
	std::stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getInfo()->getId() << DELIMITA_CAMPO;
		actual = actual->getSig();
	}
	return s.str();
}


template<class T>
bool Lista<T>::eliminarElemento(std::string cod) {
	actual = primero;
	if (primero->getInfo()->getId() == cod) {
		primero = primero->getSig();
		delete actual;
		can--;
		return true;
	}
	else {
		while (actual->getSig() != nullptr) {
			if (actual->getSig()->getInfo()->getId() == cod) {
				Nodo<T>* temp = actual->getSig();
				actual->setSig(temp->getSig());
				delete temp;
				can--;
				return true;
			}
			actual = actual->getSig();
		}
	}
	return false;
}

#endif // !PLANTILLALISTA_H
