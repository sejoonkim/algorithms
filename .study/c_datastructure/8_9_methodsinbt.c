#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int get_node_count(TreeNode *root) {
    int count = 0;
    if (root != NULL) {
        count = 1 + get_node_count(root->left) + get_node_count(root->right);
    }
    return count;
}

int get_leaf_count(TreeNode *root) {
    int count = 0;
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        else count = get_leaf_count(root->left) + get_leaf_count(root->right);
    }
    return count;
}

int get_nonleaf_count(TreeNode *root) {
    int count = 0;
    // if empty node or terminal node
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    
    return 1 + get_nonleaf_count(root->left) + get_nonleaf_count(root->right);
}

int get_height(TreeNode *root) {
    int height = 0;
    if (root != NULL) {
        height = max(get_height(root->left), get_height(root->right));
    }
    return height;
}

int main(void) {
    
    return 0;
}