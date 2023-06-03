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

