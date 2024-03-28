#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_is_bst - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

int binary_tree_is_bst_range(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n < min || tree->n >= max)
        return (0);

    return (binary_tree_is_bst_range(tree->left, min, tree->n) &&
            binary_tree_is_bst_range(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (binary_tree_is_bst_range(tree, INT_MIN, INT_MAX));
}
