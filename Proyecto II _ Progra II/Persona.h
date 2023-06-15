/* --------------------------------------------------------------------
*
* EIF204 Programación 2
* Proyecto 2
*
* 4-0254-0670 David Calvo H. grupo 02
* 7-0300-0234 Bayron Vega A. grupo 03
*
* -------------------------------------------------------------------
*/

#ifndef PERSONA_H
#define PERSONA_H
#include "Cliente.h"
// Actualizado

class Persona : public Cliente {
private:
	std::string correo;
	std::string nacionalidad;

public:
	Persona(std::string, std::string, std::string, std::string, std::string, std::string, Catalogo* = nullptr);
	virtual ~Persona();
	std::string getCorreo();
	std::string getNacionalidad();
	virtual bool esEmpresa();
	std::string toString() override;
	virtual std::string guardarDatos() override;
	void update() override;
};


#endif // !PERSONA_H
