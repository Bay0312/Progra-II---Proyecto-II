#ifndef EMPRESA_H
#define EMPRESA_H
#include "Cliente.h"
// Actualizado

class Empresa : public Cliente {
private:
	std::string cedJurid;
	std::string nomEmpresa;
public:
	Empresa(std::string, std::string, std::string, std::string);
	virtual ~Empresa();
	std::string getCedJurid();
	std::string getNomEmpresa();
	std::string getNomPais() override;
	std::string getCiudad() override;
	std::string toString() override;
	void update() override;
};

#endif // !EMPRESA_H
