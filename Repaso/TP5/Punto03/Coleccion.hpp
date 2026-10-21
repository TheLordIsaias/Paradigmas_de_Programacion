#include <iostream>

typedef int item;
const int indefinido = -9999;

class Coleccion{
    private:
		item *elementos;
		int max;
		int indice;
	public:
		/* PROTOTIPO DE LAS OPERACIONES DEL ADT COLECCION */
		/* Operaciones Auxiliares */
			bool reservarMemoria(unsigned int n);
			bool redimensionar();
		/* Operaciones propias del ADT COLECCION */
			void crearColeccion(unsigned int n=10);
			void agregar(item x);
			unsigned int capacidad();
			item& elemento(unsigned int p);
			unsigned int cantidad();
			void borrar(unsigned int p);
			void borrar();
			void destruir();
			//bool operator==(Coleccion V1, Coleccion V2);

};







