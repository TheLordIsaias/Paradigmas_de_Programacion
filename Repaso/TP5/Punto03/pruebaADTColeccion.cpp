//============================================================================
// PARADIGMAS DE PROGRAMACION - 2026
// pruebaADTColeccion.cpp
//============================================================================

#include <iostream>

#include "Coleccion.hpp"

using namespace std;

/*
  PROTOTIPO DE LAS OPERACIONES DEL ADT COLECCION
	Operaciones Auxiliares
		bool reservarMemoria(Coleccion &V, unsigned int n);
		bool redimensionar(Coleccion &V);
	Operaciones propias del ADT COLECCION
		Coleccion crearColeccion(unsigned int n=10);
		void agregar(Coleccion &V, item x);
		unsigned int capacidad(Coleccion V);
		item& elemento(Coleccion V, unsigned int p);
		unsigned int cantidad(Coleccion V);
		void borrar(Coleccion &V, unsigned int p);
		void borrar(Coleccion &V);
		void destruir(Coleccion &V);
		bool operator==(Coleccion V1, Coleccion V2);
*/

// SOBRECARGA OPERADOR DE INSERCION DE FLUJO ( << )
ostream& operator<<(ostream& salida, Coleccion &V){

	for (int i = 0; i < V.cantidad(); i++){
		salida << V.elemento(i) << " ";
	}
	

	return salida;
}

// SOBRECARGA OPERADOR DE EXTRACCION DE FLUJO ( >> )
istream& operator>>(istream& entrada, Coleccion &V){
	int valor;
	for(unsigned int i=0;i<V.capacidad();i++){
		entrada>>valor;
		V.agregar(valor);
	}
	return entrada;
}

bool operator==(Coleccion V1, Coleccion V2){
    if(V1.capacidad() != V2.capacidad()){
        return false;
    } else {
        for (int i = 0; i < V1.capacidad(); i++){
            if(V1.elemento(i) != V2.elemento(i)){
                return false;
            } else {
                return true;
            }
        }
        
    }
}


int main() {
	const unsigned int MAX = 5;

	// Creo un objeto Coleccion con el constructor
	Coleccion F;
	F.crearColeccion(MAX);

	// Controlo si la coleccion fue creada correctamente con el constructor
	if(F.capacidad() == MAX && F.cantidad() ==0)
		cout<<"La coleccion se inicializo correctamente"<<endl;
	else
		if(F.capacidad() != MAX )
			cout<<"La coleccion NO se inicializo con la capacidad indicada"<<endl;
		else
			cout<<"La coleccion NO se inicializo correctamente con el indice en 0"<<endl;

	// Ingreso 5 items a la coleccion utilizando la función miembro agregar
	F.agregar(10);
	F.agregar(20);
	F.agregar(30);
	F.agregar(40);

	// Modifico 2 items de la coleccion utilizando la referencia al dato de la posición p que retorna la operación elemento
	F.elemento(0) = 222;
	F.elemento(2) = 555;

	cout<<"Cantidad de elementos de la coleccion"<<endl;
	cout<<F.cantidad()<<endl;

	cout<<"Contenido de la coleccion en la posición 3 (40): "<< F.elemento(3) <<endl;

	cout<<"Contenido de la coleccion en la posición 50 (como no existe la posición, retorna el elemento de la posición 0 que es 222): "<<F.elemento(50)<<endl;

	Coleccion G;
	G.crearColeccion(7);
	// Pruebo leer un objeto coleccion utilizando el operador de extracción de flujo sobrecargado (>>)
	cout<<"Ingrese los " << G.capacidad()<<" elementos de la coleccion"<<endl;
	cin>>G;

	// Escribo la capacidad de la coleccion
	cout<<"La capacidad de la coleccion es: "<< G.capacidad() <<endl;

	// Escribo la cantidad de elementos que contiene la coleccion
	cout<<"La cantidad de elementos de la coleccion es: "<< G.cantidad()<<endl;

	// Pruebo escribir por pantalla un objeto coleccion utilizando el operador de inserción de flujo (<<)
	cout<<"La coleccion contiene los siguientes elementos: "<<G<<endl;

	// Pruebo agregar un elemento en la coleccion que ya esta completa, ésta debería crecer dinamicamente
	G.agregar(1000);

	// Escribo la nueva capacidad de la coleccion y su contenido
	cout<<"La capacidad de la coleccion luego de redimensionar la misma es: "<<G.capacidad()<<endl;

	cout<<"Contenido de la coleccion luego de redimensionar la misma"<<endl;
	cout<<G<<endl;

	// Borro el elemento que se encuentra en la posición 2
	G.borrar(2);
	cout<<"Contenido de la coleccion en la posición 2 luego de borrar el elemento de esa posicion (indef): "<< G.elemento(2) <<endl;

	cout<<"Contenido de la coleccion luego de borrar el elemento de la posición 2"<<endl;
	cout<<G<<endl;

	// Borro todos los elementos de la coleccion
	G.borrar();

	cout<<"Contenido de la coleccion luego de borrar todos los elementos"<<endl;
	cout<<G<<endl;

	G.agregar(100);
	G.agregar(200);
	G.agregar(300);
	G.agregar(400);
	G.agregar(500);

	// Se espera mensaje: Las colecciones NO son iguales
	if(F == G)
		cout<<"Las colecciones son iguales"<<endl;
	else
		cout<<"Las colecciones NO son iguales"<<endl;


	F.destruir();
	G.destruir();

	cout<<"Capacidad de la coleccion F despues de destruirla (0): "<<F.capacidad()<<endl;
	cout<<"Capacidad de la coleccion G despues de destruirla (0): "<<G.capacidad()<<endl;

	return 0 ;
}

