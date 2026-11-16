#ifndef BRANDLIST_H
#define BRANDLIST_H
#include <string>

// LAB 3: Circular linked list (brand banners)
struct BrandNode {
    std::string name;
    BrandNode* next;
    BrandNode(std::string n) : name(n), next(0) {}
};

extern BrandNode *brandFirst, *brandCur;

void buildBrands();
void freeBrands();
#endif
