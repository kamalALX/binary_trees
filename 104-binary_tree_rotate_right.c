#include "binary_trees.h"

/**
 * binary_tree_rotate_right - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL || tree->left == NULL)
		return tree;

	pivot = tree->left;
	tree->left = pivot->right;

	if (pivot->right != NULL)
		pivot->right->parent = tree;

	pivot->parent = tree->parent;
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = pivot;
		else
			tree->parent->right = pivot;
	}

	pivot->right = tree;
	tree->parent = pivot;

	return pivot;
}
