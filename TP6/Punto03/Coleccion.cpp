#include <iostream>
#include "Coleccion.hpp"
using namespace std;

/* Operaciones Auxiliares */

bool Coleccion::reservarMemoria(unsigned int n){
    elementos = new item[n];
    return true;   
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
Coleccion::Coleccion(unsigned int n){
    if(reservarMemoria(n)){
        max = n;
        indice = 0;
    } else {
        max = 0;
        indice = 0;
    }
}

Coleccion::Coleccion(const Coleccion &c){
    max = c.max;
    indice = c.indice;
    reservarMemoria(max);
    for (int i = 0; i <= indice; i++)
    {
        elementos[i] = c.elementos[i];
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

Coleccion::~Coleccion(){
    delete elementos;
    max = 0;
    indice = 0;
}

bool Coleccion::operator==(Coleccion V2){
    if(capacidad() != V2.capacidad()){
        return false;
    } else {
        for (int i = 0; i < capacidad(); i++){
            if(elemento(i) != V2.elemento(i)){
                return false;
            }
        }
        return true;
    }
}