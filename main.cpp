#include <iostream>
#include "FormatoHora.h"
int main() {
    FormatoHora entrada(12,45,32); //10,40,60
    FormatoHora salida(20,59,59); //11,30,33
    FormatoHora r;
    bool rb;

    salida==entrada? rb=true: rb = false;
    std::cout<<"salida == entrada "
             << salida.to_String()
             <<" == "<<entrada.to_String()
             <<" resultado= "<< rb<<"\n";

    r=entrada-salida;
    std::cout<<r.to_String();
}