#include "Coleccion.hpp"

/* Operaciones Auxiliares */
bool Coleccion::reservarMemoria(unsigned int n){
    elementos = new item[n];
    if(elementos == NULL){
        return false;
    } else {
        return true;
    }
    
}

bool Coleccion::redimensionar(){
    item *nuevoItem = new item[max + 5];
    if(nuevoItem != NULL){
        for (int i = 0; i < max; i++){
            nuevoItem[i] = elementos[i];
        }
        max +=5;
        delete(elementos);
        elementos = nuevoItem;
    } else {
        return false;
    }
    return true;
    
}

/* Operaciones propias del ADT COLECCION */
void Coleccion::crearColeccion(unsigned int n){
    if(reservarMemoria(n)){
        max = n;
        indice = 0;
    } else {
        max = 0;
        indice = 0;
    }
}

void Coleccion::agregar(item x){
    if(indice<max){
        elementos[indice] = x;
        indice++;
    } else {
        if(redimensionar()){
            elementos[indice] = x;
            indice++;
        }
    }
}

unsigned int Coleccion::capacidad(){
    return max;
}

item& Coleccion::elemento(unsigned int p){
    if(p >= indice){
        return elementos[0];
    } else {
        return elementos[p];
    }
}

unsigned int Coleccion::cantidad(){
    return indice;
}

void Coleccion::borrar(unsigned int p){
    if(p < max){
        elementos[p] = indefinido;
    }
}

void Coleccion::borrar(){
    indice = 0;
}

void Coleccion::destruir(){
    delete elementos;
    max = 0;
    indice = 0;
}

/*
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
*/