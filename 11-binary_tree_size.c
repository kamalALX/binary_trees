#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure the size.
 *
 * Return: If tree is NULL, the function must return 0.
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t lf, rg, size = 0;

	if (tree == NULL)
		return (0);

	lf = binary_tree_size(tree->left);
	rg = binary_tree_size(tree->right);

	size = lf + rg;
	return (size + 1);
}
