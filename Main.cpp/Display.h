#ifndef DISPLAY_H
#define DISPLAY_H
#include "Product.h"

void printHeader();
void printRow(const Product& p);
void printTable(Product* a, int n);
int chooseBrand();   // returns 0..3
#endif
