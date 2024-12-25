#ifndef IKILIARAMAAGACI_HPP
#define IKILIARAMAAGACI_HPP
#include "Dugum.hpp"

class IkiliAramaAgaci
{
	public:
	IkiliAramaAgaci();
	~IkiliAramaAgaci();
	void ekle(char eklenecek);
	void yazdir() const;
	int toplamHesapla();
    int toplamHesapla(Dugum* dugum, bool solTaraf);
	void yazdirNokta() const;
	void yazdirSeviyeGuncellenmis(Dugum* current, int seviye, int bosluk) const;
	void yazdirGuncellenmis() const;
	void aynala(Dugum* dugum);
	Dugum* kok;


	private:
	void ekle(Dugum*& current, char eklenecek);
	int yukseklik(Dugum* current) const;
	void yazdirSeviye(Dugum* current, int seviye, int bosluk, bool sagHizala = false) const;
	void yazdirNokta(Dugum* dugum, int boslukMiktari) const;
	void temizle(Dugum* dugum);

};

#endif