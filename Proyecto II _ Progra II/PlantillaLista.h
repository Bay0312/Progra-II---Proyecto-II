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
	void insertarFinal(T*);
	void notificarObservers();
	double getPrecioTotal();
	std::string toString();
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
std::string Lista<T>::toString() {
	std::stringstream s;
	actual = primero;
	while (actual != nullptr) {
		s << actual->getInfo() << std::endl;
		actual = actual->getSig();
	}
	return s.str();
}

#endif // !PLANTILLALISTA_H
