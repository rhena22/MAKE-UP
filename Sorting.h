#ifndef SORTING_H
#define SORTING_H
#include "Product.h"

// LAB 8: Sorting
void insertionSortByBrand(Product* a, int n);
void quickSort(Product* a, int lo, int hi, int mode);   // mode 1 = price, 2 = stock
#endif
