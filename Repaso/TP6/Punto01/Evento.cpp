#include <iostream>
#include "Evento.hpp"

using namespace std;

int Evento::autonumerico = 0;
const float Evento::IVA = 0.21;


Evento::Evento()
{
    codigo = 0000;
    nombre = "N/A";
    responsable = "N/A";
    disponible = false;
    precioBase = -1;
    tipoEvento = SinDefinir;
}
Evento::Evento(string nombre, string responsable, bool disponible, double precioBase, TipoEvento tipoEvento)
{
    codigo = GetAutonumerico();
    this->nombre = nombre;
    this->responsable = responsable;
    this->disponible = disponible;
    this->precioBase = precioBase;
    this->tipoEvento = tipoEvento;
}
Evento::Evento(const Evento& e)
{
    codigo = e.codigo;
    nombre = e.nombre;
    responsable = e.responsable;
    disponible = e.disponible;
    precioBase = e.precioBase;
    tipoEvento = e.tipoEvento;
}
Evento::~Evento()
{
    codigo = 0000;
    nombre = "N/A";
    responsable = "N/A";
    disponible = false;
    precioBase = -1;
    tipoEvento = SinDefinir;
}

int Evento::GetAutonumerico()
{
    autonumerico++;
    return autonumerico;
}
void Evento::SetResponsable(string responsable)
{
    this->responsable = responsable;
}
void Evento::ListarInformacion()
{
    cout << "---- Mostrando informacion del Evento ----" << endl << "Codigo: " << codigo << endl << "Nombre: " << nombre << endl << "Responsable: " << responsable << endl << "Precio Base: $" << precioBase << endl << "Tipo de Evento: " << tipoEvento << endl;
}
float Evento::CalcularCosto()
{
    float precio = 0;
    float costo;
    if(disponible)
    {
        if(tipoEvento == "I")
        {
            precio = precioBase * 1.3;
        }
        else
        {
            precio = precioBase;
        }
        costo = precio * (1 + IVA);
    }
    return costo;
}