#include<iostream>
#include <math.h>
using namespace std;

class Nokta{
    private:
        int x,y;


    public:
        Nokta();
        Nokta(int,int);
        ~Nokta();

        // get metodlar
        int getX()const;
        int getY()const;

        Nokta topla(const Nokta&)const;


};



Nokta::Nokta(){
    x=0;
    y=0;
    cout << "parametresiz yapici\n";

}
Nokta::Nokta(int x,int y=7){
    this->x=x;
    this->y=y;
    cout << "parametreli yapici\n";

}
Nokta::~Nokta(){
    cout << "yikici cagrildi\n";
}
int Nokta::getX()const{
    return x;
}
int Nokta::getY()const{
    return y;
}

Nokta Nokta::topla(const Nokta& n)const{
    int x = this->x + n.x;
    int y = this->y + n.y;
    return Nokta(x,y); // bu islemde yapici cagrilmaz

}
int main(){  
    Nokta n1(3,4);
    Nokta n2 (0,0);

    Nokta n3 = n1.topla(n2); // bir nesne uzerine aliriz, nesne omru bu scope lar kapanana kadardir
    cout << n3.getX() << "," << n3.getY() << endl;
    

    int x = (n1.topla(n2)).getX(); 
    // bu sekilde bir nesne uzerinde tutmadan bu degerleri alabiliriz
    // derleyici tek satirda nesneyi olusturur ve siler
    // tek satirda kullanip silmek icin () arasinda kullanmamiz gerek
    // yukaridaki islem icin yapici cagrilmaz
    cout << x << endl;
    return 0;
}