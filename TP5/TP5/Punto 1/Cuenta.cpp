#include <iostream>
#include "Cuenta.hpp"
using namespace std;

void Cuenta::Crear(int num, long int dniTitular, double saldo){
    numero = num;
    this->dniTitular = dniTitular;
    if(saldo >= 0){
        this->saldo = saldo;
    }
    else
    {
        this->saldo = 0;
    }
}
bool Cuenta::Depositar(double monto){
    if(monto > 0){
        saldo += monto;
        return true;
    }
    else
    {
        return false;
    }
}
bool Cuenta::Extraer(double monto){
    if(monto >= 0 && (saldo - monto) >= 0){
        saldo -= monto;
        return true;
    }
    else
    {
        return false;
    }
}

double Cuenta::GetSaldo(){
    return saldo;
}

void Cuenta::MostrarInformacion(){
    cout << "---- Mostrando informacion de la Cuenta ----" << endl;
    cout << "Numero de Cuenta: " << numero <<  endl;
    cout << "DNI Titular: " << dniTitular << endl;
    cout << "Saldo: $" << saldo << endl;
}

