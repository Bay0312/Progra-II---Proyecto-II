#ifndef PROCESADOR_H
#define PROCESADOR_H
#include "Componente.h"

class Procesador : public Componente {
private:
	std::string categoria;
	std::string tipo;
	std::string caracteristicas;

public:
	Procesador();
	Procesador(std::string, std::string, std::string, std::string, double);
	virtual ~Procesador();
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

#endif // !PROCESADOR_H
