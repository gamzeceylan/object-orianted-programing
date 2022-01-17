/*
    abstract class(soyut sinif): taban sınıftan türeyen tüm sınıflarda olmasını
    istediğimiz özellik ve metodları belirtiriz. soyut sınıflardan nesne üretilemez

    soyut sınıftan türettiğimiz bir nesneyi başka bir sınıda kalıtım alırsak soyut metodları
    tanımlamamıza gerek yoktur
*/

#include<iostream>
using namespace std;

// soyut sınıfımız
class Sekil{
    protected:
        double alan,cevre;
    public:
        Sekil(){
            cout <<"Sekil Sinifi Kurucusu\n";
        }
       virtual void senNesin() = 0;
       virtual void alanHesapla() = 0;
       virtual void cevreHesapla() = 0;
       double getAlan()const{ return alan; }
       double getCevre()const{ return cevre; }

};

class Dikdortgen:public Sekil{
    double yukseklik, genislik;
    public:
        Dikdortgen(double yukseklik, double genislik):yukseklik(yukseklik), genislik(genislik){}
        void senNesin(){
            cout << "Ben Dikdortgenim\n";
        }
        void alanHesapla(){
           alan=yukseklik*genislik;
        }
        void cevreHesapla(){
           cevre = 2*(yukseklik+genislik);
        }
};

class Daire:public Sekil{
    double yaricap, pi;
    public:
        Daire(double yaricap): yaricap(yaricap), pi(3.14){}
        void senNesin(){
            cout << "Ben Daireyim\n";
        } 
        void alanHesapla(){
           alan = pi*yaricap*yaricap;
        }
        void cevreHesapla(){
           cevre = 2*pi*yaricap;
       }        
        
};
class Kare:public Dikdortgen{
    double kenar;
    public:
        Kare(double kenar): Dikdortgen(kenar, kenar){}
        void senNesin(){ cout << "Ben kareyim\n"; }
};

int main(){
    Sekil* dizi[3];
 //   dizi[0] = new Sekil();
    dizi[0] = new Kare(2); 
    dizi[1] = new Dikdortgen(3,4);
    dizi[2] = new Daire(5);

  //  dizi[0]->senNesin();
    dizi[0]->senNesin();
    dizi[0]->alanHesapla();
    dizi[0]->cevreHesapla();
    cout << "alan: " << dizi[0]->getAlan()
         << " cevre: " << dizi[0]->getCevre() << endl;


    dizi[1]->senNesin();
    dizi[1]->alanHesapla();
    dizi[1]->cevreHesapla();
    cout << "alan: " << dizi[1]->getAlan()
         << " cevre: " << dizi[1]->getCevre() << endl;
    


    dizi[2]->senNesin();
    dizi[2]->alanHesapla();
    dizi[2]->cevreHesapla();
    cout << "alan: " << dizi[2]->getAlan()
         << " cevre: " << dizi[2]->getCevre() << endl;
    
   
    

    return 0;
}