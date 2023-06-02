#pragma once
#include "Cliente.h"
// Actualizado

class Empresa : public Cliente {
private:
	string cedJurid;
	string nomEmpresa;
public:
	Empresa(string, string, string, string);
	virtual ~Empresa();
	string getCedJurid();
	string getNomEmpresa();
	string getNomPais() override;
	string getCiudad() override;
	string toString() override;
	void update() override;
};

