#include <iostream>

using namespace std;

class Revista
{
    private:
        string codigoISSN;
        string titulo;
        int anioEdicion;
        int numero;
        int volumen;
        string campoTematico;
        double precioBase;
    
    public:
        void Crear(string codigoISSN, string titulo, int anioEdicion, int numero, int volumen, string campoTematico, double precioBase);
        double PrecioVenta(int anioActual);
};