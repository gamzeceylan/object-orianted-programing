#include<iostream>
using namespace std;
// bu işlemi sınıf kütüphanelerini oluşturmak için yaparız
class Nokta{
    public:
        int x,y;

        // prototip tanımlama
        void degerAta(int, int);
        void ekranaYaz();
        bool baslangictaMi();


};

// namespace gibi :: ile kullanırsın
void Nokta::degerAta(int _x, int _y){
    x = _x;
    y = _y;
}

void Nokta::ekranaYaz(){
     cout<< x << "," << y <<endl;
}

bool Nokta::baslangictaMi(){
    if(x==0 && y==0)
        return true;

    return false;
}

int main(){     
    Nokta n1; // siniftan model olusturduk
    Nokta n2;
    n1.degerAta(5,10);
    n1.ekranaYaz();

    n2.degerAta(0,0);
    n2.ekranaYaz();

    if(n1.baslangictaMi())
        cout << "n1 baslangic noktasinda";

    if(n2.baslangictaMi())
        cout << "n2 baslangic noktasinda";
   

    return 0;
}