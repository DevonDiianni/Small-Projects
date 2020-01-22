#ifndef TREENODE_H
#define TREENODE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
  void *data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

typedef struct TreeNode TreeNode;

TreeNode *treeNodeCreate(const void * value, const size_t valueSize);// constructs a TreeNode
void * treeNodeGetValue(const TreeNode * node); //gets the value pointer from the TreeNode
void treeNodeSetLeft(TreeNode * node, TreeNode *left); // sets the left child of node
void treeNodeSetRight(TreeNode * node, TreeNode *right); // sets the right child of node
TreeNode * treeNodeGetLeft(const TreeNode *node); // returns a ptr to TreeNode in left of node
TreeNode * treeNodeGetRight(const TreeNode *node); // returns a ptr to TreeNode in right of node
void treeNodeAdd(TreeNode * node, int (*comparator)(const void*,const void*), const void *value, const size_t valueSize);// adds value to the correct place within the tree, see below for comparator
void treeNodePrint(const TreeNode * node, char *(*formatter)(const void *));// performs an in order print of the TreeNode

//Extra Credit
void treeNodePrePrint(const TreeNode * node, char *(*formatter)(const void *));
void treeNodePostPrint(const TreeNode * node, char *(*formatter)(const void *));
TreeNode * nodeSearch(const TreeNode *node, int (*comparator)(const void *value1,const void *value2), const void * value);
TreeNode * deepestRightmostNode(TreeNode *node);


#endif
