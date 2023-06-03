#ifndef PERSONA_H
#define PERSONA_H
#include "Cliente.h"
// Actualizado

class Persona : public Cliente {
private:
	std::string id;
	std::string correo;
	std::string nacionalidad;
	std::string nombre;
public:
	Persona(std::string, std::string, std::string, std::string, std::string, std::string);
	virtual ~Persona();
	std::string getId();
	std::string getCorreo();
	std::string getNacionalidad();
	std::string getNombre();
	std::string getNomPais() override;
	std::string getCiudad() override;
	std::string toString() override;
	void update() override;
};


#endif // !PERSONA_H
