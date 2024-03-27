#include "binary_trees.h"

/**
 * binary_tree_rotate_right - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

    if (tree->left != NULL)
    {
        tree->parent = tree->left;
        tree->left = tree->left->right;
        tree->parent->right = tree;
        tree->parent->parent = NULL;
        return (tree->parent);
    }
    return (tree);
}
