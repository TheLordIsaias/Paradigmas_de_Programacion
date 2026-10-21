#include <iostream>
#include "Libro.hpp"
#include "Revista.hpp"
using namespace std;

int main(){

    Libro libro;
    Revista revista;
    libro.Crear("123-45-651-76", "El principito", 2020, "Reynal & Hitchcock", "Antoine de Saint-Exupéry", true, 10000);
    revista.Crear("389-13-312-12", "Rolling Stone Argentina", 2021, 43, 2, "Cultura Rock", 15000);
    libro.ListarDatos();
    cout << "El codigo ISBN de libro es: " << libro.VerCodigoIsbn() << endl;
    if(libro.EsBestSeller()){
        cout << "El libro es Best Seller" << endl;
    }
    else{
        cout << "El libro no es Best Seller" << endl;
    }
    cout << "El precio de venta es: $" << libro.PrecioVenta() << endl;

    revista.ListarDatos();
    cout << "El codigo ISSN de la revista es: " << revista.VerCodigoIssn() << endl;
    cout << "El precio de venta es: $" << revista.PrecioVenta(2026) << endl;


    return 0;
}
