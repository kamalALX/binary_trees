#include "binary_trees.h"

/**
 * binary_tree_uncle - Inserts a node as the left-child of another node
 * @node: Pointer to the node to insert the left-child in
 *
 * Return: Pointer to the created node, or NULL on failure
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

    if (node->parent == node->parent->parent->left)
        return (node->parent->parent->right);
    return (node->parent->parent->left);
}
