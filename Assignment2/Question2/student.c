/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int helper(struct TreeNode* node, struct TreeNode* min, struct TreeNode* max){

    if (node == NULL)
        return 0;

    if (min && node->val <= min->val)
        return -1;

    if (max && node->val >= max->val)
        return -1;

    int leftheight = helper(node->left, min, node);
    if (leftheight == -1)
        return -1;

    int rightheight = helper(node->right, node, max);
    if (rightheight == -1)
        return -1;

    if (abs(leftheight - rightheight) > 1)
        return -1;

    return (leftheight > rightheight ? leftheight : rightheight) + 1;
}



bool isAVL(struct TreeNode* root) {
    // TODO: implement
    // Hint: One common O(n) approach:
    // - Use a recursive helper that returns the subtree height,
    //   and returns -1 if subtree is invalid (BST violation or unbalanced).
    return helper(root, NULL, NULL) != -1;
    (void)root;
    return false;
}
