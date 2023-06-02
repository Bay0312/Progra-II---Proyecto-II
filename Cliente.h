#pragma once
#include <iostream>
#include <sstream>
using namespace std;
// Actualizado

class Cliente {  // Observer
protected:
	string nomPais;
	string ciudad;
public:
	Cliente(string = " ", string = " ") {}
	virtual ~Cliente() {}
	virtual string toString() = 0;
	virtual string getNomPais() = 0;
	virtual string getCiudad() = 0;
	virtual void update() = 0;
};