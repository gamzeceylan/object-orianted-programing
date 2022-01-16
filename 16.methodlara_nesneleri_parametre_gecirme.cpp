#include<iostream>
#include <math.h>
using namespace std;

/*
    Nokta& referans, nesnenin kendisini kullan kopya olusutup onun uzerinden islem yapma demek.
*/
class Nokta{
    private:
        int x,y;


    public:
        Nokta();
        Nokta(int,int);

        // get metodlar
        int getX()const;
        int getY()const;

        double uzaklikHesapla(const Nokta&)const;

};



Nokta::Nokta(){
    x=0;
    y=0;

}
Nokta::Nokta(int x,int y=7){
    this->x=x;
    this->y=y;

}
int Nokta::getX()const{
    return x;
}
int Nokta::getY()const{
    return y;
}

double Nokta::uzaklikHesapla(const Nokta& n)const{
    int xU= pow(n.getX()-x, 2);
    int yU= pow(n.getY()-y, 2);
    return sqrt(xU+yU);
}

int main(){  
    Nokta n1(3,4);
    Nokta n2 (0,0);
    cout << n1.uzaklikHesapla(n2)<< endl;
    return 0;
}