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

#include "Fecha.h"

//Constructores y Destructor
Fecha::Fecha() : dia{ 0 }, mes{ 0 }, annio{ 0 } {}

Fecha::Fecha(int _dia, int _mes, int _annio) : dia{ _dia }, mes{ _mes }, annio{ _annio } {}

Fecha::~Fecha() {}

//Setters y Getters
int Fecha::getDia() { return dia; }
void Fecha::setDia(int _dia) { dia = _dia; }

int Fecha::getMes() { return mes; }
void Fecha::setMes(int _mes) { mes = _mes; }

int Fecha::getAnnio() { return annio; }
void Fecha::setAnnio(int _annio) { annio = _annio; }

//Metodos varios
void Fecha::actualizarPorActual() { //Actualiza la fecha por la fecha actual del sistema.
	SYSTEMTIME st; //Systemtime contiene informacion detallada sobre la fecha actual
	GetLocalTime(&st); //GetLocalTime es una funcion de la API de windows.

	dia = st.wDay; //Devuelve el valor en numero entero, del dia del mes en el que se encuentra el sistema.
	mes = st.wMonth; // //Devuelve el valor en numero entero, del mes en el que se encuentra el sistema.
	annio = st.wYear; //Devuelve el valor en numero entero, del año en el que se encuentra el sistema.
}

//Metodos toString()
std::string Fecha::toString() {
	std::stringstream s;
	s << dia << "/" << mes << "/" << annio;
	return s.str();
}
