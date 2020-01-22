#include "Tree.h"
#include <string.h>

Tree * treeCreate(char *(*printFormatter)(const void *aValue), int (*comparator)(const void *value1,const void *value2)) {
    Tree *newTree = (Tree *)malloc(sizeof(Tree));
    newTree->root = NULL;
    newTree->printFormatter = printFormatter;
    newTree->comparator = comparator;
    return newTree;
}

TreeNode* treeGetRoot(const Tree * tree) {
    if (!tree)
        return NULL;

    return tree->root;
}

void treeAdd(Tree * tree, const void *value, const size_t valueSize) {
    if (!tree->root) {
        tree->root = treeNodeCreate(value, valueSize);
    }
    else {
        treeNodeAdd(tree->root, tree->comparator, value, valueSize);
    }
}

void treePrint(const Tree * tree) {
    if (!tree->root)
        return;

    treeNodePrint(tree->root, tree->printFormatter);
}

int treeSearch(const Tree *tree, const void * value) {
    if (!tree || !tree->root || !tree->comparator)
        return 0;

    return nodeSearch(tree->root, tree->comparator, value) != NULL;
}

int treeDelete (Tree *tree, const void * value) {
    if (!tree || !tree->root || !tree->comparator)
        return 0;


    TreeNode *deepestRigthmostNode = deepestRightmostNode(tree->root);
    TreeNode *found = NULL;


    if (tree->comparator(tree->root->data, value) == 0) {
        found = tree->root;
    }
    else {
        found = (TreeNode *)nodeSearch(tree->root, tree->comparator, value);
    }

    if (deepestRigthmostNode && found) {
        free(found->data);
        found->data = deepestRigthmostNode->data;
        free(deepestRigthmostNode);
        return 1;
    }

    return 0;
}
