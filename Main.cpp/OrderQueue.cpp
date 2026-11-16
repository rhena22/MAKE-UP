#include "OrderQueue.h"

OrderNode *qFront = 0, *qRear = 0;
int qCount = 0;

void enqueue(int id, int qty) {
    OrderNode* n = new OrderNode(id, qty);
    if (qRear) qRear->next = n; else qFront = n;
    qRear = n;
    qCount++;
}
bool dequeue(int& id, int& qty) {
    if (!qFront) return false;
    OrderNode* d = qFront;
    id = d->id; qty = d->qty;
    qFront = d->next;
    if (!qFront) qRear = 0;
    delete d;
    qCount--;
    return true;
}
