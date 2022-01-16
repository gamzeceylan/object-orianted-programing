#include <iostream>
using namespace std;

class Kolon{
    int* data; // veri kumesinin kac elemanli olacagini bilmedigimizden dinamik bellek ile yonetecegiz
    int boyut; // veri kumesinin boyutu

    public:
        Kolon(int boyut=1): boyut(boyut){
            data = new int[boyut];
        //    cout << "kurucu calisti\n";
        }

        Kolon(const Kolon& k){
            this->boyut = k.boyut;
            data = new int[boyut];
            for(int i=0; i<boyut; i++)
                data[i] = k.data[i];
            
          //  cout << "kopyalama kurucusu calisti\n";
        }

        ~Kolon(){ 
          //  cout << "yikici calisti\n"; 
            delete[] data; // data dizi turunde oldugu icin silerken tum alanları iade etmemiz gerek
            
        }

        void set(int indis, int value){
            if(indis<boyut){
                data[indis] = value;
            }
        }

        int getBoyut(){ return boyut; }
        void setBoyut(int boyut){ this->boyut = boyut; }

        const int* getData()const{ return data; } // geri donus degeri de sonradan degistirilemeyecek, sabit bir deger olarak doner

        void print()const{
            for(int i=0; i<boyut; i++)
                cout << data[i] << " ";
            
            cout << endl;
        }

        Kolon topla(const Kolon& k){
            if(boyut == k.boyut){
                Kolon temp(boyut);
               // temp.boyut = boyut;
                for(int i=0; i<boyut; i++){
                    temp.data[i] = data[i] + k.data[i];
                }
                return temp;
            }
           
        }

        Kolon carp(const Kolon& k)const{
            if(boyut == k.boyut){
                Kolon temp(boyut);
               // temp.boyut = boyut;
                for(int i=0; i<boyut; i++){
                    temp.data[i] = data[i] * k.data[i];
                }
                return temp;
            }
        }
        double ortalama()const{
            double toplam=0;
            for(int i=0; i<boyut; i++){
                toplam += data[i];
            }
            return toplam / boyut;
        }


};

int main(){
    Kolon k1(3);
    k1.set(0,5);
    k1.set(1,4);
    k1.set(2,1);
    k1.print();

    Kolon k2 (3);
    k2.set(0,1);
    k2.set(1,2);
    k2.set(2,3);
    k2.print();

    cout <<endl << endl;

    (k1.carp(k2)).print();
    (k1.topla(k2)).print();
    
    cout << k1.ortalama();
    return 0;
}