#include "binary_trees.h"

/**
 * binary_tree_rotate_left - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL || tree->right == NULL)
		return (tree);

    tree->parent = tree->right;
    tree->right = tree->parent->left;
    if (tree->parent->left != NULL)
        tree->parent->left>parent = tree;
    tree->parent->left = tree;
    tree->parent->parent = NULL;
    return (tree->parent);
}
