/*
    bir sinif bir sinifi genisletir, kullanir
*/
#include<iostream>
#include<math.h>
using namespace std;

class Nokta{
    private:
        int x,y;

    public:
        Nokta();
        Nokta(int, int);

        // get metodlar
        int getX()const;
        int getY()const;

        void ekranaYaz()const;

        double uzaklikHesapla(const Nokta&)const;

};
Nokta::Nokta(){
    x=0;
    y=0;
    cout << "parametresiz yapici\n";
}
Nokta::Nokta(int x, int y=99){
    this->x = x;
    this->y = y;
    cout << "parametreli yapici\n";
}

int Nokta::getX()const{
    return x;
}
int Nokta::getY()const{
    return y;
}
void Nokta::ekranaYaz()const{
     cout<< x << "," << y <<endl;
}
double Nokta::uzaklikHesapla(const Nokta& n)const{
    /*
        Not: const fonksiyonlarin icinde cagirdigin fonksiyonalrda da const olma
        garantisi vermelisin. o yuzden getX ve getY const yaptik
    */
    int xU= pow(n.getX()-x, 2);
    int yU= pow(n.getY()-y, 2);
    return sqrt(xU+yU);
}


class Cizgi{
    private:
        Nokta baslangic;
        Nokta bitis;
    public:
        Cizgi(Nokta, Nokta);
        double uzunluk()const;
        void yazdir()const;

};
// cizgi icin noktaları yeniden olusturma ve baslangic degeri atama

// asagidaki gibi yazinca parametresiz kurucular cagirliyor
// cunku baslangic ve bitis Nokta nesnesi. this ile onlari cagriyoruz ve yeniden olusuyorlar???
Cizgi::Cizgi(Nokta baslangic, Nokta bitis) {
    this->baslangic = baslangic;
    this->bitis = bitis;

}

// zaten varolan noktalari cizgiye baslangic degeri atama 

// asagidaki gibi yazinda Nokta icin kurucular cagrilmiyor. dogrusu asagiski yazimdir
// (!) Cizgi icin kurucu cagirmadan once ozelliklerinden olan Nokta nesnelerinin hangi degerlerden baslatilacagini veriyoruz
// cunku cizgi icin zaten olusturulmus iki nokta nesnesini kullaniyoruz
// bunlar icin de kurucu fonksiyonlar main icinde cagriliyor.
// burada yeni bir nesne olusmamali
/*
Cizgi::Cizgi(Nokta baslangic, Nokta bitis): baslangic(baslangic), bitis(bitis) {

}
*/
double Cizgi::uzunluk()const{
    return baslangic.uzaklikHesapla(bitis);
}
void Cizgi::yazdir()const{
    baslangic.ekranaYaz();
    bitis.ekranaYaz();
    cout <<"Cizgi uzunlugu: " << uzunluk() << endl;
}

int main(){     
    Nokta n1(3,4);
    Nokta n2(0,0);
    Cizgi c(n1,n2);
    c.yazdir();

    Cizgi c2(Nokta(3,4), Nokta(0,0));
    c2.yazdir();

    return 0;
}