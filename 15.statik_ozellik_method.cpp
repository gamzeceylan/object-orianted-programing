/*
    int i=0; gibi bir degisken tanimladigimizda her tanimlandigi yerde bellekten bir yer tutar ve yasam suresi
    bitene kadar bu alani birakmaz.

    static ozellik: ilk kez tanimladigi yerde bellekten yer tutar. sonraki tanimlandigi yerlerde de ayni bellek yeri
    uzerinden islem yapar. her cagrildigi yerde bellekten yer ayirmaz.
    - tum nesneler uzerinde ortak bir islem yapmayi saglar
    - static degiskenlerin get ve set metodlari da static olmali
    - static degiskenler icin daha nesne olusmadan programin ilk calistigi anda bellekten yer ayirilir
    - static degiskenlere baslangic degeri veremeyiz. kendi kendine olusmazlar
    - nesnelerden biri icin static alani degistirirsen hepsi icin degisir
*/



#include<iostream>
using namespace std;
class Nokta{
    private:
        int x,y;
        static int sayac_private;


    public:
        static int sayac_public;
        // static int sayac = 0; hata baslangic degeri veremeyiz

        Nokta();
        Nokta(int,int);
        ~Nokta();

        // get metodlar
        int getX()const;
        int getY()const;

        static int getSayac_private(); // static ozelliklerin fonksiyonlari static olur
        static void setSayac_private();
 

};

int Nokta::sayac_public=0; // static degiskenlere ilk degeri verme
int Nokta::sayac_private=0;

Nokta::Nokta(){
    x=0;
    y=0;
   // sayac = 0; kurucu metod icinde de verilemez
   sayac_public++;

   sayac_private++;
}
Nokta::Nokta(int x,int y=7){
    this->x=x;
    this->y=y;
    sayac_public ++;

    sayac_private++;
}
Nokta::~Nokta(){
    sayac_public--; // sadece yasayan nesneleri tutma

    sayac_private--;
}

int Nokta::getSayac_private(){
    return sayac_private;
}
void Nokta::setSayac_private(){
    sayac_private++;
    //sayac_private = _i;
}


int Nokta::getX()const{
    return x;
}
int Nokta::getY()const{
    return y;
}

int main(){  
    Nokta n1;
    Nokta n2;
    cout << Nokta::sayac_public << endl; // private olunca bunu yapamayiz. publicte direkt erisebiliriz

    {
        Nokta n4;

        cout << Nokta::sayac_public << endl;
    } // scop sonunda n4 nesnesi silindi

    cout << Nokta::sayac_public << endl;
    
    cout << n2.getSayac_private() << endl;

    return 0;
}