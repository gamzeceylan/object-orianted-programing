/*
    polimorfizm (cok bicimlilik): sınıflarda override yapıldığında sanallaştırma yapılmalıdır.
    - nesneleri pointer veya diziye yerleştirdiğimiz zaman taban sınıf ve turetilmiş sınıfı ayni pointer'a 
    koyabilmek için, taban siniftan yerleştirme yapilir. bu yüzden sanallaştırma yapmazsak (virtual ile) 
    aşagıdaki kodda taban sınıfın yani kedi sınıfının ses ver methodu çalışır. Taban sınıf türemiş sınıfın
    sesVer methodunu ezer.
        Aslan a;
        Kedi *k1;
        k1 = &a;
        k1->sesVer(); // miyav

        k1 = &k;
        k1->sesVer(); // miyav

    - ama virtual ile taban sınıfta sanallaştırma yaptığımızda taban sınıf türemiş sınıfın override edilmiş methodunu ezemez

    virtual ile sanallaştırma yaptığımızda derleyici arka planda taban sınıfa ek özellik olarak bir pointer yerleştirdi. (Vptr)
    Yani sanal sınıf tablosu oluşturdu. Derleyici hangi sınıftan hangi methodun çağrılacağına karar vermek için bunu yaptı. Bir pointer
    üzerinden methodlarımı çağırdığımız zaman öncelik olarak Vptr ye bakılır çünkü sanal. ve nesnenin ne olduguna karar verir.
    Vptr'de iki ayrı sesVer methodunun adresi tutulur ona göre çağrım yapılır.
        örneğin Ram'de 2. adreste kediye ait, 7. adreste aslana sesVer methodunu tutulsun. Vptr tablosuna bunlar kaydedilir. Eğer 2.
        adresteki sesVer çağrılırsa Vptr'ye bakılrı ve kedi ye ait olan çağrılır. eğer 7. adresteki sesVer çağrılırsa tabloya bakılır
        ve aslana ait sesVer çağrılır.

*/
#include<iostream>
using namespace std;

class Kedi{
    public:
        virtual void sesVer(){
            cout << "Miyav\n";
        }

};

class Aslan: public Kedi{
    public:
        void sesVer(){
            cout << "Kukredim\n";
        }

};


int main(){
    Kedi k;
    k.sesVer();

    Aslan a;
    a.sesVer();

    Kedi *k1;
    k1 = &a;
    k1->sesVer(); // virtual yazmazsan -> miyav virtual yazarsan -> kukreme

    k1 = &k;
    k1->sesVer();
/*
    Aslan *a1;
    a1 = &k;   hata
    a1->sesVer(); //

*/
    return 0;
}