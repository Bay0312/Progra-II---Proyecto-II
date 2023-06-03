#ifndef CLIENTE_H
#define CLIENTE_H
#include <sstream>
#include <iostream>
// Actualizado

class Cliente {  // Observer
protected:
	std::string nomPais;
	std::string ciudad;
public:
	Cliente(std::string = " ", std::string = " ") {}
	virtual ~Cliente() {}
	virtual std::string toString() = 0;
	virtual std::string getNomPais() = 0;
	virtual std::string getCiudad() = 0;
	virtual void update() = 0;
};

#endif // !CLIENTE_H
