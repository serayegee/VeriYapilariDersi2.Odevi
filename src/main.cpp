/** 
 * @file main.cpp
 * @description Satırlardan oluşturulan ikili arama ağaçlarını bağlı liste ile birbirine bağlama ve ağaçlar üzerinde işlemler yapma
 * @course 1. Öğretim C Grubu
 * @assignment 2
 * @date 24.12.2024
 * @author Seray Eğe seray.ege@ogr.sakarya.edu.tr
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "BagliListe.hpp"

using namespace std;


// çıktı için kullanılan fonksiyonlar
int boslukMiktari=3;

void cizgiYaz()
{
	for(int i=0;i<boslukMiktari;i++)
		cout<<" ";
	cout<<"********";
}

void degerYaz(const string& deger)
{
    for (int i = 0; i < boslukMiktari; i++)
        cout << " ";
    cout << "*";
    cout << setw(6) << deger;
    cout << "*";
}

void degerYaz1(int deger)
{
	for(int i=0;i<boslukMiktari;i++)
		cout<<" ";
	cout<<"*";
    cout<<setw(6)<<deger;
    cout<<"*";
}

void satirCiz()
{
    for(int i=0;i<10;i++)
    cizgiYaz();
}

string adresYaz(void* adres) {
    // adresi string olarak almak için
    ostringstream oss;
    oss << adres; 

    string tamAdres = oss.str();

    // adresin son 4 karakterini yazdırmak için
    if (tamAdres.length() > 5) {
        return tamAdres.substr(tamAdres.length() - 5);
    }
    return tamAdres; // adres kısa ise adresi kısaltmadan döndür
}

string isaretYaz(int indeks)
{
    if(indeks!=0)
    {
        for(int i=0;i<indeks;i++)
        {
            for(int i=0;i<boslukMiktari;i++)
		        cout<<" ";
            cout<<"        ";
        }
    }
        for(int i=0;i<boslukMiktari;i++)
		cout<<" ";
	cout<<"^^^^^^^^";
}


int main() {
    BagliListe liste;
    ifstream dosya("agaclar.txt");
    string satir;

    // Dosyadan satırları oku ve listeye ekle
    while (getline(dosya, satir)) {
        liste.ekle(satir);
    }
    dosya.close();

    int indeks=0;
    int sayfaBaslangic=0;
    const int sayfaBoyutu=10;
    int toplamDugumSayisi=liste.getBoyut();
    AgacDugum* current = liste.getBas();

    while(true)
    {

    system("cls");

    cout<<endl;
    satirCiz();
    cout << endl;

    current = liste.getBas();
    for (int i = 0; i < sayfaBaslangic && current != nullptr; i++) {
        current = current->sonraki;
    }


    AgacDugum* temp = current;
        for (int i = 0; i < sayfaBoyutu && temp != nullptr; i++) {
            degerYaz(adresYaz(temp));
            temp = temp->sonraki;
        }

    cout << endl;
    satirCiz();


    temp = current;
    cout << endl;

    for (int i = 0; i < sayfaBoyutu && temp != nullptr; i++) {
        degerYaz1(temp->agac->toplamHesapla());
        temp = temp->sonraki;

    }

    cout<<endl;
    satirCiz();

    temp = current;
    cout << endl;
    for (int i = 0; i < sayfaBoyutu && temp != nullptr; i++) {
        if (temp->sonraki != nullptr) {
            degerYaz(adresYaz(temp->sonraki));
        } else {
            degerYaz("NULL");
        }
        temp = temp->sonraki;
    }
    cout << endl;
    satirCiz();
    cout<<endl;

    isaretYaz(indeks);
    cout<<endl;

    // ağaç yazdırma
    temp = liste.getBas();
        for (int i = 0; i < (sayfaBaslangic + indeks) && temp != nullptr; i++) {
            temp = temp->sonraki;
        }

        if (temp != nullptr) {
            temp->agac->yazdir(); // seçili düğümün ağacını yazdır
        } else {
            cout << "\nSecili agac bos...\n";
        }


    cout << "Secim...: ";
    string secim;
    getline(cin, secim); // kullanıcıdan seçim için giriş al

    if (secim == "x") {
        break; // döngüyü sonlandır
    } else if (secim == "d") {
        indeks++; // enter'a basıldığında işareti ilerlet

        if (indeks >= sayfaBoyutu) {
                indeks = 0;
                sayfaBaslangic += sayfaBoyutu;

                // başlangıç toplam düğüm sayısını aşarsa başa dön
                if (sayfaBaslangic >= toplamDugumSayisi) {
                    sayfaBaslangic = 0;
                }
              
            }
           
    }
    else if (secim == "a") {
        if (indeks > 0) {
        indeks--; // sayfadaki bir önceki öğeye git
    } else {
        // indeks sıfırsa sayfayı değiştir
        if (sayfaBaslangic > 0) {
            sayfaBaslangic -= sayfaBoyutu; // önceki sayfa
            indeks = sayfaBoyutu - 1; // önceki sayfanın son elemanına git
        }
    }

    }

    else if (secim == "w") {

        if(current==nullptr)
        {
            cout << "\nSecili dugum bulunamadi.\n";
        }

        current->agac->aynala(current->agac->kok);  // seçili ağacın aynalanması
        current->agac->yazdir(); // aynalanmış ağacın yazdırılması

        cout << endl;
    }
    
    else if (secim == "s") {
            int silinecek = sayfaBaslangic + indeks;
            liste.sil(silinecek);

            toplamDugumSayisi = liste.getBoyut();
            if (toplamDugumSayisi == 0) {
                cout << "Liste bos\n";
                break;
            }

            if (indeks >= toplamDugumSayisi - sayfaBaslangic) {
                indeks--;
                if (indeks < 0 && sayfaBaslangic > 0) {
                    sayfaBaslangic -= sayfaBoyutu;
                    indeks = sayfaBoyutu - 1;
                }
            }
    }
    
    }

    return 0;
}


