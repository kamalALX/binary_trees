#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

void inorderTraversal(heap_t *heap, int* result, int* index) {
    if (heap) {
        // Traverse left subtree
        inorderTraversal(heap->left, result, index);
        // Append value to the result array
        result[(*index)++] = heap->n;
        // Traverse right subtree
        inorderTraversal(heap->right, result, index);
    }
}

// Function to convert Binary Max Heap to a sorted array
int* heap_to_sorted_array(heap_t *heap, size_t* size) {
    // Count the number of nodes in the heap
    int numNodes = 0;
    inorderTraversal(heap, NULL, &numNodes);

    // Allocate memory for the result array
    int* result = (int*)malloc(numNodes * sizeof(int));
    if (!result) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Perform inorder traversal to get sorted array
    int index = 0;
    inorderTraversal(heap, result, &index);

    // Set the size of the array
    *size = numNodes;

    return result;
}
