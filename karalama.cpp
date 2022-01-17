/*
    copy contructor: ozel bir kurucu fonksiyon. parametre olarak siniftan uretilen bir nesne veririz.verdigimiz nesnenin kopyasi ile yeni
    bir nesne olustururuz.

    geri donus degeri olmaz
    parametresi sinifin referans turunde nesnesi
    parametrenin sabit olarak gelmesi gerek. yoksa copy constructor olmaz

*/

#include<iostream>
using namespace std;
class Nokta{
    private:
        int x,y;


    public:
        int* z;
        const int t;
        Nokta();
        Nokta(int,int,int);

        ~Nokta();

        // get metodlar
        int getX()const;
        int getY()const;

        // set metodlar
        void setX(int);
        void setY(int);

        void ekranaYaz();

};


Nokta::Nokta() : t(0){
    x=0;
    y=0;
    z=new int(5);
    cout << "parametresiz kurucu\n";
}
Nokta::Nokta(int x, int t, int y=7): t(t){
    this->x=x;
    this->y=y;
    z = new int(10);
    cout << "parametreli kurucu\n";
}

Nokta::~Nokta(){
    cout << "yikici\n";

}

int Nokta::getX()const{
    return x;
}
int Nokta::getY()const{
    return y;
}

int main(){  
    Nokta n1(5,10,15);

    Nokta n2(n1); // kopyalama
    cout << n1.z << endl << n2.z << endl;
  
    return 0;
}