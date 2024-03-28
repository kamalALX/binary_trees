#include "binary_trees.h"

/**
 * binary_tree_rotate_right - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	tree->parent = tree->left;
	tree->left = tree->parent->right;
	if (tree->parent->right != NULL)
		tree->parent->right->parent = tree;
	tree->parent->right = tree;
	tree->parent->parent = NULL;

	root = tree;
	while (root->parent != NULL)
		root = root->parent;
	return (root);
}
