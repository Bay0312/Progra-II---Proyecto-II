#ifndef ITERADORLISTA_H
#define ITERADORLISTA_H
#include "Nodo.h"

// Actualizado

template <class T>
class IteradorLista {
private:
	Nodo<T>* actual;
public:
	IteradorLista(Nodo<T>*);
	virtual ~IteradorLista();
	bool vacia();
	Nodo<T>* getSig();
	bool hayMas();
};

template<class T>
IteradorLista<T>::IteradorLista(Nodo<T>* _primero) {
	actual = _primero;
}

template<class T>
IteradorLista<T>::~IteradorLista() {
}

template<class T>
bool IteradorLista<T>::vacia() {
	return actual == nullptr;
}

template<class T>
Nodo<T>* IteradorLista<T>::getSig() {
	if (hayMas()) {
		actual = actual->getSig();
		return actual;
	}
	return nullptr;
}

template<class T>
bool IteradorLista<T>::hayMas() {
	return actual != nullptr && actual->getSig() != nullptr;
}

#endif // !ITERADORLISTA_H
