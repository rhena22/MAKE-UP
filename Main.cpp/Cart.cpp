#include "Cart.h"

CartNode *cartHead = 0, *cartTail = 0, *cartCur = 0;

int qtyInCart(int id) {
    for (CartNode* c = cartHead; c; c = c->next) if (c->id == id) return c->qty;
    return 0;
}
void addToCart(int id, int qty) {
    for (CartNode* c = cartHead; c; c = c->next)
        if (c->id == id) { c->qty += qty; return; }
    CartNode* n = new CartNode(id, qty, cartTail);
    if (cartTail) cartTail->next = n; else cartHead = n;
    cartTail = n;
    if (!cartCur) cartCur = n;
}
void removeCurrent() {
    CartNode* d = cartCur;
    if (!d) return;
    if (d->prev) d->prev->next = d->next; else cartHead = d->next;
    if (d->next) d->next->prev = d->prev; else cartTail = d->prev;
    cartCur = d->next ? d->next : d->prev;
    delete d;
}
void clearCart() {
    while (cartHead) { CartNode* d = cartHead; cartHead = d->next; delete d; }
    cartTail = cartCur = 0;
}
