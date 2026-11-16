#ifndef PRODUCTTREE_H
#define PRODUCTTREE_H

// LAB 6: Binary Search Tree (search by product ID)
struct TreeNode {
    int id, index;
    TreeNode *left, *right;
    TreeNode(int i, int x) : id(i), index(x), left(0), right(0) {}
};

extern TreeNode* root;

TreeNode* buildTree(int lo, int hi);
void freeTree(TreeNode* n);
void rebuildTree();
int findById(int id);   // returns catalog index or -1
#endif
