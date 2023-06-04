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

#ifndef FECHA_H
#define FECHA_H
#include <sstream>
#include <Windows.h>

class Fecha {
private:
	int dia;
	int mes;
	int annio;

public:
	Fecha();
	Fecha(int, int, int);
	virtual ~Fecha();
	int getDia();
	void setDia(int);
	int getMes();
	void setMes(int);
	int getAnnio();
	void setAnnio(int);
	void actualizarPorActual();
	std::string toString();

};


#endif // !FECHA_H

