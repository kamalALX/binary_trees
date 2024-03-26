#include "binary_trees.h"


/**
 * binary_tree_preorder - Inserts a node as the left-child of another node
 * @tree: Pointer to the node to insert the left-child in
 * @func: Value to store in the new node
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    func(tree->n);
    binary_tree_preorder(tree->left, func);
    binary_tree_preorder(tree->right, func);
}
