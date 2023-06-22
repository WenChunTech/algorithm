/// https://leetcode.cn/problems/validate-binary-search-tree/

#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

bool leftCompare(int rootVal, struct TreeNode *childNode) {
  if (childNode == NULL) {
    return true;
  }
  if (childNode->val >= rootVal) {
    return false;
  }
  return leftCompare(rootVal, childNode->left) &&
         leftCompare(rootVal, childNode->right);
}

bool rightCompare(int rootVal, struct TreeNode *childNode) {
  if (childNode == NULL) {
    return true;
  }
  if (childNode->val <= rootVal) {
    return false;
  }
  return rightCompare(rootVal, childNode->left) &&
         rightCompare(rootVal, childNode->right);
}

bool isValidBST(struct TreeNode *root) {
  if (root == NULL) {
    return true;
  }

  return isValidBST(root->left) && isValidBST(root->right) &&
         leftCompare(root->val, root->left) &&
         rightCompare(root->val, root->right);
}

int main() {}