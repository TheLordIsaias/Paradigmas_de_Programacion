#include <iostream>
#include "Libro.hpp"

using namespace std;

void Libro::Crear(string codigoISBN, string titulo, int anioEdicion, string nombreEditorial, string nombreAutor, bool bestSeller, double precioBase)
{
    this->codigoISBN = codigoISBN;
    this->titulo = titulo;
    this->anioEdicion = anioEdicion;
    this->nombreEditorial = nombreEditorial;
    this->nombreAutor = nombreAutor;
    this->bestSeller = bestSeller;
    this->precioBase = precioBase;
}
void Libro::ListarDatos()
{
    cout << "---- Datos del Libro ----" << endl;
    cout << "Codigo ISBN: " << codigoISBN << endl 
         << "Titulo: " << titulo << endl 
         << "Anio de Edicion: " << anioEdicion << endl 
         << "Nombre de la Editorial: " << nombreEditorial << endl 
         << "Nombre del Autor: " << nombreAutor << endl 
         << "Best Seller: " << bestSeller << endl 
         << "Precio Base:" << precioBase << endl;
    cout << "-------------------------" << endl;
}
string Libro::VerCodigoISBN()
{
    return codigoISBN;
}
bool Libro::EsBestSeller()
{
    return bestSeller;
}
double Libro::PrecioVenta()
{
    double precioVenta;
    if(bestSeller)
    {
        precioVenta = precioBase * 1.31;
    }
    else
    {
        precioVenta = precioBase * 1.21;
    }

    return precioVenta;
}