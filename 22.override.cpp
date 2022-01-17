/*
    override: kalitim alindiginde taban sinifta tanimlanan ozellik ve methodun yeniden tanimlanip ezilmesidir
    ! overloading: cpp'nin kendisinde varolan bir metodu yeniden tanimlamaktir. kalitima gerek yok

    - ozellikleri methodlarla, methodlari ozelliklerle ezebiliriz.

    - turetilmis sinifta, base sinifa ait metodlari ayni isimle yazarsan artik derleyici o sinifa ait metodu calistirir.
    eger override etmezsen base sinifa ait metodu calistirir.

    - turetilmis sinifta taban sinifia ait metodu da cagirmak icin Base::print() seklinde kullanim yapabilirsin

    casting: verilerin bir turden digerine donusturulmesi islemi. eger turetilmis sinifta ezdigimiz bir method veya ozelligi
    main icinde kulanmak istersek pointer ureterek casting islemi yapariz. 
        NOT: normalde pointerlar ayni ture ait adresleri gostermek zorundadir. ama kalitimda bu is biraz farklidir.
        Turetilmis sinifi, taban siniftan olusmus pointer icine
        Base *ptr = &d;
*/
#include <iostream>
using namespace std;

class Base{
    public:
        int x; /// bu taban sinifta ozellik, turetilmis sinifta method olarak ezelim
        int data[100];
        int size;
        Base(): size(0), x(0){}
        void add(int value){
            data[size] = value;
            size++;
        }
        void print()const{
            cout << "Base print: ";
            for(int i=0;i<size;i++)
                cout << data[i] << " ";

            cout << endl;
        }
};

class Derived: public Base{
    public:
        float data[100];
        int size;
        Derived(): size(0){}
        void add(float value){
            data[size] = value;
            size++;
        }
        void print()const{ // bu metodu ezdik. artik derived sinif nesnesi uzerinden burasi cagrilir
            cout << endl;
            Base::print(); /// turetilmis sinifa ait metodu kullanmak icin
            cout << "Derived print: ";
            for(int i=0;i<size;i++)
                cout << data[i] << " ";

            cout << endl;
        }

        void addInt(int value){
            Base::add(value);  /// turetilmis sinifa ait metodu kullanmak icin
        }

        void x(){
            cout << "\nHello World!\n";
        }
};
int main(){
    Base b;
    b.add(10);
    b.add(5);
    b.print();

    Derived d;
    d.print();
    d.add(3.9);
    d.add(3.7);
    d.print();

    d.addInt(0);
    d.addInt(1);
    d.addInt(2);
    d.print();

   // cout << d.x;  -> hata. x artik method olarak derived sinifinda kullanilir.
   d.x(); // -> dogru

   ///// casting
   Base *ptr = &d;
   cout << ptr->x << endl;
   ptr->x = 2;
   cout << ptr->x << endl;
   d.x();
   // ptr->x(); hata
 
    return 0;
}