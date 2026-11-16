#include "UndoStack.h"

StackNode* undoTop = 0;

void pushUndo(int id) { undoTop = new StackNode(id, undoTop); }
bool popUndo(int& id) {
    if (!undoTop) return false;
    StackNode* d = undoTop;
    id = d->productId;
    undoTop = d->next;
    delete d;
    return true;
}
