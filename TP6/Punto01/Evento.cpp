#include <iostream>
#include "Evento.hpp"

using namespace std;

int Evento::autoNumerico = 0;
const float Evento::IVA = 0.21;

Evento::Evento(){
    codigo = 0;
    nombre = "Sin nombre";
    responsable = "Sin responsable";
    disponible = false;
    precioBase = 0;
    tipoEvento = SinDefinir;
}


Evento::Evento(string nombre, string responsable, bool disponible, double precioBase ,TipoEvento tipoEvento){
    codigo = getAutonumerico();
    this->responsable = responsable;
    this->disponible = disponible;
    this->precioBase = precioBase;
    this->tipoEvento = tipoEvento;
}

Evento::Evento(const Evento& obj){
    codigo = obj.codigo;
    nombre = obj.nombre;
    responsable = obj.responsable;
    disponible = obj.disponible;
    precioBase = obj.precioBase;
    tipoEvento = obj.tipoEvento;
}

Evento::~Evento(){
    this->codigo = -1;
    this->nombre = "N/A";
    this->responsable = "N/A";
    this->disponible = false;
    this->precioBase = -1;
    this->tipoEvento = SinDefinir;
    cout << "El objeto de tipo Evento fue destruido " << this << endl;
}

int Evento::getAutonumerico(){
    autoNumerico++;
    return autoNumerico;
}

void Evento::setResponsable(string responsable){
    this->responsable = responsable;
}

void Evento::listarInformacion(){
    cout << "Codigo: " << codigo << " Nombre: " << nombre << " Responsable: " << responsable << " Disponible: " << disponible << " Precio Base: " << precioBase << " tipoEvento: " << tipoEvento << endl;
}

float Evento::calcularCosto(){
    float precio = 0;
    float costo = 0;
    if(disponible){
        if(tipoEvento == Internacional){
            precio = precioBase * 1.30;
        }
        else{
            precio = precioBase;
        }
        costo = precio * (1 + IVA);
    }
    return costo;
}