/** 
 * @file Dugum.cpp
 * @description Satırlardan oluşturulan ikili arama ağaçlarını bağlı liste ile birbirine bağlama ve ağaçlar üzerinde işlemler yapma
 * @course 1. Öğretim C Grubu
 * @assignment 2
 * @date 24.12.2024
 * @author Seray Eğe seray.ege@ogr.sakarya.edu.tr
 */

#include "Dugum.hpp"
#include <iomanip>
#include <iostream>

Dugum::Dugum(char v)
{
    veri=v;
    sol=nullptr;
    sag=nullptr;
}