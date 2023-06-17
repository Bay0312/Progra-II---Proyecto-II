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

#include "Parlante.h"

//Constructores y Destructor
Parlante::Parlante() : Componente(), tipo{ "" }, caracteristicas{ "" } {}

Parlante::Parlante(std::string cat, std::string tip, std::string _model, std::string car, std::string cod, double pre)
	: tipo{ tip }, modelo{ _model }, caracteristicas{ car } {
	categoria = cat;
	codigo = cod;
	precio = pre;
}

Parlante::Parlante(const Parlante& copParlante) {
	this->categoria = copParlante.categoria;
	this->tipo = copParlante.tipo;
	this->caracteristicas = copParlante.caracteristicas;
	this->codigo = copParlante.codigo;
	this->precio = copParlante.precio;
	this->modelo = copParlante.modelo;
}

Parlante::~Parlante() {}

//Getters
std::string Parlante::getTipo() const { return tipo; }
std::string Parlante::getModelo() const { return modelo; }
std::string Parlante::getCaracteristicas() const { return caracteristicas; }

//Setters
void Parlante::setTipo(std::string componente) { this->tipo = componente; }
void Parlante::setModelo(std::string modelo) { this->modelo = modelo; }
void Parlante::setCaracteristicas(std::string caracteristicas) { this->caracteristicas = caracteristicas; }

//Metodos Varios
void Parlante::agregar(Componente* nan) { throw new std::string("No se supone que la clase parlante agregue."); } //La clase que agrega es el composite, por lo que aqui se lanza una excepcion.
double Parlante::obtenerPrecio() const { return precio; } //Se retorna solo el precio, dado que es un componente individual.

std::string Parlante::toString() const {
	std::stringstream s;
	s << categoria << "\t\t" << tipo << "\t\t" << codigo << "\t\t" << precio << "\t\t" << caracteristicas;
	return s.str();
}

std::string Parlante::guardarDatos(){
	std::stringstream s;
	s << 'A' << DELIMITA_CAMPO;
	s << categoria << DELIMITA_CAMPO; //DELIMITA_CAMPO sirve como separador entre cada dato.
	s << tipo << DELIMITA_CAMPO;
	s << modelo << DELIMITA_CAMPO;
	s << codigo << DELIMITA_CAMPO;
	s << caracteristicas << DELIMITA_CAMPO;
	s << precio << DELIMITA_CAMPO;
	return s.str();
}

bool Parlante::esSistema() const { return false; }