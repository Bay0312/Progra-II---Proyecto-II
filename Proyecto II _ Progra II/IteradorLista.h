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

#ifndef ITERADORLISTA_H
#define ITERADORLISTA_H
#include "Nodo.h"

// Actualizado

template <class T>
class IteradorLista {
private:
	Nodo<T>* actual;

public:
	//Constructor y Destructor
	IteradorLista(Nodo<T>*);
	virtual ~IteradorLista();

	//Metodos Varios
	Nodo<T>* getActual(); 
	void setActual(Nodo<T>*);
	bool vacia();
	Nodo<T>* getSig();
	bool hayMas();
	void operator ++();
};

//Constructor y Destructor
template<class T>
IteradorLista<T>::IteradorLista(Nodo<T>* _primero) {
	actual = _primero;
}

template<class T>
IteradorLista<T>::~IteradorLista() {
}

//Metodos Varios
template<class T>
Nodo<T>* IteradorLista<T>::getActual(){
	return actual;
}

template<class T>
void IteradorLista<T>::setActual(Nodo<T>* act){
	actual = act;
}

template<class T>
bool IteradorLista<T>::vacia() {
	return actual == nullptr;
}

template<class T>
Nodo<T>* IteradorLista<T>::getSig() {
		actual = actual->getSig();
		return actual;
}

template<class T>
bool IteradorLista<T>::hayMas() {
	return actual != nullptr && actual->getSig() != nullptr;
}

template<class T>
void IteradorLista<T>::operator++() {
	actual = actual->getSig();
}
#endif // !ITERADORLISTA_H
