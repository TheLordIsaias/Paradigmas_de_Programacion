#include <iostream>

using namespace std;

enum TipoEvento{
    Nacional,
    Internacional,
    SinDefinir
};


class Evento{
    static int autoNumerico;
    int codigo;
    string nombre;
    string responsable;
    bool disponible;
    double precioBase;
    static const float IVA;
    TipoEvento tipoEvento;


    public:
    
    Evento();
    Evento(string nombre, string responsable, bool disponible, double precioBase ,TipoEvento tipoEvento);
    Evento(const Evento& obj);
    ~Evento();
    static int getAutonumerico();
    void setResponsable(string responsable);
    void listarInformacion();
    float calcularCosto();
};

