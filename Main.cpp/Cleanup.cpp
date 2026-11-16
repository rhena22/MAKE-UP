#include "Cleanup.h"
#include "Catalog.h"
#include "ProductTree.h"
#include "Cart.h"
#include "OrderQueue.h"
#include "UndoStack.h"
#include "BrandList.h"

void cleanup() {
    delete[] catalog; catalog = 0;
    freeTree(root); root = 0;
    clearCart();
    freeBrands();
    int a, b;
    while (dequeue(a, b)) {}
    while (popUndo(a)) {}
}
