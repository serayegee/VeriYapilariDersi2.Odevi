/** 
 * @file AgacDugum.cpp
 * @description Satırlardan oluşturulan ikili arama ağaçlarını bağlı liste ile birbirine bağlama ve ağaçlar üzerinde işlemler yapma
 * @course 1. Öğretim C Grubu
 * @assignment 2
 * @date 24.12.2024
 * @author Seray Eğe seray.ege@ogr.sakarya.edu.tr
 */

#include "AgacDugum.hpp"

AgacDugum::AgacDugum()
{
    agac=new IkiliAramaAgaci();
    sonraki=nullptr;
}

AgacDugum::~AgacDugum() {
    delete agac; 
}

