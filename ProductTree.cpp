#include "ProductTree.h"
#include "Catalog.h"

TreeNode* root = 0;

TreeNode* buildTree(int lo, int hi) {             // pick the middle -> balanced tree
    if (lo > hi) return 0;
    int m = (lo + hi) / 2;
    TreeNode* n = new TreeNode(catalog[m].id, m);
    n->left = buildTree(lo, m - 1);
    n->right = buildTree(m + 1, hi);
    return n;
}
void freeTree(TreeNode* n) {
    if (n) { freeTree(n->left); freeTree(n->right); delete n; }
}
void rebuildTree() {
    freeTree(root);
    root = buildTree(0, numProducts - 1);
}
int findById(int id) {
    TreeNode* c = root;
    while (c) {
        if (id == c->id) return c->index;
        c = (id < c->id) ? c->left : c->right;
    }
    return -1;
}
