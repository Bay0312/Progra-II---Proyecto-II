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

#ifndef EMPRESA_H
#define EMPRESA_H
#include "Cliente.h"
// Actualizado

class Empresa : public Cliente {
public:
	Empresa(std::string, std::string, std::string, std::string, Catalogo* = nullptr);
	virtual ~Empresa();
	virtual bool esEmpresa();
	std::string toString() override;
	virtual std::string guardarDatos() override;
	void update() override;
};

#endif // !EMPRESA_H
