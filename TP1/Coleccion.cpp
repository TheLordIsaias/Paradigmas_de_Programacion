#include "Coleccion.h"

/* Operaciones Auxiliares */
bool reservarMemoria(Coleccion &V, unsigned int n){
    V.elementos = new item[n];
    if(V.elementos == NULL){
        return false;
    } else {
        return true;
    }
    
}

bool redimensionar(Coleccion &V){
    item *nuevoItem = new item[V.max + 5];
    if(nuevoItem != NULL){
        for (int i = 0; i < V.max; i++){
            nuevoItem[i] = V.elementos[i];
        }
        V.max +=5;
        delete(V.elementos);
        V.elementos = nuevoItem;
    } else {
        return false;
    }
    return true;
    
}

/* Operaciones propias del ADT COLECCION */
Coleccion crearColeccion(unsigned int n){
    Coleccion V;
    if(reservarMemoria(V, n)){
        V.max = n;
        V.indice = 0;
    } else {
        V.max = 0;
        V.indice = 0;
    }
    return V;
}

void agregar(Coleccion &V, item x){
    if(V.indice<V.max){
        V.elementos[V.indice] = x;
        V.indice++;
    } else {
        if(redimensionar(V)){
            V.elementos[V.indice] = x;
            V.indice++;
        }
    }
}

unsigned int capacidad(Coleccion V){
    return V.max;
}

item& elemento(Coleccion V, unsigned int p){
    if(p >= V.indice){
        return V.elementos[0];
    } else {
        return V.elementos[p];
    }
}

unsigned int cantidad(Coleccion V){
    return V.indice;
}

void borrar(Coleccion &V, unsigned int p){
    if(p < V.max){
        V.elementos[p] = indefinido;
    }
}

void borrar(Coleccion &V){
    V.indice = 0;
}

void destruir(Coleccion &V){
    delete V.elementos;
    V.max = 0;
    V.indice = 0;
}

bool operator==(Coleccion V1, Coleccion V2){
    if(V1.max != V2.max){
        return false;
    } else {
        for (int i = 0; i < V1.max; i++){
            if(V1.elementos[i] != V2.elementos[i]){
                return false;
            } else {
                return true;
            }
        }
        
    }
}