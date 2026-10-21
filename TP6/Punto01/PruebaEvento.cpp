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
    eventoA.listarInformacion();
    cout << "---- Evento B ----" << endl; 
    eventoB.listarInformacion();
    cout << "---- Evento C ----" << endl;
    eventoC.listarInformacion();
    cout << "Asigno un responsable al evento A" << endl;
    eventoA.setResponsable("Pepito");
    eventoA.listarInformacion();
    cout << "Calculo el costo del eventoB: " << eventoB.calcularCosto() << endl;
    cout << "Destruyo el eventoB" << endl;
    eventoB.~Evento();

    return 0;
}