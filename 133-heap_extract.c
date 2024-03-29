#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const heap_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (1 + left_size + right_size);
}

/**
 * swap1 - waps the values of two nodes.
 * @a: first node
 * @b: second node
*/

void swap1(heap_t *a, heap_t *b)
{
	int temp;

	temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * heapify_down - Maintains the Max Heap property by fixing violations
 * after extracting the root node.
 * @root: Pointer to the root of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	if (left != NULL && left->n > largest->n)
		largest = left;

	if (right != NULL && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		swap1(root, largest);
		heapify_down(largest);
	}
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Pointer to the root of the heap
 * Return: Value of the extracted node, or 0 if the heap is empty
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *last_node, *temp_node;
	size_t rear, front;
	size_t count = binary_tree_size(*root);
	heap_t *queue[count];

	if (root == NULL || *root == NULL)
		return (0);

	if ((*root)->left == NULL && (*root)->right == NULL)
	{
		extracted_value = (*root)->n;
		free(*root);
		*root = NULL;
		return (extracted_value);
	}
	rear = 0;
	front = 0;
	queue[rear++] = *root;

	while (front < rear)
	{
		temp_node = queue[front++];
		if (temp_node->left)
			queue[rear++] = temp_node->left;
		if (temp_node->right)
			queue[rear++] = temp_node->right;
	}
	last_node = queue[--rear];
	extracted_value = (*root)->n;
	(*root)->n = last_node->n;

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	free(last_node);
	heapify_down(*root);

	return (extracted_value);
}
