#include "binary_trees.h"

/**
 * binary_tree_is_full - Inserts a node as the left-child of another node
 * @node: Pointer to the node to insert the left-child in
 *
 * Return: Pointer to the created node, or NULL on failure
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == tree->right && tree->left == NULL)
		return (1);

	if (binary_tree_is_full(tree->left) && (binary_tree_is_full(tree->right)))
		return (1);
	return (0);
}
