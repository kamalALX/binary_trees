#include "binary_trees.h"

/**
 * bst_insert - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 * @value: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
		return (*tree = binary_tree_node(*tree, value));
	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
			return ((*tree)->left = binary_tree_node(*tree, value));
		return (bst_insert(&((*tree)->left), value));
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
			return ((*tree)->right = binary_tree_node(*tree, value));
		return (bst_insert(&((*tree)->right), value));
	}
	return (NULL);
}
