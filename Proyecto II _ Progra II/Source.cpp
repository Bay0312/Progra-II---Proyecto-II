#include <iostream>
#include <sstream>
#include "Sistema.h"
#include "Fuente.h"
#include "PlantillaLista.h"
#include "Parlante.h"
#include "Componente.h"
#include "Iterador.h"

int main() {
	Lista<Componente>* lista = new Lista<Componente>;

	Componente* c1 = new Fuente("Fuente", "Corsair", "RM850", "850W", 150);
	Componente* c2 = new Parlante("Parlante", "DDD", "Z3", "2.4", 250);
	Componente* c3 = new Fuente("Fuente", "Corsair", "RM9", "456W", 150);
	Componente* c4 = new Parlante("Parlante", "Mic", "Z43", "1.1", 150);
	Componente* c5 = new Parlante("Parlante", "Nvidia", "Z4", "3.1", 150);

	lista->insertarFinal(c1);
	lista->insertarFinal(c2);
	lista->insertarFinal(c3);
	lista->insertarFinal(c4);
	lista->insertarFinal(c5);

	std::cout << lista->toString();
	std::cout << "\n\n\n\n";

	IteradorLista<Componente>* ite2;
	ite2 = lista->getIterador();

	//Iterador<Componente>* ite1 = lista->getIterador2();
	std::cout << "---Ahora vamos a usar el iterador---\n";

	/*for (int i = 0; i < 5; i++) {
		std::cout << ite1->operator*() << '\n';
		ite1->operator++();
	}*/
	/*while (ite1 != nullptr) { //Se cae el programa porque llega a un nullptr, parece no identificar cuando es diferente de nullptr)
		std::cout << ite1->operator*();
		ite1->operator++();
		
	}*/

	
	return 0;
}