#include<iostream>
using namespace std;

// NOT:
// bir değişken derleyici tarafından ilk önce tanımlı oladuğu scope'da aranır
// eger yoksa globale bakılır
// local degiskenler ilgili scope kapanınca bellekten silinir

// birden fazla programci bir program uzerinde calisirken derleyicinin tekrarlanan tanimlarda
// hata vermemesini saglamak. her programci kendine bir namespace belirtip orada calisabilir

namespace programci1{
    int x=20;
    void Foo(){
        int x=8;
        cout << x << '\n';
    }
}

namespace programci2{
    int x=10;
    void Foo(){
        int x=5;
        cout << x << '\n';
    }
}

int main(){
    int x=0;
    cout << x << '\n'; // 0 yazar

    cout << programci1::x << '\n'; // 20
    programci1::Foo(); // 8

    cout << programci2::x << '\n'; // 10
    programci2::Foo(); // 5


    return 0;
}