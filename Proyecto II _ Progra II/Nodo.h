#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <sstream>

template <class T>

class Nodo {
private:
	T* info;
	Nodo<T>* sig;
public:
	Nodo();
	Nodo(T*, Nodo<T>*);
	virtual ~Nodo();
	T* getInfo() const;
	Nodo<T>* getSig() const;
	void setInfo(T*);
	void setSig(Nodo<T>*);
};

template<class T>
Nodo<T>::Nodo() : info{ nullptr }, sig{ nullptr } {}

template<class T>
Nodo<T>::Nodo(T* dato, Nodo<T>* _sig) : info{ dato }, sig{ _sig } {}

template<class T>
Nodo<T>::~Nodo() {
	delete info;
}

template<class T>
T* Nodo<T>::getInfo() const {
	return info;
}

template<class T>
Nodo<T>* Nodo<T>::getSig() const {
	return sig;
}

template<class T>
void Nodo<T>::setInfo(T* dato) {
	info = dato;
}

template<class T>
void Nodo<T>::setSig(Nodo<T>* _sig) {
	sig = _sig;
}

#endif // !NODO_H