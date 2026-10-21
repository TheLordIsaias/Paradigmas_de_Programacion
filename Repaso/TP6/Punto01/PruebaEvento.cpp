#include <iostream>
#include "Evento.hpp"

using namespace std;

int main (){

    cout << "Creo un eventoA usando el constructor por defecto" << endl;
    Evento eventoA;
    cout << "Creo un eventoB usando el constructor con parametros" << endl;
    Evento eventoB("Evento B", "Isaias Ruiz", true, 10000, Nacional);
    cout << "Creo un eventoC usando el constructor copia" << endl;
    Evento eventoC(eventoB);
    cout << "Muestro la informacion de los eventos: " << "---- Evento A ----" << endl;
    eventoA.ListarInformacion();
    cout << "---- Evento B ----" << endl; 
    eventoB.ListarInformacion();
    cout << "---- Evento C ----" << endl;
    eventoC.ListarInformacion();
    cout << "Asigno un responsable al evento A" << endl;
    eventoA.SetResponsable("Pepito");
    eventoA.ListarInformacion();
    cout << "Calculo el costo del eventoB: " << eventoB.CalcularCosto() << endl;
    cout << "Destruyo el eventoB" << endl;
    eventoB.~Evento();

    return 0;
}