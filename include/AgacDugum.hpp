#ifndef AGACDUGUM_HPP
#define AGACDUGUM_HPP
#include "IkiliAramaAgaci.hpp"
#include <iostream>
using namespace std;

class AgacDugum
{
public:
    IkiliAramaAgaci* agac;
    AgacDugum* sonraki;  

    AgacDugum();
    ~AgacDugum();
    int degerHesapla();
};
#endif