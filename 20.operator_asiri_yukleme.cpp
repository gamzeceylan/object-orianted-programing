/*
    overloading islemi yapilabilen operatorler: +, -, *, /, ++, --, ()
    overloading islemi yapilamayan operatorler: ^, ., ::, ?:, sizeof()

    - operatorlerin islem onceligi degisritilemez
    - aldiklari parametre sayilari degistirilemez
    - program okunurlugunu kolaylastirmak icin kullanilir

    NOT: kopyalama kurucusu tanimlama zamaninda, atama operatoru tanimlamanin haricinde herhangi bir 
    yerde atama yapildiginda calisir.

        Kolon k1=k2; // kopyalama calisti

        Kolon k1;
        k1=k2; // atama calisti



    NOT: k3=k2=k1;  atama sagdan sola dogru yapilir. k2=k1 de atama overloading calisir. bu fonksiyon sonucunun Kolon
    turunden bir deger return etmesi lazim ki k3 e atanabilsin. eger atama overloading void olursa derleyici k3=void 
    atamasini yapmaya calisir, hata verir.

        Kolon operator=(const Kolon& k){
          // islemler

          return *this;
        }

*/

#include <iostream>
using namespace std;

class Kolon{
    int* data; // veri kumesinin kac elemanli olacagini bilmedigimizden dinamik bellek ile yonetecegiz
    int boyut; // veri kumesinin boyutu

    public:
        Kolon(int boyut=1): boyut(boyut){
            data = new int[boyut];
          //  cout << "kurucu calisti\n";
        }

        Kolon(const Kolon& k){
            this->boyut = k.boyut;
            data = new int[boyut];
            for(int i=0; i<boyut; i++)
                data[i] = k.data[i];
            
          //  cout << "kopyalama kurucusu calisti\n";

        /*
            *this = k; // this bir pointer, *this ile nesneye erisiyoruz.
             // atama asiri yuklemesini burada da cagirabiliriz
        */
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

        void ara(int value){
             for(int i=0; i<boyut; i++){
                data[i] +=value;
            }
        }

        ////////// toplama asiri yukleme
        Kolon operator+(const Kolon& k)const{
            if(boyut == k.boyut){
                Kolon temp(boyut);
                for(int i=0; i<boyut; i++){
                    temp.data[i] = data[i] * k.data[i];
                }
                return temp;
            }
        }

        ////////// atama asiri yukleme
        // derleyici default olarak cagirir
        // ama nesnelerin referanslari da ayni olur. eger bunu bunu istemeiyorsak kendimiz yazmaliyiz
        void operator=(const Kolon& k){
            delete[] data; // atamalarda bu referansi istemiyoruz. kendimiz yeni alan olusturucaz
            // cunku burada da yine kurucu fonksiyon calisacak

            boyut = k.boyut;
            data = new int[boyut];
            for(int i=0; i<boyut; i++){
                data[i] = k.data[i];
            }
 
        }

        ////////// indis asiri yukleme
        // geri donus tipi referans olmali??
        const int& operator[](int indis)const{
            if(indis>=0 && indis< boyut)
                return data[indis]; // burasini const yaptik. daha sonradan degistirilemez

        }

        ////////// parantez asiri yukleme
        // takas islemlerinde kullanilir
        void operator()(int i, int j)const{
            int temp = data[i];
            data[i]=data[j];
            data[j]=temp;
        }

        ////////// ++ asiri yukleme
        // (int) olmasi parametre alacagini degil, ++ operatorunun posfix olacagini derleyiciye bildirir
        void operator++(int){
            ara(1);
        }
        // () prefix olarak kullanilacak
        void operator++(){
            ara(2);
        }

        ////////// -- asiri yukleme
        // (int) olmasi parametre alacagini degil, ++ operatorunun posfix olacagini derleyiciye bildirir
        void operator--(int){
            ara(-1);
        }
        // () prefix olarak kullanilacak
        void operator--(){
           ara(-2);
        }

};

int main(){
    Kolon k1(3);
    k1.set(0,5);
    k1.set(1,4);
    k1.set(2,1);
    for(int i=0; i<3; i++){
        cout << k1[i] << " ";
    }
/*
    Kolon k2 (3);
    k2.set(0,1);
    k2.set(1,2);
    k2.set(2,3);
    k2.print();

    cout <<endl << endl;

    (k1.carp(k2)).print();
    (k1.topla(k2)).print();
    
    cout << k1.ortalama() << endl;

    (k1 + k2).print();
*/
    Kolon k3;
    k3 = k1;
    for(int i=0; i<3; i++){
        cout << k3[i] << " ";
    }

    cout << endl;
   // k3[1]=10;ü
    
    k1(0,1); // yer degisti
    for(int i=0; i<3; i++){
        cout << k1[i] << " ";
    }

    k1++; // posfix
    for(int i=0; i<3; i++){
        cout << k1[i] << " ";
    }

    ++k1; // prefix
    for(int i=0; i<3; i++){
        cout << k1[i] << " ";
    }

    
    k1--; // prefix
    for(int i=0; i<3; i++){
        cout << k1[i] << " ";
    }

    
    --k1; // prefix
    for(int i=0; i<3; i++){
        cout << k1[i] << " ";
    }


    return 0;
}

