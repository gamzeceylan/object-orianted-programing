#include <iostream>
using namespace std;
/*
https://www.youtube.com/watch?v=YqYpgQrvVgg&list=PLfs1gAT4S8yInGkovwucGKCjcxP-Odf7Q&index=34

    taban sinifi public kalitim alirsak:
        derleyici taban siniftaki hicbir erisim belirtecini degistirmeden turetilmis sinifa kopyalar
    
    taban protected kalitim alirsak:
        taban siniftaki public olanlari protected olarak tasir
        sadece turetilmis siniftan public ve protected ozelliklere erisilir
    
    taban private kalitim alirsak:
        sadece turetilmis siniftan public ve protected ozelliklere erisilir

    NOT: public ve private kalitim almanin farkı birden fazla kalitim alindiginda ortaya cikar
        class A{};
        class B: private A{};   <---
        class C: public B{};
    eger B sinifindan taban sinifin tabanina erisim istiyorsak protected, istemiyorsak private kalitim almaliyiz

*/
class A{
    private:
        int priA;
    protected:
        int proA;
    public:
        int pubA;
        A(): pubA(0), priA(2), proA(1){}

};

class B: private A{
    private:
        int priB;
    protected:
        int proB;
    public:
        int pubB;
        B(): pubB(3), priB(5), proB(4){}
        void Yazdir(){
            cout<< A::pubA << " " << A:: proA << " " << endl;
        }

};

int main(){
    /// public kalitim alindiginda
    /*
        B b;
        cout << b.pubA << endl;
        //cout << b.proA << endl; erisilemez
        //cout << b.priA << endl; erisilemez
        b.Yazdir();
    */

    /// protected kalitim alindiginda
    B b;
    // cout << b.pubA << endl; erisilemez
    b.Yazdir();


    return 0;
}