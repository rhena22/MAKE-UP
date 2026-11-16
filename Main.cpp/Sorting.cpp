#include "Sorting.h"
#include <algorithm>
using namespace std;

void insertionSortByBrand(Product* a, int n) {
    for (int i = 1; i < n; i++) {
        Product key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j].brand > key.brand) { a[j + 1] = a[j]; j--; }
        a[j + 1] = key;
    }
}
static double keyOf(const Product& p, int mode) {
    return mode == 1 ? p.price : p.stockQuantity;
}
void quickSort(Product* a, int lo, int hi, int mode) {
    if (lo >= hi) return;
    double pivot = keyOf(a[hi], mode);
    int i = lo - 1;
    for (int j = lo; j < hi; j++)
        if (keyOf(a[j], mode) <= pivot) { i++; swap(a[i], a[j]); }
    swap(a[i + 1], a[hi]);
    quickSort(a, lo, i, mode);
    quickSort(a, i + 2, hi, mode);
}
