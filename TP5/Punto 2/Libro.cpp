#include <iostream>
#include "Libro.hpp"
using namespace std;


void Libro::Crear(string codigoIsbn, string titulo, int anioEdicion, string nombreEditorial, string nombreAutor, bool bestSeller, double precioBase){
    this->codigoIsbn = codigoIsbn;
    this->titulo = titulo;
    this->anioEdicion = anioEdicion;
    this->nombreEditorial = nombreEditorial;
    this->nombreAutor = nombreAutor;
    this->bestSeller = bestSeller;
    this->precioBase = precioBase;
}
void Libro::ListarDatos(){
    cout << "---- Datos del Libro ----" << endl;
    cout << "Codigo ISBN: " << codigoIsbn << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Anio Edicion: " << anioEdicion << endl;
    cout << "Editorial: " << nombreEditorial << endl;
    cout << "Autor: " << nombreAutor << endl;
    cout << "Es Bestseller: " << bestSeller << endl;
    cout << "Precio base: " << precioBase << endl;
}
string Libro::VerCodigoIsbn(){
    return codigoIsbn;
}
bool Libro::EsBestSeller(){
    return bestSeller;
}
double Libro::PrecioVenta(){
    if(bestSeller){
        return precioBase * 1.31;
    }
    else{
        return precioBase * 1.21;
    }
}