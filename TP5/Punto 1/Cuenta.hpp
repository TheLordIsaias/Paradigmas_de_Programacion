#include <iostream>
using namespace std;
class Cuenta{
    int numero;
    long int dniTitular;
    double saldo;
    public:
        void Crear(int num, long int dniTitular, double saldo);
        bool Depositar(double monto);
        bool Extraer(double monto);
        double GetSaldo();
        void MostrarInformacion();

};