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
#include "PlantillaLista.h"

class Sistema: public Componente { //Composite
private:
	Lista<Componente>* lista;

public:
	//Constructor y Destructor
	Sistema();
	virtual ~Sistema();

	//Metodos Varios
	virtual void agregar(Componente*);
	virtual void obtenerPrecio();
	virtual std::string toString();
	
};


#endif // !SISTEMA_H
