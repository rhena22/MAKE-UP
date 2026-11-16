#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

// LAB 5: Queue (checkout line, first in = first out)
struct OrderNode {
    int id, qty;
    OrderNode* next;
    OrderNode(int i, int q) : id(i), qty(q), next(0) {}
};

extern OrderNode *qFront, *qRear;
extern int qCount;

void enqueue(int id, int qty);
bool dequeue(int& id, int& qty);
#endif
