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
Fuente::Fuente() : Componente(), tipo{ "" }, caracteristicas{ "" } {}

Fuente::Fuente(std::string cat, std::string tip, std::string _model, std::string car, std::string cod, double pre) 
	: tipo{ tip }, modelo{ _model }, caracteristicas{ car } {
	categoria = cat;
	codigo = cod;
	precio = pre;
}

Fuente::Fuente(const Fuente& copFuente) {
	this->categoria = copFuente.categoria;
	this->tipo = copFuente.tipo;
	this->caracteristicas = copFuente.caracteristicas;
	this->codigo = copFuente.codigo;
	this->precio = copFuente.precio;
	this->modelo = copFuente.modelo;
}

Fuente::~Fuente() {}

//Getters
std::string Fuente::getTipo() const { return tipo; }
std::string Fuente::getModelo() const { return modelo; }
std::string Fuente::getCaracteristicas() const { return caracteristicas; }

//Setters
void Fuente::setTipo(std::string componente) { this->tipo = componente; }
void Fuente::setModelo(std::string modelo) { this->modelo = modelo; }
void Fuente::setCaracteristicas(std::string caracteristicas) { this->caracteristicas = caracteristicas; }

//Metodos Varios
void Fuente::agregar(Componente* nan) { throw new std::string("No se supone que la clase fuente agregue nada."); } //La clase que agrega es el composite, por lo que aqui se lanza una excepcion.
double Fuente::obtenerPrecio() const { return precio; } //Se retorna solo el precio, dado que es un componente individual.

std::string Fuente::toString() const {
	std::stringstream s;
	s << categoria << "\t\t" << tipo << "\t\t" << codigo << "\t\t" << precio << "\t\t" << caracteristicas;
	return s.str();
}

std::string Fuente::guardarDatos() {
	std::stringstream s;
	s << 'F' << DELIMITA_CAMPO;
	s << categoria << DELIMITA_CAMPO; //DELIMITA_CAMPO sirve como separador entre cada dato.
	s << tipo << DELIMITA_CAMPO;
	s << modelo << DELIMITA_CAMPO;
	s << codigo << DELIMITA_CAMPO;
	s << caracteristicas << DELIMITA_CAMPO;
	s << precio << DELIMITA_CAMPO;
	return s.str();
}

bool Fuente::esSistema() const { return false; }