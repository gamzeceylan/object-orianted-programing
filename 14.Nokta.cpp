// fonksiyon govdelerinin oldugu dosya -> cpp dosyası

#ifndef _NOKTA_
#define _NOKTA_

#include "14.Nokta.hpp" // prototiplerin oldugu dosya include edilir
#include<iostream> // friend'deki ostream isim uzayi icin


Nokta::Nokta() : t(0){
    x=0;
    y=0;
    z=new int(5);
  
}
Nokta::Nokta(int x, int t, int y=7): t(t){
    this->x=x;
    this->y=y;
    z = new int(10);
  
}
Nokta::Nokta(const Nokta& n): t(t){
    x = n.x;
    y = n.y;
    z = new int(*n.z);

}
Nokta::~Nokta(){
    delete z;
}

int Nokta::getX()const{
    return x;
}
int Nokta::getY()const{
    return y;
}
std::ostream& operator << (std::ostream& out, Nokta& n){
    out << n.x <<"," << n.y;
    return out;
}

#endif