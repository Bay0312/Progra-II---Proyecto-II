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

#ifndef ITERADOR_H
#define ITERADOR_H
#include "Nodo.h"

template<class T>
class Iterador {
private:
	Nodo<T>* pNodo;

public:
	//Constructor y Destructor
	Iterador(Nodo<T>*);
	virtual ~Iterador();

	//Getter
	Nodo<T>* getPNodo();

	//Operadores
	Iterador* operator = (Iterador&);
	bool operator != (const Iterador&);
	T* operator *();
	void operator ++();

};

//Constructor y Destructor
template<class T>
Iterador<T>::Iterador(Nodo<T>* n) : pNodo{ n } {}

template<class T>
Iterador<T>::~Iterador(){}

//Getter
template<class T>
Nodo<T>* Iterador<T>::getPNodo() { return pNodo; }

//Operadores
template<class T>
Iterador<T>* Iterador<T>::operator=(Iterador& itera) {
	if (this != &itera) {
		return new Iterador(itera.getPNodo());
	}
	return this;
}

template<class T>
bool Iterador<T>::operator!=(const Iterador& itera) {
	if (&itera != nullptr) {
		if (this->pNodo == nullptr && itera.pNodo == nullptr) {
			return false;
		}
		if (this->pNodo != itera.pNodo) {
			return true;
		}
	}
	return true;
}

template<class T>
T* Iterador<T>::operator*() { return (this->getPNodo()->getInfo()); }

template<class T>
void Iterador<T>::operator++() { pNodo = this->pNodo->getSig(); }


#endif // !ITERADOR_H
