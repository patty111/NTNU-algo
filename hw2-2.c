#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given value
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to find the height of a binary tree
int getHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

// Function to find the minimum of maximum path sum among all possible BSTs
int minOfMaxPathSum(struct TreeNode* root, int* maxSum) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    int leftMaxPathSum = minOfMaxPathSum(root->left, maxSum);
    int rightMaxPathSum = minOfMaxPathSum(root->right, maxSum);
    int maxPathSum = max(leftHeight, rightHeight);
    if (maxPathSum > *maxSum) {
        *maxSum = maxPathSum;
    }
    return 1 + min(leftMaxPathSum, rightMaxPathSum);
}


// Function to insert a value into a BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}



// Function to find the minimum of maximum path sum among all possible BSTs (wrapper function)
int findMinOfMaxPathSum(int* nums, int size) {
    struct TreeNode* root = NULL;
    for (int i = 0; i < size; i++) {
        root = insert(root, nums[i]);
    }
    int maxSum = 0;
    minOfMaxPathSum(root, &maxSum);
    return maxSum;
}
int main() {
    int n; // Number of integers
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    int* nums = (int*)malloc(n * sizeof(int)); // Dynamically allocate memory for the array of integers
    printf("Enter the integers separated by spaces: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int minMaxPathSum = findMinOfMaxPathSum(nums, n);
    printf("Minimum of Maximum Path Sum among all possible BSTs: %d\n", minMaxPathSum);
    free(nums); // Free dynamically allocated memory
    return 0;
}
