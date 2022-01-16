
#include<iostream>
using namespace std;

/*
    Kurucu yazmazsak derleyici arka planda parametresiz kurucu cagirir.
    ama biz kurucu tanimladigimiz an derleyici bu islemi iptal eder ve bizim olusturdugumuz kurucular uzerinden islem yapar.
    eger parametreli bir kurucu tanimlarsak parametresiz artik cagrilmaz. bu yuzden eger hicbir kurucu yazmazsak Nokta dizi[5]; hata vermez. herhangi bir kurucu tanimlarsak
    parametresiz kurucu da tanimlamamizi ister
*/


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
    cout << "parametresiz kurucu cagrildi\n";
}


// x=18 yazarsak hem parametreli hem parametresiz davranir
Nokta::Nokta(int x, int y=0){
    this->x = x;
    this->y = y;
    cout << "parametreli kurucu cagrildi\n";
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
    // # 1 parametresiz olusturma   
    Nokta dizi1[5]; 
    /*  
        mutlaka parametresiz kurucu fonk. olmalı
        çünkü Nokta tipinde 5 elemanlı bir dizi olustururken parametre veremiyoruz
        kurucu içinde deger atamamiza gerek yok. Nokta(){} yazsak da olur
        5 defa "parametresiz kurucu cagrildi" yazar
    */

    cout << endl;

    // # 2 parametreli olusturma
    Nokta dizi2[5] = {{1,2}, {8}, {10,12}};
    /*
        baslangic degerlerini bu sekilde verebiliriz.
        {1,2,8,10,12} seklinde yanlistir. gruplandirarak vermeliyiz.
        3 kere "parametreli kurucu cagrildi" 2 kere "parametresiz kurucu cagrildi" yazar
        parametresiz kurucu icinde deger atamazsak rastgele atanir
    */
    
    cout << endl;

    // # 3
    Nokta dizi3[5] = {{}, {}, {1,2}, {8}, {10,12}};
    /*
        2 kere "parametresiz kurucu cagrildi" 3 kere "parametreli kurucu cagrildi"
    */

    // elemanlari ekrana yazdirma
    for(int i=0; i<5; i++){
        cout << dizi2[i].getX() << "," << dizi2[i].getY() << "\n";
    }
    

    // # 4 pointer seklinde tanimlama
    Nokta *ptr;
    /*
        sadece Nokta tipinde pointer tanimladik. bellekte herhangi bir yeri gostermez, yeni nesne olusmaz
        bu yuzden burada kurucu fonk cagrilmaz
    
    */
    cout << "..." << ptr << " " << &ptr << " "<< ptr->getX() << endl;
    /*
        Önemli Not: burada nesne olusmaz ama yine de ptr->getX() calisir ancak bu tanimsiz davranis uretir (undefined behavior).
        baslatilmamis bir isaretcinin bavurusunu uretmeye calistigi icin.
        pointer rastgele degerlerle baslatilir. uretilen deger hicbir sey ifade etmez. anlamli bir cikti yoktur. 
        pointer baslangic degerini null atamadigin icin suan bellekte baska bir programin kulandigi yerleri okuyor olabiliriz. bu bilinmez

        bu tarz bir kod ayrica hic guvenli degildir.
        1- isaretcinin yiginda baslatma icin hazir oldugu bir yeri gosterebilir (iyi durum)
        2- baska amaclar icin kullanilan hafizanin uzerine yazariz. kotu yazilimlar tarafindan kullanilabilir. ve erisilen yerin
        baslatilmayacaginin garantisi yoktur. (ptr = &main)
    */


    // # 5
    Nokta* ptr2 = new Nokta(); 
    /*
        kurucu cagrilir
        pointer artik bir nesneyi gosteriyor
    */
    cout << ptr2->getX() << endl;
   
    return 0;
}