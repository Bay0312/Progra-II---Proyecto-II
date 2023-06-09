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

#include "Sistema.h"

//Constructor y Destructor
Sistema::Sistema() : Componente() {
	lista = new Lista<Componente>();
}

Sistema::Sistema(const Sistema& copSistema) {
	lista = new Lista<Componente>();
	IteradorLista<Componente>* iterador = copSistema.getLista()->getIterador();
	//Iterador<Componente>* iterador2 = copSistema.getLista()->getIterador2();

	while (iterador->getActual() != nullptr) {
		if (dynamic_cast<Fuente*>(iterador->getActual()->getInfo()) != nullptr) {
			Fuente* c = new Fuente(*dynamic_cast<Fuente*>(iterador->getActual()->getInfo()));
			this->agregar(c);
		}
		else {
			if (dynamic_cast<Procesador*>(iterador->getActual()->getInfo()) != nullptr) {
				Procesador* c = new Procesador(*dynamic_cast<Procesador*>(iterador->getActual()->getInfo()));
				this->agregar(c);
			}
			else {
				if (dynamic_cast<Parlante*>(iterador->getActual()->getInfo()) != nullptr) {
					Parlante* c = new Parlante(*dynamic_cast<Parlante*>(iterador->getActual()->getInfo()));
					this->agregar(c);
				}
			}
		}
		iterador->operator++();
	}
}

Sistema::~Sistema() {
	if(lista != nullptr) delete lista;
}

//Getters
Lista<Componente>* Sistema::getLista() const { return lista; }

//Metodos Varios
void Sistema::agregar(Componente* c) { 
	lista->insertarFinal(c);
}

double Sistema::obtenerPrecio() const {
	return lista->getPrecioTotal();
}

std::string Sistema::toString() const {
	std::stringstream s;
	s << lista->toString();
	return s.str();
}

bool Sistema::esSistema() const { return true; }