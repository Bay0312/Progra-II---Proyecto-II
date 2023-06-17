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

#ifndef COMPONENTE_H
#define COMPONENTE_H
#include <sstream>
#define DELIMITA_CAMPO ';' 
#define DELIMITA_REGISTRO '\n'

class Componente { //<<Abs>>
protected:
	std::string codigo;
	std::string categoria;
	double precio;

public:
	Componente() : codigo{ "" }, categoria{ "" }, precio{ 0.0 } {}
	virtual ~Componente(){}
	virtual std::string getId() const { return codigo; } //Se le llama de esta forma para que sea mas generico.
	virtual void setCodigo(std::string _codigo) { codigo = _codigo; }
	virtual void setPrecio(double _precio) { precio = _precio; }
	virtual double getPrecio() const { return precio; }
	virtual std::string getCategoria() const { return categoria; }
	virtual void setCategoria(std::string _categoria) { categoria = _categoria; }
	
	virtual std::string getTipo() const = 0;
	virtual std::string getModelo() const = 0;
	virtual std::string getCaracteristicas() const = 0;

	virtual void setTipo(std::string) = 0;
	virtual void setModelo(std::string) = 0;
	virtual void setCaracteristicas(std::string) = 0;

	virtual void agregar(Componente*) = 0;
	virtual double obtenerPrecio() const = 0;
	virtual std::string toString() const = 0;
	virtual std::string guardarDatos() = 0;
	virtual bool esSistema() const = 0;
	
};


#endif // !COMPONENTE_H
