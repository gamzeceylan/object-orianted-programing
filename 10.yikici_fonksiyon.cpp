
#include<iostream>
using namespace std;
/*
    cont tanimlandiktan sonra degistirilemez
    cosnt veri tiplerini public alanda tanimlanmasinin bir sakincasi yoktur. zaten disaridan da
    degistirilemeyecek bir degerdir.
    const tiplerinin kurucu fonksiyon cagrilmadan degerlerinin atanmasi gerekir
    const veri tipleri sadece okunabilirdir. kurucuda veya herhangi bir yerde atama yaparsan hata alirsin

    asagidaki ozel bir yazimdir. sabitleri bu sekilde tanimlariz. 
    kurucu metod daha cagrilmadan : sonraki islemler yapilir.

    Nokta(): t(0){  // t ye baslangic 0 atanir

        //islemler
    }

    Nokta(int x, int y, int t): t(t){  // t ye gelen t degeri atanir

        //islemler
    }

    NOT: t(t) yaziminda derleyici ilk t'nin sinifa ait, ikinci t'nin gelen degere ait oldugunu bilir. this kullanimina gerek yoktur.
*/
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
        int getX();
        int getY();

        // set metodlar
        void setX(int);
        void setY(int);

        void ekranaYaz();

};
/*
Nokta::Nokta(){
    x=0;
    y=0;
 // t=0; hata sadece okunabilir.
   
}
Nokta::Nokta(int x, int y=7, int t=0){
    this->x=x;
    this->y=y;
  //  this->t=t; hata
}
*/
Nokta::Nokta(): t(0){
    x=0;
    y=0;
   
}
// t degeri gelirse geleni atar, gelmezse 0 atar
Nokta::Nokta(int x, int y=7, int t=0 ): t(t){
    this->x=x;
    this->y=y;
}
/*
    NOT:

    Nokta::Nokta(int x, int t, int y=7 ): t(t){}  -> dogru
    Nokta::Nokta(int x, int y=7, int t=0 ): t(t){}  -> dogru
    Nokta::Nokta(int x, int y=7, int t ): t(t){}  -> yanlis

    default deger atadiktan sonra gelen parametrelere de default deger atamalisin. yoksa derleyicinin kafasi karisir
*/
Nokta::~Nokta(){
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
    Nokta n2(5,10,15);

    return 0;
}