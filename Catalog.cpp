#include "Catalog.h"
#include <iostream>
using namespace std;

Product* catalog = new Product[4];
int numProducts = 0, capacity = 4, nextId = 1;

void addProduct(Product p) {
    if (numProducts == capacity) {                // full -> make a bigger array
        Product* bigger = new Product[capacity * 2];
        for (int i = 0; i < numProducts; i++) bigger[i] = catalog[i];
        delete[] catalog;
        catalog = bigger;
        capacity *= 2;
        cout << "[Lab 1] Catalog grew to " << capacity << " slots\n";
    }
    catalog[numProducts++] = p;
}

static void seed(string name, string cat, int b, double price, int stock) {
    addProduct(makeProduct(nextId++, name, cat, BRANDS[b], price, stock));
}

void seedCatalog() {
    seed("Matte Lip Tint", "Lips", 0, 199, 50);        seed("Cushion Foundation", "Face", 0, 499, 30);
    seed("Brow Pencil", "Eyes", 0, 179, 40);           seed("Blush Stick", "Cheeks", 0, 249, 35);
    seed("Loose Setting Powder", "Face", 0, 299, 25);
    seed("Hydra Lip Gloss", "Lips", 1, 189, 60);       seed("Liquid Concealer", "Face", 1, 229, 45);
    seed("Waterproof Mascara", "Eyes", 1, 249, 38);    seed("Cheek Tint", "Cheeks", 1, 199, 42);
    seed("Eyeshadow Palette", "Eyes", 1, 399, 20);
    seed("Liquid Eyeliner", "Eyes", 2, 129, 70);       seed("Creamy Lipstick", "Lips", 2, 149, 55);
    seed("Compact Powder", "Face", 2, 169, 48);        seed("Lip Balm SPF15", "Lips", 2, 99, 80);
    seed("BB Cream", "Face", 2, 199, 33);
    seed("Glow Primer Serum", "Face", 3, 349, 28);     seed("Velvet Lip Cream", "Lips", 3, 219, 44);
    seed("Highlighter Palette", "Cheeks", 3, 329, 22); seed("Lengthening Mascara", "Eyes", 3, 259, 36);
    seed("Makeup Setting Spray", "Face", 3, 279, 30);
}
