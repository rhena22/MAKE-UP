#ifndef CART_H
#define CART_H

// LAB 2: Doubly linked list (shopping cart)
struct CartNode {
    int id, qty;
    CartNode *prev, *next;
    CartNode(int i, int q, CartNode* p) : id(i), qty(q), prev(p), next(0) {}
};

extern CartNode *cartHead, *cartTail, *cartCur;

int qtyInCart(int id);
void addToCart(int id, int qty);
void removeCurrent();
void clearCart();
#endif
