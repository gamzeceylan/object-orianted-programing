/*
    kurucu fonksiyonlar, nesne ilk olustugunda derleyici tarafindan cagrilir.
    geri donus degeri yok, sinif adiyla ayni isimde, public
*/

#include<iostream>
using namespace std;

class Nokta{
    private:
        int x,y;

    public:
        Nokta();
        Nokta(int, int);

        // get metodlar
        int getX();
        int getY();

        // set metodlar
        void setX(int);
        void setY(int);

        void ekranaYaz();



};

Nokta::Nokta(){
    // nesne ilk olustugunda baslangic degeri veriyoruz
    x=0;
    y=0;
}
/* 
    eger iki degiskene de default bir deger verirsen bu fonksiyon parametresiz kurucu gibi davranir
    ve yukarida parametresiz kurucu tanimladigimizdan hata veirir.

    Nokta::Nokta(int x=0, int y=0){
        this->x = x;
        this->y = y;
    }

    eger sadece yukaridaki tanimi yaparsakk, parametresiz kurucuda yazdigimiz ozellikleri de karsilariz.
    onu silip sadece bunu yazabiliriz

    Not: default degerler sagdan sola dogru calisir

*/
Nokta::Nokta(int x, int y=99){
    this->x = x;
    this->y = y;
}

int Nokta::getX(){
    return x;
}
int Nokta::getY(){
    return y;
}
void Nokta::setX(int _x){
    x=_x;
}
void Nokta::setY(int _y){
    if(_y > 5)
        y=_y;
    else
        y = 2;
}


void Nokta::ekranaYaz(){
     cout<< x << "," << y <<endl;
}



int main(){     
    Nokta n1;
    cout << n1.getX() << "," << n1.getY() << "\n";

    Nokta n2(8,9);
    cout << n2.getX() << "," << n2.getY() << "\n";
    
    Nokta n3(8);
    cout << n3.getX() << "," << n3.getY() << "\n";
    
    
   
    return 0;
}