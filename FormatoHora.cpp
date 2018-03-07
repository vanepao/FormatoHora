//
// Created by Vanessa Paola Alvarado on 05/03/18.
//

#include "FormatoHora.h"
#include <iostream>
FormatoHora::FormatoHora() {
    h=m=s=0;
}
FormatoHora::FormatoHora(int horas, int minutos, int segundos) {
    //Constructor
    validaHS(horas)?this->h=horas:this->h=0;
    validaMS(minutos)?this->m=minutos:this->m=0;
    validaMS(segundos)?this->s=segundos:this->s=0;
}

void FormatoHora::validarFormato() {
    /**
     * REGLAS DE FORMATO
     * Cuando minutos y segundos excedan las 60 unidades,
     * incrementa la siguiente unidad en uno y elimina el excedente
     */
   // std::cout<<s<<"\n";
    //std::cout<<m<<"\n";
    //std::cout<<h<<"\n";
   // int a=m++;
    //int b= a+m;

    //caso 1
    this->s > 59? this->s=this->s - 60, this->m++: this->s;
    this->m > 59? this->m=this->m-60, this->h++ :this->m;

    //caso 2
    this->s > 59? this->s=this->s - 60, this->m++: this->s;
     m++;
    this->m > 59? this->m=this->m-60, this->h++ :this->m;
                                //this->m++,


    //Si segundos son negativos, suma 60 segundos
    this->s<0? this->s+=60, this->m-=1: this->s;
    //Si minutos son negativos, suma 60 minutos
    this->m<0? this->m+=60, this->h-=1: this->m;
    //Si horas son negativas
    this->h<0? this->h+=24: this->h;

    //std::cout<<s<<"\n";
    //std::cout<<m<<"\n";
    //std::cout<<h<<"\n";
}

std::string FormatoHora::to_String() {
    /**
     * Devuelve una cadena en formato HH:MM::SS
     */
    return std::to_string(h) + ":" + std::to_string(m)+":"+ std::to_string(s);
}

bool FormatoHora::validaHS(int horas) {
    /**
     * Si horas menor a 23 y mayor a 0, regresa TRUE, de otra forma FALSE
     */
    return 23 > horas > 0;
}

bool FormatoHora::validaMS(int ms) {
    /**
     * Si minutos o segundos menor a 59 y mayor a 0 regresa TRUE,
     * de otra forma FALSE
     */
    return 59 > ms > 0;
}

FormatoHora operator+ (const FormatoHora &h1, const FormatoHora &h2){
    //Suma horas, minutos y segundos, de cada parámetro de tipo FormatoHora
    FormatoHora r (h1.h+h2.h,h1.m+h2.m,h1.s+h2.s);
    r.validarFormato();
    return r;
}

FormatoHora operator- (const FormatoHora &h1, const FormatoHora &h2){
    //Suma horas, minutos y segundos, de cada parámetro de tipo FormatoHora

    FormatoHora r (h1.h-h2.h,h1.m-h2.m,h1.s-h2.s);
    r.validarFormato();
    return r;
}

bool operator< (const FormatoHora &h1, const FormatoHora &h2){
    //Suma horas, minutos y segundos, de cada parámetro de tipo FormatoHora
    return h1.h < h2.h;
}

bool operator> (const FormatoHora &h1, const FormatoHora &h2){
    //Suma horas, minutos y segundos, de cada parámetro de tipo FormatoHora
    return h1.h > h2.h;
}

bool operator<= (const FormatoHora &h1, const FormatoHora &h2){
    /**
     * Si horas minutos y segundos de los parámetros h1 y h2 son menores o iguales,
     * devuelve true
     */
    int ub1= h1.h*60*60+h1.m*60+h1.s;
    int ub2= h2.h*60*60+h2.h*60+h2.s;
    return ub1<=ub2;
}

//OTRA MANERA:
    //if (ub1<=ub2){
    //return true;}
    //else{ return false;}



bool operator>= (const FormatoHora &h1, const FormatoHora &h2){
    /**
     * Si horas minutos y segundos de los parámetros h1 y h2 son mayores o iguales,
     * devuelve true
     */
int ub1= h1.h*60*60+h1.m*60+h1.s;
int ub2= h2.h*60*60+h2.m*60+h2.s;
    return ub1>=ub2;

}

bool operator== (const FormatoHora &h1, const FormatoHora &h2){
    /**
     * Si horas minutos y segundos de los parámetros h1 y h2 son iguales,
     * devuelve true
     */
    return h1.h == h2.h && h1.m == h2.m && h1.s == h2.s;
}

bool operator!= (const FormatoHora &h1, const FormatoHora &h2){
    /**
     * Si horas minutos y segundos de los parámetros h1 y h2 son iguales,
     * devuelve true
     */
    return h1.h != h2.h || h1.m != h2.m || h1.s != h2.s;
}