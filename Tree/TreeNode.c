#include "TreeNode.h"


TreeNode *treeNodeCreate(const void * value, const size_t valueSize) {
  TreeNode *result = (TreeNode *)malloc(sizeof(TreeNode));
  if (value && valueSize) {
    result->data = (void *)malloc(valueSize);
    memcpy(result->data, value, valueSize);
  }
  else 
  result->data = NULL;
  result->left = NULL;
  result->right = NULL;
  return result;
}

void * treeNodeGetValue(const TreeNode * node) {
  return node ? node->data : NULL;
}

void treeNodeSetLeft(TreeNode * node, TreeNode *left) {
  if (!node)
    return;

  node->left = left;
}

void treeNodeSetRight(TreeNode * node, TreeNode *right) {
  if (!node)
    return;
    
  node->right = right;
}

TreeNode * treeNodeGetLeft(const TreeNode *node) {
  if (!node)
    return NULL;

  return node->left;
}

TreeNode * treeNodeGetRight(const TreeNode *node) {
  if (!node)
    return NULL;

  return node->right;
}

void treeNodeAdd(TreeNode * node, int (*comparator)(const void*,const void*), const void *value, const size_t valueSize) {
    if (comparator(value, node->data) < 0) {
        if (!node->left) {
            node->left = treeNodeCreate(value, valueSize);
        }
        else {
            treeNodeAdd(node->left, comparator, value, valueSize);
        }
    }
    else if (comparator(value, node->data) > 0) {
        if (!node->right) {
            node->right = treeNodeCreate(value, valueSize);
        }
        else {
            treeNodeAdd(node->right, comparator, value, valueSize);
        }
    }
    else
        return;
}

void treeNodePrint(const TreeNode * node, char* (*formatter)(const void *)) {
    if (!node)
        return;

    printf("%s\n", formatter(node->data));
    treeNodePrint(node->left, formatter);
    treeNodePrint(node->right, formatter);
}


void treeNodePrePrint(const TreeNode * node, char *(*formatter)(const void *)) {
    if (!node)
        return;

    printf("%s\n", formatter(node->data));
    treeNodePrint(node->left, formatter);
    treeNodePrint(node->right, formatter);
}

void treeNodePostPrint(const TreeNode * node, char *(*formatter)(const void *)) {
    if (!node)
        return;

    treeNodePrint(node->left, formatter);
    treeNodePrint(node->right, formatter);
    printf("%s\n", formatter(node->data));
}

TreeNode * nodeSearch(const TreeNode *node, int (*comparator)(const void *value1,const void *value2), const void * value) {
    if (!node || !value)
        return NULL;

    if (comparator(node->data, value) == 0)
        return (TreeNode *)node;

    TreeNode * found = nodeSearch(node->left, comparator, value);
    if (!found)
        found = nodeSearch(node->right, comparator, value);

    return found;
}

TreeNode * deepestRightmostNode(TreeNode *node) {
    if (!node)
        return NULL;

    if (!node->right)
        return node;

    TreeNode * found = deepestRightmostNode(node);
    if (found)
        node->right = NULL;

    return found;
}

