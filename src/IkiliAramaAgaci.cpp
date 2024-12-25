/** 
 * @file IkiliAramaAgaci.cpp
 * @description Satırlardan oluşturulan ikili arama ağaçlarını bağlı liste ile birbirine bağlama ve ağaçlar üzerinde işlemler yapma
 * @course 1. Öğretim C Grubu
 * @assignment 2
 * @date 24.12.2024
 * @author Seray Eğe seray.ege@ogr.sakarya.edu.tr
 */

#include "IkiliAramaAgaci.hpp"
#include <iostream>
#include <cmath>

using namespace std;

IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok=nullptr;
} 

IkiliAramaAgaci::~IkiliAramaAgaci() {
    temizle(kok);
    kok=nullptr;
}

void IkiliAramaAgaci::temizle(Dugum* dugum) {
    
     if (dugum != nullptr) {
        //cout << "Siliniyor: " << dugum << endl;
        temizle(dugum->sol);
        temizle(dugum->sag);
        delete dugum;
        dugum=nullptr;
    }
}

void IkiliAramaAgaci::ekle(Dugum*& current, char eklenecek) 
{
    if (current == nullptr) {
        current = new Dugum(eklenecek);
        return;
    }

    if (eklenecek < current->veri) {
        ekle(current->sol, eklenecek);
    } else if (eklenecek > current->veri) {
        ekle(current->sag, eklenecek);
    }
}

void IkiliAramaAgaci::ekle(char eklenecek) 
{
    ekle(kok, eklenecek);
}

int IkiliAramaAgaci::yukseklik(Dugum* current) const 
{
    if (current == nullptr) return 0;
    return 1 + max(yukseklik(current->sol), yukseklik(current->sag));
}

void IkiliAramaAgaci::yazdirSeviye(Dugum* current, int seviye, int bosluk, bool sagHizala) const 
{ 
    if (current == nullptr) {
        cout << string(bosluk, ' ');
        return;
    }
    if (seviye == 1) {
        cout << string(bosluk / 3, ' ') << current->veri << string(bosluk / 3, ' ');
    } else if (seviye > 1) {
        yazdirSeviye(current->sol, seviye - 1, bosluk / 2);
        yazdirSeviye(current->sag, seviye - 1, bosluk / 2, true);
    }
    
}

void IkiliAramaAgaci::yazdir() const 
{
    int h = yukseklik(kok);
    int bosluk = pow(2, h + 1);
    // int bosluk=3;

    for (int i = 1; i <= h; i++) {
        yazdirSeviye(kok, i, bosluk);
        cout << endl;
    }
}

int IkiliAramaAgaci::toplamHesapla()
{
    return toplamHesapla(kok, true); // sol taraf kök
}

int IkiliAramaAgaci::toplamHesapla(Dugum* dugum, bool solTaraf)
{   
    if (dugum == nullptr) return 0; // düğüm yoksa 

    int solToplam = toplamHesapla(dugum->sol, true);   
    int sagToplam = toplamHesapla(dugum->sag, false);  

    int katsayi = solTaraf ? 2 : 1; // sol için 2 sağ için 1 katsayı

    if(dugum==kok)
    {
        katsayi=1;
    }

    return (dugum->veri * katsayi) + solToplam + sagToplam;
}

void IkiliAramaAgaci::aynala(Dugum* dugum) {
        if (dugum == nullptr) return;

        // ağacın sol ve sağ alt ağaçlarını yer değiştir
        Dugum* temp = dugum->sol;
        dugum->sol = dugum->sag;
        dugum->sag = temp;

        // aynala
        aynala(dugum->sol);
        aynala(dugum->sag);
}