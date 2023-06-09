#ifndef TIENDA_H
#define TIENDA_H
#include "Venta.h"
#include "Catalogo.h"

class Tienda {
private:
	Catalogo* catalogo;
	Lista<Venta>* listaVentas;

public:
	Tienda(Catalogo* = nullptr);
	virtual ~Tienda();
	Catalogo* getCatalogo();
	Lista<Venta>* getListaVentas();
	void agregarClienteCat(Cliente*); //Para suscribir los clientes al catalogo
	void agregarProductosCat(Componente*);
	std::string mostrarClientesCat();
	std::string mostrarProductosCat();
	void agregarVenta(Venta*);
	std::string mostrarVentas();
	std::string mostrarPDirecciones();
	double determinaCostoEnvio(int);
};



#endif // !TIENDA_H
