/*
    sabit nesne amaci: sinifimizdaki metodlara nesneleri parametre olarak gecirmek. parametresi o sinifa ait nesne olan
    metodlari tanimlarken nesnelerin degistirilemeyecegini garanti altina almak isteriz. bu yuzden sabit nesneler veririz
    const nesnelerin hiçbir ozelligine, metoduna erisemeyiz ve degistiremeyiz. 

    sabit fonksiyon amaci: hata ayiklama zamaninda kolaylik saglamasi.
    sabit method tanimladigimizda sinifin ozelliklerinin sabit method icinde bir degisime ugramadigi garantisi verir.
    kullanmak zorunlu degil ama hata ayiklama zamani daha kisa surer
    sinifa ait olmayan degerleri bu fonksiyonlar icinde degistirebiliriz
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
        int getX()const;  // const method
        int getY()const;  // const method

        // set metodlar
        void setX(int);
        void setY(int);

        void ekranaYaz();

};


Nokta::Nokta() : t(0){
    x=0;
    y=0;
    z=new int(5);
}
Nokta::Nokta(int x, int t, int y=7): t(t){
    this->x=x;
    this->y=y;
    z = new int(10);
}
Nokta::~Nokta(){
    delete z;
}

int Nokta::getX()const{
    // x=10;  -> sinif ozelligini degistirme var, hata
    int sayi=2*x; // hata yok
    return x;
}
int Nokta::getY()const{
    return y;
}

int main(){  
    const Nokta n1(5,10,15);
    /*
        const nesnelerin hiçbir ozelligine, metoduna erisemeyiz ve degistiremeyiz. 
        n1.getX() -> hata
    */

    Nokta n2;
    cout << n2.getY();
  
    return 0;
}