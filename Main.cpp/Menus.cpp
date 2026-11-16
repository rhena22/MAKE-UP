#include "Menus.h"
#include "Product.h"
#include "Catalog.h"
#include "ProductTree.h"
#include "Cart.h"
#include "OrderQueue.h"
#include "UndoStack.h"
#include "BrandList.h"
#include "Sorting.h"
#include "Input.h"
#include "Display.h"
#include <iostream>
using namespace std;

void filterByBrand() {                            // option 2
    int b = chooseBrand();
    printHeader();
    for (int i = 0; i < numProducts; i++)
        if (catalog[i].brand == BRANDS[b]) printRow(catalog[i]);
}

void searchMenu() {                               // option 3
    if (askInt("1 = Keyword (Linear Search)  2 = Product ID (BST): ", 1, 2) == 1) {
        string key = toLower(askText("Keyword: "));
        printHeader();
        for (int i = 0; i < numProducts; i++) {   // linear: check every product
            Product& p = catalog[i];
            if (toLower(p.name + " " + p.brand + " " + p.category).find(key) != string::npos)
                printRow(p);
        }
    } else {
        int i = findById(askInt("Product ID: ", 1, 100000));
        if (i < 0) cout << "  Not found.\n"; else printTable(&catalog[i], 1);
    }
}

void priceRange() {                               // option 4
    int lo = askInt("Min price: ", 0, 100000), hi = askInt("Max price: ", 0, 100000);
    Product* a = new Product[numProducts];        // binary search needs sorted data
    for (int i = 0; i < numProducts; i++) a[i] = catalog[i];
    quickSort(a, 0, numProducts - 1, 1);
    int l = 0, r = numProducts;                   // binary search: first price >= lo
    while (l < r) { int m = (l + r) / 2; if (a[m].price < lo) l = m + 1; else r = m; }
    printHeader();
    for (int i = l; i < numProducts && a[i].price <= hi; i++) printRow(a[i]);
    delete[] a;
}

void cartMenu() {                                 // option 5
    while (true) {
        int c = askInt("\nCART: 1 Add  2 View/Navigate  3 Back: ", 1, 3);
        if (c == 3) return;
        if (c == 1) {
            int i = findById(askInt("Product ID: ", 1, 100000));
            if (i < 0) { cout << "  Not found.\n"; continue; }
            int avail = catalog[i].stockQuantity - qtyInCart(catalog[i].id);
            if (avail <= 0) { cout << "  Out of stock.\n"; continue; }
            int q = askInt("Quantity (max " + toStr(avail) + "): ", 1, avail);
            addToCart(catalog[i].id, q);
            cout << "  Added " << q << " x " << catalog[i].name << "\n";
        } else {
            while (cartHead) {
                for (CartNode* n = cartHead; n; n = n->next) {
                    Product& p = catalog[findById(n->id)];
                    cout << (n == cartCur ? " -> " : "    ") << p.name << " (" << p.brand << ") x" << n->qty << "\n";
                }
                string cmd = toLower(askText("[n]ext [p]rev [r]emove [b]ack: "));
                if (cmd == "n" && cartCur->next) cartCur = cartCur->next;
                else if (cmd == "p" && cartCur->prev) cartCur = cartCur->prev;
                else if (cmd == "r") removeCurrent();
                else if (cmd == "b") break;
            }
            if (!cartHead) cout << "  Cart is empty.\n";
        }
    }
}

void checkoutMenu() {                             // option 6
    while (true) {
        int c = askInt("\nCHECKOUT (" + toStr(qCount) + " waiting): 1 Place order  2 Process next  3 Back: ", 1, 3);
        if (c == 3) return;
        if (c == 1) {
            if (!cartHead) { cout << "  Cart is empty.\n"; continue; }
            for (CartNode* n = cartHead; n; n = n->next) enqueue(n->id, n->qty);
            clearCart();
            cout << "  Order placed!\n";
        } else {
            int id, qty;
            if (!dequeue(id, qty)) { cout << "  Nobody in line.\n"; continue; }
            int i = findById(id);
            if (i >= 0 && catalog[i].stockQuantity >= qty) {
                catalog[i].stockQuantity -= qty;  // stock update
                cout << "  Sold " << qty << " x " << catalog[i].name << ". Stock left: " << catalog[i].stockQuantity << "\n";
            } else cout << "  Order skipped (not enough stock).\n";
        }
    }
}

void adminMenu() {                                // option 7
    while (true) {
        int c = askInt("\nADMIN: 1 Add product  2 UNDO last add  3 Back: ", 1, 3);
        if (c == 3) return;
        if (c == 1) {
            string name = askText("Name: "), cat = askText("Category: ");
            int b = chooseBrand();
            int price = askInt("Price: ", 1, 100000), stock = askInt("Stock: ", 0, 100000);
            addProduct(makeProduct(nextId++, name, cat, BRANDS[b], price, stock));
            rebuildTree();
            pushUndo(catalog[numProducts - 1].id);
            cout << "  Product added.\n";
        } else {
            int id;
            if (!popUndo(id)) { cout << "  Nothing to undo.\n"; continue; }
            numProducts--;                        // newest product is always the last one
            rebuildTree();
            cout << "  Undone: product " << id << " removed.\n";
        }
    }
}

void showBanner() {                               // option 8
    while (true) {
        int n = 0;
        for (int i = 0; i < numProducts; i++) if (catalog[i].brand == brandCur->name) n++;
        cout << "\n  *** FEATURED BRAND: " << brandCur->name << " (" << n << " products) ***\n";
        if (toLower(askText("Enter = next brand, q = back: ")) == "q") return;
        brandCur = brandCur->next;                // after the last brand, it loops to the first
    }
}

void sortView() {                                 // option 9
    int c = askInt("1 Price (Quick)  2 Stock (Quick)  3 Brand (Insertion): ", 1, 3);
    Product* a = new Product[numProducts];
    for (int i = 0; i < numProducts; i++) a[i] = catalog[i];
    if (c == 3) insertionSortByBrand(a, numProducts); else quickSort(a, 0, numProducts - 1, c);
    printTable(a, numProducts);
    delete[] a;
}
