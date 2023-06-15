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

#include "Procesador.h"

//Constructores y Destructor
Procesador::Procesador() : Componente(), tipo{ "" }, caracteristicas{ "" } {}

Procesador::Procesador(std::string cat, std::string tip, std::string model, std::string car, std::string cod, double pre) 
	: tipo{ tip }, modelo{model}, caracteristicas{ car } {
	categoria = cat;
	codigo = cod;
	precio = pre;
}

Procesador::Procesador(const Procesador& copProcesador) {
	this->categoria = copProcesador.categoria;
	this->tipo = copProcesador.tipo;
	this->caracteristicas = copProcesador.caracteristicas;
	this->codigo = copProcesador.codigo;
	this->precio = copProcesador.precio;
}

Procesador::~Procesador() {}

//Getters
std::string Procesador::getTipo() const { return tipo; }
std::string Procesador::getModelo() const { return modelo; }
std::string Procesador::getCaracteristicas() const { return caracteristicas; }

//Setters
void Procesador::setTipo(std::string componente) { this->tipo = componente; }
void Procesador::setModelo(std::string modelo) { this->modelo = modelo; }
void Procesador::setCaracteristicas(std::string caracteristicas) { this->caracteristicas = caracteristicas; }

//Metodos Varios
void Procesador::agregar(Componente* nan) { throw new std::string("No se supone que la clase procesador agregue."); } //La clase que agrega es el composite, por lo que aqui se lanza una excepcion.
double Procesador::obtenerPrecio() const { return precio; } //Se retorna solo el precio, dado que es un componente individual.

std::string Procesador::toString() const {
	std::stringstream s;
	s << categoria << "\t\t" << tipo << "\t\t" << codigo << "\t\t" << caracteristicas << "\t\t" << precio;
	return s.str();
}

std::string Procesador::guardarDatos() {
	std::stringstream s;
	s << categoria << DELIMITA_CAMPO; //DELIMITA_CAMPO sirve como separador entre cada dato.
	s << tipo << DELIMITA_CAMPO;
	s << codigo << DELIMITA_CAMPO;
	s << caracteristicas << DELIMITA_CAMPO;
	s << precio << DELIMITA_REGISTRO; //DELIMITA_REGISTRO sirve como separador entre cada registro.
	return s.str();
}

bool Procesador::esSistema() const { return false; }

