#ifndef COMPONENTE_H
#define COMPONENTE_H
#include <sstream>

class Componente { //<<Abs>>
protected:
	std::string codigo; //Modelo
	double precio;

public:
	Componente() : codigo{ "" }, precio{ 0.0 } {}
	virtual ~Componente(){}
	virtual std::string toString() const = 0;
	virtual double obtenerPrecio() const = 0;
	virtual void agregar() = 0;

};


#endif // !COMPONENTE_H
