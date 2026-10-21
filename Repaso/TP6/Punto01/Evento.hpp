#include <iostream>

using namespace std;

enum TipoEvento
{
    Nacional,
    Internacional,
    SinDefinir
};

class Evento
{
    private:
        static int autonumerico;
        int codigo;
        string nombre;
        string responsable;
        bool disponible;
        double precioBase;
        static const float IVA;
        string tipoEvento;
    public:
        Evento();
        Evento(string nombre, string responsable, bool disponible, double precioBase, TipoEvento tipoEvento);
        Evento(const Evento& e);
        ~Evento();
        static int GetAutonumerico();
        void SetResponsable(string responsable);
        void ListarInformacion();
        float CalcularCosto();
};