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

#ifndef SISTEMA_H
#define SISTEMA_H
#include "Componente.h"
#include "Fuente.h"
#include "Procesador.h"
#include "Parlante.h"
#include "PlantillaLista.h"

class Sistema: public Componente { //Composite
private:
	Lista<Componente>* lista;

public:
	//Constructor y Destructor
	Sistema();
	Sistema(const Sistema&);
	virtual ~Sistema();

	//Getter
	Lista<Componente>* getLista() const;

	//Metodos Varios
	virtual void agregar(Componente*);
	virtual double obtenerPrecio() const;
	virtual std::string toString() const;
	virtual std::string guardarDatos();
	virtual bool esSistema() const;

	virtual std::string getTipo() const;
	virtual std::string getModelo() const;
	virtual std::string getCaracteristicas() const;

	virtual void setTipo(std::string);
	virtual void setModelo(std::string);
	virtual void setCaracteristicas(std::string);
	
};


#endif // !SISTEMA_H
