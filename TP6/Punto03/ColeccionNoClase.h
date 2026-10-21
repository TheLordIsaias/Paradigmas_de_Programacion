#include <iostream>

typedef int item;
const int indefinido = -9999;

struct Coleccion{
    
    item *elementos;
    int max;
    int indice;

}typedef Colecion;


/* PROTOTIPO DE LAS OPERACIONES DEL ADT COLECCION */
/* Operaciones Auxiliares */
	bool reservarMemoria(Coleccion &V, unsigned int n);
	bool redimensionar(Coleccion &V);
/* Operaciones propias del ADT COLECCION */
	Coleccion crearColeccion(unsigned int n=10);
	void agregar(Coleccion &V, item x);
	unsigned int capacidad(Coleccion V);
	item& elemento(Coleccion V, unsigned int p);
	unsigned int cantidad(Coleccion V);
	void borrar(Coleccion &V, unsigned int p);
	void borrar(Coleccion &V);
	void destruir(Coleccion &V);
	bool operator==(Coleccion V1, Coleccion V2);




