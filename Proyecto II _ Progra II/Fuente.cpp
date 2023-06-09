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

#include "Fuente.h"

//Constructores y Destructor
Fuente::Fuente() : Componente(), categoria{ "" }, tipo{ "" }, caracteristicas{ "" } {}

Fuente::Fuente(std::string cat, std::string tip, std::string car, std::string cod, double pre) : categoria{ cat }, tipo{ tip }, caracteristicas{ car } {
	codigo = cod;
	precio = pre;
}

Fuente::Fuente(const Fuente& copFuente) {
	this->categoria = copFuente.categoria;
	this->tipo = copFuente.tipo;
	this->caracteristicas = copFuente.caracteristicas;
	this->codigo = copFuente.codigo;
	this->precio = copFuente.precio;
}

Fuente::~Fuente() {}

//Getters
std::string Fuente::getCategoria() const { return categoria; }
std::string Fuente::getTipo() const { return tipo; }
std::string Fuente::getCaracteristicas() const { return caracteristicas; }

//Setters
void Fuente::setCategoria(std::string categoria) { this->categoria = categoria; }
void Fuente::setTipo(std::string componente) { this->tipo = componente; }
void Fuente::setCaracteristicas(std::string caracteristicas) { this->caracteristicas = caracteristicas; }

//Metodos Varios
void Fuente::agregar(Componente* nan) { throw new std::string("No se supone que la clase fuente agregue nada."); } //La clase que agrega es el composite, por lo que aqui se lanza una excepcion.
double Fuente::obtenerPrecio() const { return precio; } //Se retorna solo el precio, dado que es un componente individual.

std::string Fuente::toString() const {
	std::stringstream s;
	s << categoria << '\t' << tipo << '\t' << codigo << '\t' << caracteristicas << '\t' << precio;
	return s.str();
}

bool Fuente::esSistema() const { return false; }