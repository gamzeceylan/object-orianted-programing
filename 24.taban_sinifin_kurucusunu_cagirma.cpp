/*
Tekrar izle:
https://www.youtube.com/watch?v=bxsOoKiIUA0&list=PLfs1gAT4S8yInGkovwucGKCjcxP-Odf7Q&index=34
    
    derived sinifindan nesne uretildiginde arka planda base sinifindan da nesne uretilir.
    bu yuzden kalitim aldiginda base sinifinin kurucusunun mutlaka baslatilmasi, bir deger atanmasi gerekir.

    1- ya taban siniftaki kurucuda degiskenlere varsayilan deger vereceksin
    2- ya da taban sinifta varsayilan deger vermezsen tuertilmis sinifin kurucusunda, taban sinif degislenlerinin hangi degerlerle baslatilacagini belirteceksin

*/
#include <iostream>
using namespace std;

class Base{
    public:
        int* ptr;
        double* dptr;
        /*
        1
        eger kurucu asagidaki gibiyse mutlaka turetilmis sinifta kurucuya deger atamasi yapmalisin

        Base(int i, int k){
            cout << "Base kurucu\n";
            this->k=k;
            ptr = new int(i);
        }
        
        */

       Base(int i=0){
            cout << "Base int kurucu\n";
            ptr = new int(i);
        }

        Base(double i){
            cout << "Base double kurucu\n";
            dptr = new double(i);

        }
        
        

};
class Derived: public Base{
    public:
        int* ptr2;
        /*
        1
        Derived(int i=0, int k=0): Base(1,k){
            cout << "Derived kurucu\n";
            ptr2 = new int(i);
        }
        */

        Derived(int i=0): Base(1){
            cout << "Derived kurucu\n";
            ptr2 = new int(i);
          //  ptr = new int(i);
        }
        // : Base(1) de taban sinifin int kurucusu
        // : Base (1.2) de taban sinifin double kurucu calisir
 

};
int main(){
    // Base b(100);
    // cout << *b.ptr << endl;

    Derived d(50);
    cout << *d.ptr2 << endl;
    cout << *d.ptr << endl;

    return 0;
}