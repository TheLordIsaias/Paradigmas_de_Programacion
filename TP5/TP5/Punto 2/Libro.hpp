#include <iostream>
using namespace std;
class Libro{
    string codigoIsbn;
    string titulo;
    int anioEdicion;
    string nombreEditorial;
    string nombreAutor;
    bool bestSeller;
    double precioBase;
    
    public:
        void Crear(string codigoIsbn, string titulo, int anioEdicion, string nombreEditorial, string nombreAutor, bool bestSeller, double precioBase);
        void ListarDatos();
        string VerCodigoIsbn();
        bool EsBestSeller();
        double PrecioVenta();
};