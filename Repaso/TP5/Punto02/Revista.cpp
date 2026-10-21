#include <iostream>
#include "Revista.hpp"

using namespace std;


void Revista::Crear(string codigoISSN, string titulo, int anioEdicion, int numero, int volumen, string campoTematico, double precioBase)
{
    this->codigoISSN = codigoISSN;
    this->titulo = titulo;
    this->anioEdicion = anioEdicion;
    this->numero = numero;
    this->volumen = volumen;
    this->campoTematico = campoTematico;
    this->precioBase = precioBase;
}
double Revista::PrecioVenta(int anioActual)
{
    double precioFinal;
    if((anioActual - anioEdicion)>=5)
    {
        precioFinal = precioBase * 1.31;
    }
    else
    {
        precioFinal = precioBase *1.21;
    }
    return precioFinal;
}