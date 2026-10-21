#include <iostream>

using namespace std;

class Libro
{
    private:
        string codigoISBN;
        string titulo;
        int anioEdicion;
        string nombreEditorial;
        string nombreAutor;
        bool bestSeller;
        double precioBase;
    public:
        void Crear(string codigoISBN, string titulo, int anioEdicion, string nombreEditorial, string nombreAutor, bool bestSeller, double precioBase);
        void ListarDatos();
        string VerCodigoISBN();
        bool EsBestSeller();
        double PrecioVenta();
};