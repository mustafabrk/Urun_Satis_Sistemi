#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
 
using namespace std;
//Class Kira baþladý.
class Kira {
public:
 string Ad;
 string urunadi;
 int Barkodno;
 string Tarih;
 
 void KiraGir();
 void KiraYazdir();
} ;
 
void Kira::KiraGir() {
 cout.setf(ios::right);
 cout<<"Urunu alanin Adi..:";
 cin>>Ad;
 cout<<"Urunun Adi..:";
 cin>>urunadi;
 cout<<"Urunun barkod nosu..:";
 cin>>Barkodno;
 cout<<"Alinma tarihi :";
 cin>>Tarih;
}
 
 
void Kira::KiraYazdir() {
 cout.setf(ios::right);
 cout<<"Urunu alanin Adi.."<<Ad<<endl;
 cout<<"Urunun Adi..:"<<urunadi<<endl;
 cout<<"Urunun barkod nosu..:"<<Barkodno<<endl;
 cout<<"Alinma tarihi :"<<Tarih<<endl;
 cout<<"**************************************"<<endl;
}
 
//Class Urun bitti.
//Class Kira baþladý.
 
class Urun {
public:
 string Ad;
 string Marka;
 string Madeby;
 float fiyat;
 int Barkodno;
 
 void UrunGir();
 void UrunYazdir();
} ;
 
void Urun::UrunGir() {
 cout.setf(ios::right);
 cout<<"Urunun Adi..:";
 cin>>Ad;
 cout<<"Urunun Markasi..:";
 cin>>Marka;
 cout<<"Urunun Uretildigi yer..:";
 cin>>Madeby;
 cout<<"Urunun Fiyati..:";
 cin>>fiyat;
 cout<<"Urunun barkod nosu..:";
 cin>>Barkodno;
 
}
 
 
void Urun::UrunYazdir() {
 cout.setf(ios::right);
 cout<<"Urunun Adi..:"<<Ad<<endl;
 cout<<"Urunun Markasi..:"<<Marka<<endl;
 cout<<"Urunun Uretildigi Yer..:"<<Madeby<<endl;
 cout<<"Urunun Fiyati..:"<<fiyat<<endl;
 cout<<"Urunun barkod nosu..:"<<Barkodno<<endl;
 cout<<"**************************************"<<endl;
}
 
//Class Kira bitti. 
//Class Depo basladi.

class Depo {
private:
fstream dosya;
fstream yedek;
fstream kira;
 
void KiraAc() {
 kira.open("kira.txt",ios::out|ios::in|ios::app);
 kira.setf(ios::left);
}
 
void KiraKapat() {
 kira.close();
}
void DosyaAc() {
 dosya.open("kayit.txt",ios::out|ios::in|ios::app);
 dosya.setf(ios::left);
}
 
void YedekAc() {
 yedek.open("yedek.txt",ios::out|ios::in|ios::app);
 yedek.setf(ios::left);
}
 
void DosyaKapat() {
 dosya.close();
}
 
void YedekKapat() {
 yedek.close();
}
 
 
void UrunOkuDosyadan(Urun &temp) {
 dosya>>temp.Ad;
 dosya>>temp.Marka;
 dosya>>temp.Madeby;
 dosya>>temp.fiyat;
 dosya>>temp.Barkodno;
}
 
void UrunYazDosyaya(Urun &K) {
 dosya<<endl
 <<setw(30)<<K.Ad
 <<setw(30)<<K.Marka
 <<setw(30)<<K.Madeby
 <<setw(30)<<K.fiyat
 <<setw(30)<<K.Barkodno;
 
}
 
void UrunOkuKiradan(Kira &temp) {
 kira>>temp.Ad;
 kira>>temp.urunadi;
 kira>>temp.Barkodno;
 kira>>temp.Tarih;
}
 
void UrunYazKiraya(Kira &K) {
 kira<<setw(30)<<K.Ad
 <<setw(30)<<K.urunadi
 <<setw(30)<<K.Barkodno
 <<setw(30)<<K.Tarih
 <<endl;
 
}
 
void UrunYazYedek(Urun &K) {
 yedek<<setw(30)<<K.Ad
 <<setw(30)<<K.Marka
 <<setw(30)<<K.Madeby
 <<setw(30)<<K.fiyat
 <<setw(30)<<K.Barkodno<<endl;
}
 
void KiraYazYedek(Kira &K) {
 yedek<<setw(30)<<K.Ad
 <<setw(30)<<K.urunadi
 <<setw(30)<<K.Barkodno
 <<setw(30)<<K.Tarih
 <<endl;
}
 
 
public:
Urun K;
Kira L;
int sayac;
 
Depo() {
 UrunGoster();
 system("cls");
}
 
 
void KiraEkle() {
 KiraAc();
 L.KiraGir();
 UrunYazKiraya(L);
 KiraKapat();
}

void UrunEkle() {
 DosyaAc();
 K.UrunGir();
 UrunYazDosyaya(K);
 DosyaKapat();
 sayac++;
}
 
int UrunBul(int Barkodno) {
 DosyaAc();
 Urun temp;
 
 for(int i=1;i<sayac;i++) {
 
UrunOkuDosyadan(temp);
 
if(temp.Barkodno==Barkodno) {
 temp.UrunYazdir();
 DosyaKapat();
 return 0;
 }
 }
 
DosyaKapat();
 cout<<"Aradiginiz barkod nolu Urun Bulunamadi\n\n";
 return 0;
}
void KiraGoster() {
 KiraAc();
 Kira temp;
 
 UrunOkuKiradan(temp);
 while(!dosya.eof()) {
 temp.KiraYazdir();
 UrunOkuKiradan(temp);
 }
 KiraKapat();
}
void UrunGoster() {
 sayac=0;
 DosyaAc();
 Urun temp;
 
 if(!dosya.eof())
 sayac++;
 
UrunOkuDosyadan(temp);
 while(!dosya.eof()) {
 temp.UrunYazdir();
 UrunOkuDosyadan(temp);
 sayac++;
 }
 DosyaKapat();
}
 
void UrunSayisi() {
 system("cls");
 cout<<"\nDeponuzdaki Urun sayisi "<<sayac-1<<" dir...\n\n";
}
 
void UrunSil(int Barkodno) {
 DosyaAc();
 YedekAc();
 Urun temp;
 
for(int i=1;i<sayac;i++) {
 
UrunOkuDosyadan(temp);
 
if(temp.Barkodno==Barkodno) {
 cout<<"Silmek istediginiz Urun Bulundu ve SILINDI\n\n";
 sayac--;
 }
 else {
 UrunYazYedek(temp);
 }
 }
 DosyaKapat();
 remove("kayit.txt");
 YedekKapat();
 rename("yedek.txt","kayit.txt");
}
void KiraSil(int Barkodno) {
 KiraAc();
 YedekAc();
 Kira temp;
 
for(int i=1;i<sayac;i++) {
 
UrunOkuKiradan(temp);
 
if(temp.Barkodno==Barkodno) {
 cout<<"Silmek istediginiz Urun Bulundu ve SILINDI\n\n";
 sayac--;
 }
 else {
 KiraYazYedek(temp);
 }
 }
 DosyaKapat();
 remove("kira.txt");
 YedekKapat();
 rename("yedek.txt","kira.txt");
}
void UrunSiralaBarkod() {
 DosyaAc();
 YedekAc();
 Urun temp[100];
 Urun gecici;
 
for(int i=0;i<sayac-1;i++) {
 
UrunOkuDosyadan(temp[i]);
 }
 
for(int i=0;i<sayac-1;i++) {
 for(int j=i+1;j<sayac-1;j++) {
 if(temp[j].Barkodno<temp[i].Barkodno) {
 gecici=temp[i];
 temp[i]=temp[j];
 temp[j]=gecici;
 }
 }
 }
 
 for(int i=0;i<sayac-1;i++) {
 UrunYazYedek(temp[i]);
 }
 
DosyaKapat();
 remove("kayit.txt");
 YedekKapat();
 rename("yedek.txt","kayit.txt");
 cout<<"Barkod no ya gore siralama islemi basariyla gerceklestirildi...\n\n";
}
 
 
void UrunSiralaAd() {
 
 DosyaAc();
 YedekAc();
 Urun temp[100];
 Urun gecici;
 
for(int i=0;i<sayac-1;i++) {
 
UrunOkuDosyadan(temp[i]);
 }
 
for(int i=0;i<sayac-1;i++) {
 for(int j=i+1;j<sayac-1;j++) {
 if(temp[j].Ad<temp[i].Ad) {
 gecici=temp[i];
 temp[i]=temp[j];
 temp[j]=gecici;
 }
 }
 }
 
 for(int i=0;i<sayac-1;i++) {
 UrunYazYedek(temp[i]);
 }
 
DosyaKapat();
 remove("kayit.txt");
 YedekKapat();
 rename("yedek.txt","kayit.txt");
 
cout<<"Ad a gore siralama islemi basariyla gerceklestirildi...\n\n";
}
void UrunSiralaMarka() {
 
 DosyaAc();
 YedekAc();
 Urun temp[100];
 Urun gecici;
 
for(int i=0;i<sayac-1;i++) {
 
UrunOkuDosyadan(temp[i]);
 }
 
for(int i=0;i<sayac-1;i++) {
 for(int j=i+1;j<sayac-1;j++) {
 if(temp[j].Marka<temp[i].Marka) {
 gecici=temp[i];
 temp[i]=temp[j];
 temp[j]=gecici;
 }
 }
 }
 
 for(int i=0;i<sayac-1;i++) {
 UrunYazYedek(temp[i]);
 }
 
DosyaKapat();
 remove("kayit.txt");
 YedekKapat();
 rename("yedek.txt","kayit.txt");
 cout<<"Markaya gore siralama islemi basariyla gerceklestirildi...\n\n";
}
 
void UrunSiralaMadeby() {
 
 DosyaAc();
 YedekAc();
 Urun temp[100];
 Urun gecici;
 
for(int i=0;i<sayac-1;i++) {
 
UrunOkuDosyadan(temp[i]);
 }
 
for(int i=0;i<sayac-1;i++) {
 for(int j=i+1;j<sayac-1;j++) {
 if(temp[j].Madeby<temp[i].Madeby) {
 gecici=temp[i];
 temp[i]=temp[j];
 temp[j]=gecici;
 }
 }
 }
 
 for(int i=0;i<sayac-1;i++) {
 UrunYazYedek(temp[i]);
 }
 
DosyaKapat();
 remove("kayit.txt");
 YedekKapat();
 rename("yedek.txt","kayit.txt");
 cout<<"Uretilen Yere gore siralama islemi basariyla gerceklestirildi...\n\n";
}
 
void UrunSiralaFiyat() {
 
 DosyaAc();
 YedekAc();
 Urun temp[100];
 Urun gecici;
 
for(int i=0;i<sayac-1;i++) {
UrunOkuDosyadan(temp[i]);
 }
 
for(int i=0;i<sayac-1;i++) {
 for(int j=i+1;j<sayac-1;j++) {
 if(temp[j].fiyat<temp[i].fiyat) {
 gecici=temp[i];
 temp[i]=temp[j];
 temp[j]=gecici;
 }
 }
 }
 
 for(int i=0;i<sayac-1;i++) {
 UrunYazYedek(temp[i]);
 }
 
DosyaKapat();
 remove("kayit.txt");
 YedekKapat();
 rename("yedek.txt","kayit.txt");
 cout<<"Fiyata gore siralama islemi basariyla gerceklestirildi...\n\n";
}
 
} ;
 
//Class Depo bitti.
//Class Menu baþladý.
class Menu {
public:
 
string myProducts();
string menu();
string kirala();
void about();
string sirala();
 
 
 
};
 
string Menu::menu() {
 string choice;
 cout<<"***********************************"<<endl;
 cout<<"* 1-Urunlerim *"<<endl;
 cout<<"* 2-Kiralama Islemleri *"<<endl;
 cout<<"* 3-Cikis *"<<endl;
 cout<<"***********************************"<<endl<<endl;
 cout<<"Bir secenek secin lutfen: ";
 cin>>choice;
 
return choice;
}
 
string Menu::kirala() {
 string choice;
 cout<<"***********************************"<<endl;
 cout<<"* 1-Kiraya ekle *"<<endl;
 cout<<"* 2-Kiradan sil *"<<endl;
 cout<<"* 3-Kiradakiler *"<<endl;
 cout<<"* *"<<endl;
 cout<<"***********************************"<<endl<<endl;
 cout<<"Bir secenek secin lutfen: ";
 cin>>choice;
 
return choice;
}
 
string Menu::myProducts() {
 string choice;
 cout<<endl;
 cout<<"**********************************"<<endl;
 cout<<"* 1-Ekle *"<<endl;
 cout<<"* 2-Bul *"<<endl;
 cout<<"* 3-Sil *"<<endl;
 cout<<"* 4-Sirala *"<<endl;
 cout<<"* 5-Listeyi Goster *"<<endl;
 cout<<"* 6-Urun sayisi *"<<endl;
 cout<<"* *"<<endl;
 cout<<"**********************************"<<endl<<endl;
 cout<<"Bir secenek secin lutfen: ";
 cin>>choice;

 return choice;
}
 
string Menu::sirala() {
 string choice;
 cout<<endl;
 cout<<"**********************************"<<endl;
 cout<<"* 1-Ada Gore *"<<endl;
 cout<<"* 2-Markaya Gore *"<<endl;
 cout<<"* 3-Uretilen Yere Gore *"<<endl;
 cout<<"* 4-Fiyata Gore *"<<endl;
 cout<<"* 5-Barkod nosuna Gore *"<<endl;
 cout<<"* *"<<endl;
 cout<<"**********************************"<<endl<<endl;
 cout<<"Bir secenek secin lutfen: ";
 cin>>choice;

 return choice; 
}
 
////Class Menu bitti.
 
int main() {
 
 Depo b;
 Menu m;
 
int Barkod;
 
for(;;) {
 string choice_m=m.menu();
 if (choice_m == "1") {
 choice_m=m.myProducts();
 if(choice_m == "1")
 b.UrunEkle();
 if(choice_m == "2") {
 cout<<"Bulmak istediginiz urunun barkod no sunu giriniz..";
 cin>>Barkod;
 b.UrunBul(Barkod);
 }
 if(choice_m == "3") {
 cout<<"Silmek istediginiz urunun barkod no sunu giriniz..";
 cin>>Barkod;
 b.UrunSil(Barkod);
 }
 
 if(choice_m=="5")
 b.UrunGoster();
 if(choice_m=="4") {
 choice_m=m.sirala();
 if(choice_m=="1")
 b.UrunSiralaAd();
 if(choice_m=="2")
 b.UrunSiralaMarka();
 if(choice_m=="3")
 b.UrunSiralaMadeby();
 if(choice_m=="4")
 b.UrunSiralaFiyat();
 if(choice_m=="5")
 b.UrunSiralaBarkod();
 }
 if(choice_m=="6")
 b.UrunSayisi();

}
 else if (choice_m=="2") {
 choice_m=m.kirala();
 if(choice_m=="1")
 b.KiraEkle();
 if(choice_m=="2") {
 cout<<"Silmek istediginiz urunun barkod no sunu giriniz..";
 cin>>Barkod;
 b.KiraSil(Barkod);
 }
 if(choice_m=="3")
 b.KiraGoster();
 
 }
 else if(choice_m=="3")
 exit(1);
 else {
 system("cls");
 cout<<"Yanlis bir giris yaptiniz"<<endl;
 cout<<"\nLutfen secenekteki numaralardan birisini giriniz...\n\n";
 }
 }
return 0;
}
