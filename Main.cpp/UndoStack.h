#ifndef UNDOSTACK_H
#define UNDOSTACK_H

// LAB 4: Stack (admin undo, last in = first out)
struct StackNode {
    int productId;
    StackNode* next;
    StackNode(int i, StackNode* n) : productId(i), next(n) {}
};

extern StackNode* undoTop;

void pushUndo(int id);
bool popUndo(int& id);
#endif
