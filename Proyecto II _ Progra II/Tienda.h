#ifndef TIENDA_H
#define TIENDA_H
#include "VentaEnLinea.h"
#include "VentaDirecta.h"
#include "Catalogo.h"
#include "Persona.h"
#include "Empresa.h"

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
	std::string reporteVentas();
	std::string reporteMasVendido();
	bool hayCompParaSistema();
	std::string facturar(Venta*);

	std::string guardarDatos();
	void cargarDatos(std::string guardar[50], int);
	void ayudaCargaComponente(std::string guardar[50], bool);
};



#endif // !TIENDA_H
