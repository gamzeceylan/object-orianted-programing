/*
    copy contructor: ozel bir kurucu fonksiyon. parametre olarak siniftan uretilen bir nesne veririz.verdigimiz nesnenin kopyasi ile yeni
    bir nesne olustururuz.

    geri donus degeri olmaz
    parametresi sinifin referans turunde nesnesi
    parametrenin sabit olarak gelmesi gerek. yoksa copy constructor olmaz
    yazmasak da derleyici arka planda cagirir

   - sinif ozellikleri icinde dinamik bellek kullandigimiz zaman (int *z=new int(0) gibi) copy c. kullaniriz. cunku derleyici
    bizim icin bu yapiciyi calistirsa da dinamik bellek alanlarini ayirmaz. z pointer'ı yeni nesneyi gosteririr bu da z ile ilgili islem yaptigimizda
    digeri uzerinde de istemeden islem yapmamiz anlamina gelir . bizim bu alanlari ayirip yeni bellek bolgeleri tahsis etmemiz gerekir

   - yikici fonksiyonda dinamik bellek alanlari iade edilir. dinamik bellek kullanip copy constructorda ilgili islemi yapmazsak yikici fonksiyon calistiginda delete z ile 
    z silinir ama kopyalanan nesnenin z bolgesine erismek istersek, silinmis bir alana erismeye calisiriz

    copy constructor yazmadan da Nokta n2(n1); calisir.
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
        Nokta(const Nokta&); // copy contructor
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
Nokta::Nokta(const Nokta& n): t(t){
    x = n.x;
    y = n.y;
    z = new int(*n.z); /// DIKKAT !!! pointer atamasi bu sekilde yapikmali
    //t = n.t;
    cout << "kopyalama kurucusu\n";
}
Nokta::~Nokta(){
    delete z;
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
    Nokta n3 = n1; // kopyalama

    Nokta n4;
 //   n4=n1;
  
    return 0;
}