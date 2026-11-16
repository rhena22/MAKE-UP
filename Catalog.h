#ifndef CATALOG_H
#define CATALOG_H
#include "Product.h"

// LAB 1: Dynamic array (grows when full)
extern Product* catalog;
extern int numProducts, capacity, nextId;

void addProduct(Product p);
void seedCatalog();   // loads the 20 starting products
#endif
