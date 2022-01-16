
#include<iostream>
using namespace std;
/*
    nesnenin yasam dongusu tamamlandiginda derleyici tarafindan cagrilan bir yikici fonksiyon vardir.
    parametre alamaz.
    Nesne olusturuken dinamik bellegi kullanirsak yikici fonksiyonda bu alanlari iade etmeliyiz. eger dinamik
    bellek ile islem yapmiyorsak tanimlamasak da olur.

    NOT: ilk olusturulan nesnenin kurucusu en son cagirilir. ilk giren son cikar veri yapisi
*/
class Nokta{
    private:
        int x,y;


    public:
        int* z;
        Nokta();
        Nokta(int,int);
        ~Nokta();

        // get metodlar
        int getX();
        int getY();

        // set metodlar
        void setX(int);
        void setY(int);

        void ekranaYaz();

};


Nokta::Nokta(){
    x=0;
    y=0;
    z=new int(5);
    cout << "parametresiz kurucu cagrildi " << x <<" "<< y <<" "<< *z <<"\n";
}
Nokta::Nokta(int x, int y=7){
    this->x=x;
    this->y=y;
    z = new int(10);
    cout << "parametreli kurucu cagrildi " << x <<" "<< y <<" "<< *z <<"\n";
}
Nokta::~Nokta(){
    cout << "yikici calisti "  << x <<" "<<y <<" "<< *z <<"\n";
    delete z;
}

int Nokta::getX(){
    return x;
}
int Nokta::getY(){
    return y;
}



int main(){  
    Nokta n1;
    Nokta n2(14,15);
    return 0;
}