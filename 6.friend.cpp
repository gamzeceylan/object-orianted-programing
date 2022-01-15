/*
    1- bir sinifin bir fonksiyon ile arkadas olmasi
    2- bir sinifin baska sinifla arkadas olmasi

    private alanlara, friend tanimladigimiz zaman o sinif veya fonksiyondan erisebiliriz.
    bunun disinda private disariya kapalidir.

    friend fonksiyonlar, sinifin fonksiyonu degildir. bu yüzden sinif adini :: ile tanimlamayiz

    classlari friend olarak tanimladigimiz zaman, friend olan class metodlarindan diger sinifin
    private dahil tum alanlarina erisilebilir

    siniflardaki nesneleri yazdirirken cout << (veya baska operatorler icin de olabilir) friend metodlari kullaniriz

*/

#include <iostream>
using namespace std;

class B; // B sinifi prototipi

class A{
    private:
        int x;

    public:
        int getX();
        int setX(int);
        friend void Foo(A&);

        void setY(B&); // friend class icin

        friend ostream& operator << (ostream&, A&); // cout << a yı kullanabilmek icin

};

class B{
    private:
        int y;
    public:
        int getY();

        friend class A;

};


int A::getX(){ return x; }

void Foo(A& a){ a.x=0; } // friend fonk, private alana direkt erisebilir.

void A::setY(B& y){ y.y=100; } // A sinifindan B'nin private alanini degistirebiliyoruz

int B::getY(){ return y;}

int A::setX(int _x){ x=_x; }
ostream& operator << (ostream& o, A& a){ // friend olarak << operatoru asiri yuklenir
    o <<"A sinifindaki x = " <<  a.x;
    return o;
}

int main(){
    A n;
    Foo(n);
    cout << n.getX() << "\n";

    B b;
    n.setY(b);
    cout << b.getY() << "\n";

    A a;
    a.setX(6);
    cout << a; // friend ostream
    
    return 0;
}