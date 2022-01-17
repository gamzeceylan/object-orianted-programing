/*
    sinif icinde pointer ozellik yoksa kopyalama kurucunu ve atama operatorunu asiri yuklmeeye gerek yok.

*/
#include <iostream>
using namespace std;

class Base{
    public:
        int* ptr;

        Base(int i=0){
            cout << "Base kurucu\n";
            ptr = new int(i);
        }

        Base(const Base& b){
            cout << "Base kopyalama kurucusu\n";
            ptr = new int(*b.ptr);
        }
        
        

};
class Derived: public Base{
    public:
        int* ptr2;

        Derived(int i=0){
            cout << "Derived kurucu\n";
            ptr2 = new int(i);
        }
        Derived(const Derived& d){
            cout << "Derived kopyalama kurucusu\n";
            ptr2 = new int(*d.ptr2);
        }

};
int main(){
    Base b(100);
    cout << "b: "<<b.ptr << "\t" << *b.ptr << endl<< endl;

    Base xb = b;
    cout <<"xb: "<< xb.ptr << "\t" << *xb.ptr << endl<< endl;

    Derived d(500);
    cout << "d: "<<d.ptr << "\t" << *d.ptr << endl<< endl;

    Derived xd1 ;
    xd1 = d;
    cout <<"xd1: "<< xd1.ptr << "\t" << *xd1.ptr << endl<< endl;

    Derived xd2=d ;
    cout << "xd2: " <<xd2.ptr << "\t" << *xd2.ptr << endl<< endl;
    return 0;
}