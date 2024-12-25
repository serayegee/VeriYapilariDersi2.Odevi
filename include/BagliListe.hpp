#ifndef BAGLILISTE_HPP
#define BAGLILISTE_HPP

#include "AgacDugum.hpp"

class BagliListe {
public:
    BagliListe();
    ~BagliListe();

    void ekle(const std::string& satir); // Satırdan bir ağaç oluştur ve listeye ekle
    void yazdir(int numara) const;       // Belirli bir numaradaki ağacı yazdır
    void yazdirListe() const;
    void currentDugum();
    AgacDugum* getBas() const;
    void toplamDegerleriYazdir();
    int getBoyut() const;
    void sil(int indeks);
    void dugumSil(int indeks);

private:
    AgacDugum* bas; // Listenin başını işaret eder
};

#endif
