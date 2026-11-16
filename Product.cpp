#include "Product.h"
using namespace std;

const string BRANDS[4] = {"ISSY", "BLK Cosmetics", "Careline", "GRWM Cosmetics"};

Product makeProduct(int id, string name, string cat, string brand, double price, int stock) {
    Product p;
    p.id = id; p.name = name; p.category = cat;
    p.brand = brand; p.price = price; p.stockQuantity = stock;
    return p;
}
