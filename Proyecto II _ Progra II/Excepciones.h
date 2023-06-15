#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H
#include <sstream>
#include <exception>

class Excepcion {
public:
	virtual std::string toString() = 0;
};

class ExcepcionValor: public Excepcion {
public:
	std::string toString();
};

class ExcepcionDeExistencia: public Excepcion {
public:
	std::string toString();
};

#endif // !EXCEPCIONES_H
