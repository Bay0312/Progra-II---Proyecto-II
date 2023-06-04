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
Procesador::Procesador() : Componente(), categoria{ "" }, tipo{ "" }, caracteristicas{ "" } {}

Procesador::Procesador(std::string cat, std::string tip, std::string car, std::string cod, double pre) : categoria{ cat }, tipo{ tip }, caracteristicas{ car } {
	codigo = cod;
	precio = pre;
}

Procesador::~Procesador() {}

//Getters
std::string Procesador::getCategoria() const { return categoria; }
std::string Procesador::getTipo() const { return tipo; }
std::string Procesador::getCaracteristicas() const { return caracteristicas; }

//Setters
void Procesador::setCategoria(std::string categoria) { this->categoria = categoria; }
void Procesador::setTipo(std::string componente) { this->tipo = componente; }
void Procesador::setCaracteristicas(std::string caracteristicas) { this->caracteristicas = caracteristicas; }

//Metodos Varios
void Procesador::agregar() { throw new std::string("No se supone que la clase procesador agregue."); } //La clase que agrega es el composite, por lo que aqui se lanza una excepcion.
double Procesador::obtenerPrecio() const { return precio; } //Se retorna solo el precio, dado que es un componente individual.

std::string Procesador::toString() const {
	std::stringstream s;
	s << "Procesador: " << codigo << " " << precio << " " << categoria << " " << tipo << " " << caracteristicas << std::endl;
	return s.str();
}



