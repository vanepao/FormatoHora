//
// Created by Vanessa Paola Alvarado on 05/03/18.
//

#ifndef FH_FORMATOHORA_H
#define FH_FORMATOHORA_H
#include <iostream>

class FormatoHora {
private:
    int h,m,s,a,b;

    void validarFormato();

public:
    FormatoHora();
    FormatoHora (int horas, int minutos, int segundos);
    std::string to_String();
    bool validaHS(int horas);
    bool validaMS(int minutos);

    friend FormatoHora operator+ (const FormatoHora &h1, const FormatoHora &h2);
    friend FormatoHora operator- (const FormatoHora &h1, const FormatoHora &h2);
    friend bool operator< (const FormatoHora &h1, const FormatoHora &h2);
    friend bool operator> (const FormatoHora &h1, const FormatoHora &h2);
    friend bool operator<= (const FormatoHora &h1, const FormatoHora &h2);
    friend bool operator>= (const FormatoHora &h1, const FormatoHora &h2);
    friend bool operator== (const FormatoHora &h1, const FormatoHora &h2);
    friend bool operator!= (const FormatoHora &h1, const FormatoHora &h2);
};




#endif //FH_FORMATOHORA_H
