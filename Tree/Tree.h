#ifndef TREE
#define TREE

#include "TreeNode.h"

typedef struct Tree {
    TreeNode *root;
    char *(*printFormatter)(const void *aValue);
    int (*comparator)(const void *value1,const void *value2);
} Tree;

typedef struct Tree Tree;

Tree * treeCreate(char *(*printFormatter)(const void *aValue), int (*comparator)(const void *value1,const void *value2));
TreeNode* treeGetRoot(const Tree * tree); 
void treeAdd(Tree * tree, const void *value, const size_t valueSize);
void treePrint(const Tree * tree);

//Extra Credit
int treeDelete (Tree *tree, const void * value);
int treeSearch(const Tree *tree, const void * value);

#endif