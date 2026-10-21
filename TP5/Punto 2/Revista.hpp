#include <iostream>
using namespace std;
class Revista{
    string codigoIssn;
    string titulo;
    int anioEdicion;
    int numero;
    int volumen;
    string campoTematico;
    double precioBase;
    
    public:
        void Crear(string codigoIssn, string titulo, int anioEdicion, int numero, int volumen, string campoTematico, double precioBase);
        void ListarDatos();
        string VerCodigoIssn();
        double PrecioVenta(int anioActual);
};