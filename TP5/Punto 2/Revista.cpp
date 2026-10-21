#include <iostream>
#include "Revista.hpp"
using namespace std;

void Revista::Crear(string codigoIssn, string titulo, int anioEdicion, int numero, int volumen, string campoTematico, double precioBase){
    this->codigoIssn = codigoIssn;
    this->titulo = titulo;
    this->anioEdicion = anioEdicion;
    this->numero = numero;
    this->volumen = volumen;
    this->campoTematico = campoTematico;
    this->precioBase = precioBase;
}

void Revista::ListarDatos(){
    cout << "---- Datos de la Revista ----" << endl;
    cout << "Codigo ISBN: " << codigoIssn << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Anio Edicion: " << anioEdicion << endl;
    cout << "Numero: " << numero << endl;
    cout << "Volumen: " << volumen << endl;
    cout << "Campo Tematico: " << campoTematico << endl;
    cout << "Precio base: " << precioBase << endl;
}
string Revista::VerCodigoIssn(){
    return codigoIssn;
}

double Revista::PrecioVenta(int anioActual){
    if((anioEdicion - anioActual)>5){
        return precioBase * 1.31;
    }
    else{
        return precioBase * 1.21;
    }
}