/*
    private olan alanlara disaridan kontrollu erisim saglariz. böylece sinif kontrolunu kaybetmeyiz.
    istersek deger atamayi kapatir, sadece disaridan okumayi acariz. boylece disaridan degistirilemeyecegini garanti ederiz.
    getter metod: private olan ozelligi cagirmak
    setter metod: private olan ozelligi disaridan degistirmek
*/

#include<iostream>
using namespace std;

class Nokta{
    private:
        int x,y;

    public:
        // get metodlar
        int getX();
        int getY();

        // set metodlar
        void setX(int);
        void setY(int);

        void ekranaYaz();
        bool baslangictaMi();


};


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

bool Nokta::baslangictaMi(){
    return x==0 && y==0;
}

int main(){     
    Nokta n1;
    
    n1.setX(10);
    n1.setY(6);
    cout << n1.getX() << "," << n1.getY();
    
   
    return 0;
}