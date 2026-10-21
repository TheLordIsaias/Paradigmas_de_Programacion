#include <iostream>
#include "Cuenta.hpp"

using namespace std;

bool Transferir(Cuenta &cuentaA, Cuenta &cuentaB, double monto)
{
    if(monto > 0 && cuentaA.GetSaldo()<monto)
    {
        return false;
    }
    else
    {
        if(cuentaA.Extraer(monto))
        {
            if(cuentaB.Depositar(monto))
            {
                return true;
            }
            else
            {
                cuentaA.Depositar(monto);
                return false;
            }
            
        }
        else
        {
            return false;
        }
        
    }
}

int main()
{
    cout << "Creo una cuenta A con ID 1 y un saldo de 100000 a nombre del DNI 12345678" << endl;
    Cuenta cuentaA;
    cuentaA.Crear(1, 12345678, 100000);
    cout << "Creo una cuenta B con ID 2 y un saldo de 50000 a nombre del DNI 87654321" << endl;
    Cuenta cuentaB;
    cuentaB.Crear(2, 87654321, 50000);
    cout << "Muestro informacion de las cuentas: " << endl; 
    cout << "Cuenta A: " << endl; 
    cuentaA.MostrarInformacion();
    cout << "Cuenta B: " << endl;
    cuentaB.MostrarInformacion();
    cout << "Transfiero 50000 de la Cuenta A a la Cuenta B" << endl;
    if(Transferir(cuentaA, cuentaB, 50000))
    {
        cout << "Se transfirio el dinero con exito!" << endl;
    }
    else
    {
        cout << "Hubo un error en la transferencia" << endl;
    }
    cout << "Muestro informacion de las cuentas: " << endl; 
    cout << "Cuenta A: " << endl; 
    cuentaA.MostrarInformacion();
    cout << "Cuenta B: " << endl;
    cuentaB.MostrarInformacion();
    return 0;
}