#include <iostream>
using namespace std;
/*
    kalitim alinan sinif = taban sinif (insan)
    yeni turetilen sinif = turetilmis sinif (ogrenci)

    public: main ve turetilen sinifa acik
    protected: sadece turetilen sinifa acik
    private: sadece o sinifa acik
*/

class Insan{
    protected:
        string tc;
        string isim;
        string soyisim;

    public:
        Insan(string tc="", string isim="", string soyisim=""): tc(tc), isim(isim), soyisim(soyisim){}
        string getTc(){ return tc; }
        string getIsim(){ return isim; }
        string getSoyisim(){ return soyisim; }
        void setTc(string tc){ this->tc = tc; }
        void setIsim(string isim){ this->isim = isim; }
        void setSoyisim(string soyisim){ this->soyisim = soyisim; }

    


};
class Ogrenci: public Insan{
    private:
        string ogrenciNo;
    public:
        Ogrenci(string ogrenciNo="", string tc="", string isim="", string soyisim=""): ogrenciNo(ogrenciNo), Insan(tc,isim,soyisim){}
        string getOgrenciNo(){ return ogrenciNo; }
        void setOgrenciNo(string ogrenciNo){ this->ogrenciNo; }

        void Yazdir(){
            cout << ogrenciNo << "," << tc << ","<< isim<<"," << soyisim<< endl; // protedted alanlara erisebiliyoruz
        }

};

int main(){
    Insan Ali("1234567", "Ali", "Yilmaz");
    cout << Ali.getIsim() << endl;

    Ogrenci Gamze("b121", "456789902", "Gamze", "Ceylan");
    cout << Gamze.getIsim() << endl << Gamze.getOgrenciNo() << endl;


    /*
        ////// Isim gizleme /////

        NOT: Insan sinifinin 3 string alani oldugundan bellekte 3*24 kaplar.
        Ogrenci sinifinin 1 string alani var ama arka planda Insan'dan kalitim aldigi icin
        insan ozellikleri ogrenci icin de tanimlanir bu yüzden 4*24 luk yer kaplar
    */
    cout << sizeof(string) << endl; // 24 byte
    cout << sizeof(Insan) << endl; // 3*24 = 72 byte
    cout << sizeof(Ogrenci) << endl; // 4*24 = 96 byte

    return 0;
}