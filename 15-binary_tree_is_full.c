#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == tree->right && tree->left == NULL)
		return (1);

	if (binary_tree_is_full(tree->left) && (binary_tree_is_full(tree->right)))
		return (1);
	return (0);
}
