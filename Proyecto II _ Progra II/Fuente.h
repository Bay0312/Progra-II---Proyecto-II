#ifndef FUENTE_H
#define FUENTE_H
#include "Componente.h"

class Fuente: public Componente {
private:
	std::string categoria;
	std::string tipo;
	std::string caracteristicas;

public:
	Fuente();
	Fuente(std::string, std::string, std::string, std::string, double);
	virtual ~Fuente();
	virtual std::string toString() const;
	virtual double obtenerPrecio() const;
	virtual void agregar();
	std::string getCategoria() const;
	std::string getTipo() const;
	std::string getCaracteristicas() const;
	void setCategoria(std::string);
	void setTipo(std::string);
	void setCaracteristicas(std::string);

};

#endif // !FUENTE_H
