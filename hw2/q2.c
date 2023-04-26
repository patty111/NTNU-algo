// DP 解
// first step, generate all possible BST
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_TREES 100000

typedef struct Node{
    int val;
    struct node* left;
    struct node* right;
}node;

int cmpfunc(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}


node* addNode(int data){
    node* root = (node*)malloc(sizeof(node));
    root->val = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}


node** generateBSTs(int* nodes, int pivot_idx, int n){
    int len1 = pivot_idx;
    int len2 = n - pivot_idx - 1;
    int* left_nodes = (int*)malloc(sizeof(int) * len1);
    int* right_nodes = (int*)malloc(sizeof(int) * len2);
    for (int i=0;i<len1;i++) left_nodes[i] = nodes[i];
    for (int i=0;i<len2;i++) right_nodes[i] = nodes[i + pivot_idx];


    
}


void printTree(node* root){
    if (root == NULL)
        return;
    printTree(root->left);
    printf("%d ",root->val);
    printTree(root->right);
}

int main() {
    int n;
    int* arr = (int*)malloc(sizeof(int) * n);
    
    qsort(arr, n, sizeof(int), cmpfunc);

    node** trees = generateBSTs(arr, 0);
    
    // for (int i = 0; i < MAX_TREES; i++) {
    //     if (trees[i] != NULL) {
    //         printf("Tree %d: ", i + 1);
    //         printTree(trees[i]);
    //         printf("\n");
    //     }
    // }
    
    return 0;
}
