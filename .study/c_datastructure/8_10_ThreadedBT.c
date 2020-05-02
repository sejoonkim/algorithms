#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
    int is_thread;
} TreeNode;

TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL, 1 };
TreeNode n3 = { 'C', &n1, &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 };
TreeNode n6 = { 'F', &n4, &n5, 0 };
TreeNode n7 = { 'G', &n3, &n6, 0 };
TreeNode *expr = &n7;

TreeNode * find_successor(TreeNode *p) {
    TreeNode *q = p->right;
    // if no right child or p is terminal node
    if (q == NULL || p->is_thread == 1) 
        return q;
    while (q->left != NULL) q = q->left;
    return q;
}

void thread_inorder(TreeNode *root) {
    TreeNode *q;
    q = root;
    while (q->left) q = q->left;
    do {
        printf("%c-> ", q->data);
        q = find_successor(q);
    } while (q);

}

int main(void) {
    n1.right = &n3;
    n2.right = &n7;
    n4.right = &n6;

    thread_inorder(expr);
    printf("\n");
    return 0;
}