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
	Lista();
	virtual ~Lista();
	void insertarFinal(T*);
	std::string toString();
	int getCan();
	IteradorLista<T>* getIterador();
	void notificarObservers();
	double getPrecioTotal();
};

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

template<class T>
int Lista<T>::getCan() {
	return can;
}

template<class T>
IteradorLista<T>* Lista<T>::getIterador() {
	return new IteradorLista<T>(primero);
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

#endif // !PLANTILLALISTA_H
