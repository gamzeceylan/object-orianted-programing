#include <iostream>
using namespace std;

class Nokta{
    // bir belirteç yazmazsak private olur
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
    Nokta n1; // siniftan model olusturduk
    Nokta n2;
    n1.degerAta(5,10);
    n1.ekranaYaz();

    n2.degerAta(0,0);
    n2.ekranaYaz();

    if(n1.baslangicMi())
        cout << "n1 baslangic noktasinda";

    if(n2.baslangicMi())
        cout << "n2 baslangic noktasinda";
   

    return 0;
}