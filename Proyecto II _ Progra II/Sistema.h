#ifndef SISTEMA_H
#define SISTEMA_H
#include "Componente.h"
#include "PlantillaLista.h"

class Sistema: public Componente { //Composite
private:
	Lista<Componente>* lista;

public:
	Sistema(int);
	virtual ~Sistema();
	virtual void obtenerPrecio();
	virtual std::string toString();
	virtual void agregar(Componente*);

};


#endif // !SISTEMA_H
