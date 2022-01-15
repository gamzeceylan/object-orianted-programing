#include<iostream>
using namespace std;

/*
    this, bir pointer'dir ve siniflara ozeldir.
    pointer oldugundan -> ile kullanilir
    sadece sinif icinde yazilan fonksiyonlarda kullanilir.
*/

class Nokta{
    public:
        int x,y;

        void degerAta(int, int);
        void ekranaYaz();


};

void Nokta::degerAta(int x, int y){
   // x = x; parametre olarak gelen x'i yine kendisine atar
   // y = y;

    this->x = x;
    this->y = y;

}

void Nokta::ekranaYaz(){
     cout<< x << "," << y <<endl;
}


int main(){     
    Nokta n1; // siniftan model olusturduk
    n1.degerAta(5,10);
    n1.ekranaYaz();


    return 0;
}