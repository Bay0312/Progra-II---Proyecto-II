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

#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo {
private:
	T* info;
	Nodo<T>* sig;

public:
	//Constructor y Destructor
	Nodo(T*, Nodo<T>*);
	virtual ~Nodo();

	//Getters
	T* getInfo() const;
	Nodo<T>* getSig() const;

	//Setters
	void setInfo(T*);
	void setSig(Nodo<T>*);
};

//Constructor y Destructor
template<class T>
Nodo<T>::Nodo(T* dato, Nodo<T>* _sig) {
	info = dato;
	sig = _sig;
}

template<class T>
Nodo<T>::~Nodo() {
	delete info;
}

//Getters
template<class T>
T* Nodo<T>::getInfo() const {
	return info;
}

template<class T>
Nodo<T>* Nodo<T>::getSig() const {
	return sig;
}

//Setters
template<class T>
void Nodo<T>::setInfo(T* dato) {
	info = dato;
}

template<class T>
void Nodo<T>::setSig(Nodo<T>* _sig) {
	sig = _sig;
}

#endif // !NODO_H