#include "Display.h"
#include "Input.h"
#include <iostream>
#include <iomanip>
using namespace std;

void printHeader() {
    cout << string(72, '-') << "\n" << left << setw(5) << "ID" << setw(24) << "Product"
         << setw(9) << "Category" << setw(16) << "Brand" << right << setw(10) << "Price" << setw(8) << "Stock"
         << "\n" << string(72, '-') << "\n";
}
void printRow(const Product& p) {
    cout << left << setw(5) << p.id << setw(24) << p.name << setw(9) << p.category << setw(16) << p.brand
         << right << setw(10) << p.price << setw(8) << p.stockQuantity << "\n";
}
void printTable(Product* a, int n) {
    printHeader();
    for (int i = 0; i < n; i++) printRow(a[i]);
    cout << string(72, '-') << "\n" << n << " product(s)\n";
}
int chooseBrand() {
    for (int i = 0; i < 4; i++) cout << "  " << i + 1 << ". " << BRANDS[i] << "\n";
    return askInt("Brand (1-4): ", 1, 4) - 1;
}
