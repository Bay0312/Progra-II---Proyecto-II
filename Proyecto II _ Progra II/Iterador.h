#ifndef ITERADOR_H
#define ITERADOR_H
#include "Nodo.h"

template<class T>
class Iterador {
private:
	Nodo<T>* pNodo;
public:
	Iterador(Nodo<T>*);
	virtual ~Iterador();
	Nodo<T>* getPNodo();

	Iterador* operator = (Iterador&);
	bool operator != (const Iterador&);
	T* operator *();
	void operator ++();

};

template<class T>
Iterador<T>::Iterador(Nodo<T>* n) : pNodo{ n } {}

template<class T>
Iterador<T>::~Iterador(){}

template<class T>
Nodo<T>* Iterador<T>::getPNodo() { return pNodo; }

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
