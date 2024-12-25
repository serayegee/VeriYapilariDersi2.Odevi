/** 
 * @file BagliListe.cpp
 * @description Satırlardan oluşturulan ikili arama ağaçlarını bağlı liste ile birbirine bağlama ve ağaçlar üzerinde işlemler yapma
 * @course 1. Öğretim C Grubu
 * @assignment 2
 * @date 24.12.2024
 * @author Seray Eğe seray.ege@ogr.sakarya.edu.tr
 */

#include "BagliListe.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

BagliListe::BagliListe()
{
    bas=nullptr;
} 

BagliListe::~BagliListe() {
    AgacDugum* current = bas;
    while (current != nullptr) {
        AgacDugum* silinecek = current;
        current = current->sonraki;
        delete silinecek;
    }
}

void BagliListe::ekle(const std::string& satir) {
     AgacDugum* yeniDugum = new AgacDugum();
    for (char ch : satir) {
        yeniDugum->agac->ekle(ch);
    }

    if (bas == nullptr) {
        bas = yeniDugum;
    } else {
        AgacDugum* current = bas;
        while (current->sonraki != nullptr) {
            current = current->sonraki;
        }
        current->sonraki = yeniDugum;
    }
}


// kontrol ederek ilerleyebilmek için yazdığım fonksiyon
/*void BagliListe::yazdirListe() const {
    AgacDugum* current = bas;
    int index = 0;

    cout << "--------------------\n";
    cout << "Liste Durumu:\n";

    while (current != nullptr && index < 10) {
        cout << "Dugum Adresi: " << current << "\n";
        cout << "Dugumdeki Agac: \n";
        current->agac->yazdir(); // Ağacı yazdır
        cout << "Sonraki Dugum Adresi: " << current->sonraki << "\n";
        cout << "--------------------\n";

        current = current->sonraki;
        index++;
    }

    if (current != nullptr) {
        cout << "Devam ediyor...\n";
    } else {
        cout << "Liste sonuna ulasildi.\n";
    }
}*/

AgacDugum* BagliListe::getBas() const
{
    return bas;
}

void BagliListe::toplamDegerleriYazdir() {
    
    AgacDugum* temp = bas;
    int index = 1;
    while (temp != nullptr) {
         int toplamDeger = temp->agac->toplamHesapla();  
        //cout << "Dugum " << index << " Ağacinin Toplam Degeri: " << toplamDeger << endl;
        temp = temp->sonraki;  
        index++;
    
}
}

int BagliListe::getBoyut() const {
    int boyut = 0;
    AgacDugum* current = bas; 
    while (current != nullptr) {
        boyut++;
        current = current->sonraki; 
    }
    return boyut;
}


void BagliListe::sil(int indeks)
{
    if (bas == nullptr || indeks < 0) return; // liste boş veya geçersiz indeks

    AgacDugum* current = bas;
    AgacDugum* prev = nullptr;

    for (int i = 0; i < indeks; i++) {
        if (current == nullptr) return; 
        prev = current;
        current = current->sonraki;
    }

    if (prev == nullptr) {
        // baş düğüm
        bas = current->sonraki;
    } else {
        // son düğüm
        prev->sonraki = current->sonraki;
    }

    // ağacı ve düğümü temizle
    delete current;
    current=nullptr;
        
}

