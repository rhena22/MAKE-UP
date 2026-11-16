#include "BrandList.h"
#include "Product.h"
using namespace std;

BrandNode *brandFirst = 0, *brandCur = 0;

void buildBrands() {
    BrandNode* last = 0;
    for (int i = 0; i < 4; i++) {
        BrandNode* n = new BrandNode(BRANDS[i]);
        if (last) last->next = n; else brandFirst = n;
        last = n;
    }
    last->next = brandFirst;                      // last points back to first = circle
    brandCur = brandFirst;
}
void freeBrands() {
    if (!brandFirst) return;
    BrandNode* last = brandFirst;
    while (last->next != brandFirst) last = last->next;
    last->next = 0;                               // break the circle, then delete
    while (brandFirst) { BrandNode* d = brandFirst; brandFirst = d->next; delete d; }
    brandCur = 0;
}
