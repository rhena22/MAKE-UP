#include <iostream>
#include <iomanip>
#include "Catalog.h"
#include "ProductTree.h"
#include "BrandList.h"
#include "Input.h"
#include "Display.h"
#include "Menus.h"
#include "Cleanup.h"
using namespace std;

int main() {
    cout << fixed << setprecision(2);
    seedCatalog();
    rebuildTree();
    buildBrands();

    while (true) {
        cout << "\n=============== MAKE-UP INVENTORY & SEARCH SYSTEM (CS201) ===============\n"
             << " 1. View Complete Catalog\n 2. Filter by Brand\n 3. Search (Keyword / ID)\n"
             << " 4. Filter by Price Range (Binary Search)\n 5. Shopping Cart (Doubly Linked List)\n"
             << " 6. Checkout Queue (FIFO)\n 7. Admin Add / Undo (Stack)\n"
             << " 8. Brand Banner Showcase (Circular List)\n 9. Sort Inventory\n10. Exit\n";
        int c = askInt("Choice: ", 1, 10);
        if (c == 1) printTable(catalog, numProducts);
        else if (c == 2) filterByBrand();
        else if (c == 3) searchMenu();
        else if (c == 4) priceRange();
        else if (c == 5) cartMenu();
        else if (c == 6) checkoutMenu();
        else if (c == 7) adminMenu();
        else if (c == 8) showBanner();
        else if (c == 9) sortView();
        else break;
    }
    cleanup();
    cout << "Goodbye!\n";
    return 0;
}
