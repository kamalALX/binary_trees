#include "binary_trees.h"

/**
 * binary_tree_postorder - Inserts a node as the left-child of another node
 * @tree: Pointer to the node to insert the left-child in
 * @func: Value to store in the new node
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    binary_tree_postorder(tree->left, func);
    binary_tree_postorder(tree->right, func);
    func(tree->n);
}
