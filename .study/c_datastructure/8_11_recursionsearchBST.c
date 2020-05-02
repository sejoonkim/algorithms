#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode * new_node(int item) {
    TreeNode * temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// recursion
// TreeNode * search(TreeNode *node, int key) {
//     if (node == NULL) return NULL;
//     if (key == node->key) return node;
//     else if (key < node->key) 
//         return search(node->left, key);
//     else
//         return search(node->right, key);
// }

// loop
TreeNode * search(TreeNode *node, int key) {
    while (node != NULL) {
        if (key == node->key) return node;
        else if (key < node->key) node = node->left;
        else node = node->right;
    }
    return NULL; // failed search
}

TreeNode *insert_node(TreeNode *node, int key) {
    // if empty tree, return the new node
    if (node == NULL) return new_node(key);

    // recursively traverse the tree
    if (key < node->key) {
        node->left = insert_node(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert_node(node->right, key);
    }

    return node;
}

TreeNode * min_value_node(TreeNode *node) {
    TreeNode * current = node;

    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

TreeNode * delete_node(TreeNode * root, int key) {
    if (root == NULL) return root;

    if (key < root->key) {
        root->left = delete_node(root->left, key);
    }
    else if (key > root->key) {
        root->right = delete_node(root->right, key);
    }
    else {
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // two children
        TreeNode * temp = min_value_node(root->right);

        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

void inorder(TreeNode * root) {
    if (root) {
        inorder(root->left);
        printf("%d-> ", root->key);
        inorder(root->right);
    }
}


int main(void) {
    TreeNode * root = NULL;
    TreeNode * tmp = NULL;

    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);

    printf("BT inorder traversal result \n");
    inorder(root);
    printf("\n\n");

    if (search(root, 30) != NULL) {
        printf("found 30.");
    }
    else
        printf("not found 30"); 
    return 0;
}