#include <iostream>
#include "Cuenta.hpp"

using namespace std;

void Cuenta::Crear(int num, long int titular, double monto){
    numero = num;
    dniTitular = titular;
    saldo = monto;
}
bool Cuenta::Depositar(double monto)
{
    if(monto > 0)
    {
        saldo = saldo + monto;
        return true;
    }
    return false;
}
bool Cuenta::Extraer(double monto)
{
    if(saldo < monto)
    {
        return false;
    }
    else
    {
        saldo = saldo - monto;
        return true;
    }
}
double Cuenta::GetSaldo()
{
    return saldo;
}
void Cuenta::MostrarInformacion()
{
    cout << "Numero de Cuenta: " << numero << ". DNI del Titular: " << dniTitular << ". Saldo: " << saldo << endl;
}