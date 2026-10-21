#include <iostream>
#include "Cuenta.hpp"
using namespace std;

bool transferir(Cuenta &cuentaA, Cuenta &cuentaB, double monto);

int main() {
    Cuenta cuentaA;
    cuentaA.Crear(1, 12345678, 100000);
    Cuenta cuentaB;
    cuentaB.Crear(2, 87654321, 50000);
    cout << "--------- Mostrando informacion precargada ---------" << endl;
    cout << "Cuenta A:" << endl;
    cuentaA.MostrarInformacion();
    cout << "Cuenta B:" << endl;
    cuentaB.MostrarInformacion();
    transferir(cuentaA, cuentaB, 10000);
    cout << "Mostrando informacion post transferencia de 10000 de la Cuenta A a la B" << endl;
    cout << "Cuenta A:" << endl;
    cuentaA.MostrarInformacion();
    cout << "Cuenta B:" << endl;
    cuentaB.MostrarInformacion();
    return 0;
}

bool transferir(Cuenta &cuentaA, Cuenta &cuentaB, double monto){
    if(monto > 0){
        if(cuentaA.GetSaldo() >= monto){
            if(!cuentaA.Extraer(monto)){
                return false;
            }
            if(!cuentaB.Depositar(monto)){
                return false;
            }
            return true;
            
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}