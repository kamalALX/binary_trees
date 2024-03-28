#include "binary_trees.h"

/**
 * array_to_bst - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 * @size: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);

	i = 0;
	while (i < size)
	{
		bst_insert(&root, array[i]);
		i++;
	}
	return (root);
}
