#include "binary_trees.h"

/**
 * sorted_array_to_avl_ - checks if a binary tree is full
 * @array: Pointer to the node to insert the left-child in
 * @size: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

avl_t *sorted_array_to_avl_(avl_t **node, int *array, size_t size, int leftright)
{
	size_t mid;

	if (size == 0)
		return NULL;

	mid = (size / 2);

	if (size % 2 == 0)
		mid = mid - 1;

	if (leftright == 1)
	{
		(*node)->left = binary_tree_node(*node, array[mid]);
		sorted_array_to_avl_(&((*node)->left), array, mid, 1);
		sorted_array_to_avl_(&((*node)->left), array + mid + 1, (size - mid - 1), 0);
	}
	else if (leftright == 0)
	{
		(*node)->right = binary_tree_node(*node, array[mid]);
		sorted_array_to_avl_(&((*node)->right), array, mid, 1);
		sorted_array_to_avl_(&((*node)->right), array + mid + 1, (size - mid - 1), 0);
	}
	return (*node);
}

/**
 * sorted_array_to_avl - checks if a binary tree is full
 * @array: Pointer to the node to insert the left-child in
 * @size: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t mid;

	root = NULL;

	if (size == 0)
		return (NULL);

	mid = (size / 2);

	if (size % 2 == 0)
		mid = mid - 1;

	root = binary_tree_node(root, array[mid]);

	sorted_array_to_avl_(&root, array, mid, 1);
	sorted_array_to_avl_(&root, array + mid + 1, (size - mid - 1), 0);

	return (root);
}
