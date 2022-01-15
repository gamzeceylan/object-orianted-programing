#include <iostream>
using namespace std;

class Nokta{
    // public yazmazsak private olur
    public:
        int x,y;

        void degerAta(int _x, int _y){
            x = _x;
            y = _y;
        }

        void ekranaYaz(){
             cout<< x << "," << y <<endl;
        }

        bool baslangicMi(){
            if(x==0 && y==0)
                return true;

            return false;
        }
};

int main(){ 
    Nokta n2;

    Nokta* n3;
    n3 = &n2; // önceden oluşturulmuş nesneyi referans alma

    Nokta* n4;
    n4 = new Nokta(); // bellekten yeni bir yer ayiriyoruz;

    // dizi olarak iki şekilde oluşturabiliriz
    Nokta array[10]; // 1

    Nokta *pArray; // 2 -> dizilerin adi da ilk elemanin adresini gösteren bir pointerdir
    pArray = new Nokta[10];
    
    for(int i=0; i<5; i++){
        array[i].degerAta(i, i+2); // 1
        (pArray + i)->degerAta(i+5, i+10); // 2
    }

      for(int i=0; i<5; i++){
        array[i].ekranaYaz(); // 1
        (pArray + i)->ekranaYaz(); // 2
    }


    // işaretçilerde -> ile erişiyoruz
    n3->ekranaYaz();

    n4->degerAta(9,9);
    n4->ekranaYaz();

    return 0;
}