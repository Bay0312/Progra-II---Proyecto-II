#pragma once
#include "Cliente.h"
// Actualizado

class Persona : public Cliente {
private:
	string id;
	string correo;
	string nacionalidad;
	string nombre;
public:
	Persona(string, string, string, string, string, string);
	virtual ~Persona();
	string getId();
	string getCorreo();
	string getNacionalidad();
	string getNombre();
	string getNomPais() override;
	string getCiudad() override;
	string toString() override;
	void update() override;
};

