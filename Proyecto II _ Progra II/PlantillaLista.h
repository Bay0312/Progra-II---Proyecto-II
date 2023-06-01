#ifndef PLANTILLALISTA_H
#define PLANTILLALISTA_H
#include "Nodo.h"
#include "IteradorLista.h"
#include "Iterador.h"

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
	double getPrecioTotal();
	IteradorLista<T>* getIterador();
	Iterador<T>* getIterador2();
};

template<class T>
Lista<T>::Lista() {
	primero = nullptr;
	actual = nullptr;
	can = 0;
}

template<class T>
Lista<T>::~Lista() {
	while (primero != nullptr) {
		actual = primero;
		primero = primero->getSig();
		delete actual;
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
		s << actual->getInfo()->toString() << std::endl;
		actual = actual->getSig();
	}
	return s.str();
}

template<class T>
int Lista<T>::getCan() {
	return can;
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
IteradorLista<T>* Lista<T>::getIterador() {
	return new IteradorLista<T>(primero);
}

template<class T>
Iterador<T>* Lista<T>::getIterador2() {
	return new Iterador<T>(primero);
}

#endif // !PLANTILLALISTA_H
