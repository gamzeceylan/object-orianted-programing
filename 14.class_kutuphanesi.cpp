// main

/*
    bu static kutuphane olusturma olayidir.
    dinamik olarak olustursaydik (dll) sadece hpp dosyasini gorebilecektik. boylece kodumuzun
    kaynak dosyasini paylasmadan programimizi paylasabilecektik
*/
#include "14.Nokta.hpp" 

#include<iostream>
using namespace std;

int main(){  
    Nokta n1(5,10,15);

    Nokta n2(n1); // kopyalama
    Nokta n3 = n1; // kopyalama

    return 0;
}