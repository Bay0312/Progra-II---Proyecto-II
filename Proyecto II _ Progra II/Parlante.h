#ifndef PARLANTE_H
#define PARLANTE_H
#include "Componente.h"

class Parlante : public Componente {
private:
	std::string categoria;
	std::string tipo;
	std::string caracteristicas;

public:
	Parlante();
	Parlante(std::string, std::string, std::string, std::string, double);
	virtual ~Parlante();
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

#endif // !PARLANTE_H
