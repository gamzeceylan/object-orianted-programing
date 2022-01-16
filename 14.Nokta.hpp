// fonsiyon prototiplerini oldugu dosya -> header dosyasi

#ifndef _NOKTA_HPP_ // bu dosyanin sadece bir kere tanimlanmasini kontrol eder
#define _NOKTA_HPP_

#include<iostream> // friend'deki ostream isim uzayi icin
class Nokta{
    private:
        int x,y;


    public:
        int* z;
        const int t;
        Nokta();
        Nokta(int,int,int);
        Nokta(const Nokta&); // copy contructor
        ~Nokta();

        // get metodlar
        int getX()const;
        int getY()const;

        // set metodlar
        void setX(int);
        void setY(int);

        void ekranaYaz();
        friend std::ostream& operator << (std::ostream& , Nokta& );

};
#include"14.Nokta.cpp" // methodlarin oldugu yer. derleme sirasinda iki dosyayi birlestirmesi icin ekledik
/*
    NOT: eger sen bir proje dosyasi olusturursan, visual studio ya da devc++ gibi idelerde, proje dosyasi altina proje agaci olusur.
    source ve header dosyalari yazdiginda da derleyici senin icin hepsini birlestirme islemi yapar. ve yukaridaki #include"14.Nokta.cpp" 
    yazarsan iki kere birlestirme olacagi icin linker ya da redefination hatalari alirsin. ama bu bir proje dosyasi degilse bu sekilde kendin birlestirme
    yapman gerekir

*/
#endif
