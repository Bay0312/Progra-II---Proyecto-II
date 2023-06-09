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
	T* obtenerElemento(std::string);
	bool existeCliente(std::string);
	T* obtenerCliente(std::string);
	std::string toString();
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
		if (actual->getInfo()->getCodigo() == cod) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

template<class T>
T* Lista<T>::obtenerElemento(std::string cod){
	actual = primero;
	while (actual != nullptr) {
		if (actual->getInfo()->getCodigo() == cod) {
				return actual->getInfo();
		}
		actual = actual->getSig();
	}
	return nullptr;
}

template<class T>
bool Lista<T>::existeCliente(std::string cod){
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
T* Lista<T>::obtenerCliente(std::string cod){
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
bool Lista<T>::eliminarElemento(std::string cod) {
	actual = primero;
	if (primero->getInfo()->getCodigo() == cod) {
		primero = primero->getSig();
		delete actual;
		can--;
		return true;
	}
	else {
		while (actual->getSig() != nullptr) {
			if (actual->getSig()->getInfo()->getCodigo() == cod) {
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
