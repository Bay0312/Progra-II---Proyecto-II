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
	categoria = "Sistema";
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
	this->categoria = copSistema.categoria;
	this->codigo = copSistema.codigo;
	this->precio = obtenerPrecio();
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
	s << "---------------SISTEMA DE AUDIO CODIGO <" << codigo << ">---------------\n"
		<< "**INCLUYE**\n"
		<< "CATEGORIA\t\tTIPO\t\tCODIGO\t\tCARACTERISTICAS\t\tPRECIO\n"
		<< lista->toString() << '\n'
		<< "Precio Total del Sistema: " << obtenerPrecio() << '\n'
		<< "----------------------------------------------\n";
	return s.str();
}

std::string Sistema::guardarDatos() {
	std::stringstream s;
	s << lista->guardarDatos() << DELIMITA_REGISTRO;
	return s.str();
}

bool Sistema::esSistema() const { return true; }

std::string Sistema::getTipo() const { throw new std::string("Un sistema no puede cumplir con esta función."); }
std::string Sistema::getModelo() const { throw new std::string("Un sistema no puede cumplir con esta función."); }
std::string Sistema::getCaracteristicas() const { throw new std::string("Un sistema no puede cumplir con esta función."); }

void Sistema::setTipo(std::string) { throw new std::string("Un sistema no puede cumplir con esta función."); }
void Sistema::setModelo(std::string){ throw new std::string("Un sistema no puede cumplir con esta función."); }
void Sistema::setCaracteristicas(std::string){ throw new std::string("Un sistema no puede cumplir con esta función."); }