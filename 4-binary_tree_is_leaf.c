#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Inserts a node as the left-child of another node
 * @node: Pointer to the node to insert the left-child in
 *
 * Return: Pointer to the created node, or NULL on failure
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);
	return (0);
}
