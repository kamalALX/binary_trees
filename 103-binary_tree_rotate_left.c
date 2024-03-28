#include "binary_trees.h"

/**
 * binary_tree_rotate_left - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	pivot = tree->right;
	tree->right = pivot->left;

	if (pivot->left != NULL)
		pivot->left->parent = tree;

	pivot->parent = tree->parent;
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = pivot;
		else
			tree->parent->right = pivot;
	}

	pivot->left = tree;
	tree->parent = pivot;

	return (pivot);
}
