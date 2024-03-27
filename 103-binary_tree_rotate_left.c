#include "binary_trees.h"

/**
 * binary_tree_rotate_left - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

    if (tree->right != NULL)
    {
        tree->parent = tree->right;
        tree->right = tree->right->left;
        tree->parent->left = tree;
        tree->parent->parent = NULL;
        return (tree->parent);
    }
    return (tree);
}
