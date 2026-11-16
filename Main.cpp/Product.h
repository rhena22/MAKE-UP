#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

struct Product {
    int id;
    std::string name, category, brand;
    double price;
    int stockQuantity;
};

extern const std::string BRANDS[4];

Product makeProduct(int id, std::string name, std::string cat, std::string brand, double price, int stock);
#endif
