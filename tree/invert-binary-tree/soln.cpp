#include <stdlib.h>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    std::vector<TreeNode *> nodes_to_process;
    if (root != nullptr) {
      nodes_to_process.push_back(root);
    }
    while (!nodes_to_process.empty()) {
      TreeNode *node = nodes_to_process.back();
      nodes_to_process.pop_back();
      TreeNode *old_left = node->left;
      TreeNode *old_right = node->right;
      node->left = old_right;
      node->right = old_left;

      if (node->left != nullptr) {
        nodes_to_process.push_back(node->left);
      }
      if (node->right != nullptr) {
        nodes_to_process.push_back(node->right);
      }
    }
    return root;
  }
};

int main() {
  TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *left = (TreeNode *)malloc(sizeof(TreeNode));
  TreeNode *right = (TreeNode *)malloc(sizeof(TreeNode));

  left->val = 1;
  right->val = 3;
  root->left = left;
  root->right = right;
  Solution *soln = new Solution();
  TreeNode *res = soln->invertTree(root);

  free(left);
  free(right);
  free(root);
}
