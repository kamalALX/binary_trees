#include "binary_trees.h"

/**
 * bst_search - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 * @value: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
