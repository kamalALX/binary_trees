#include "binary_trees.h"

/**
 * array_to_avl - checks if a binary tree is full
 * @array: Pointer to the node to insert the left-child in
 * @size: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);

	i = 0;
	while (i < size)
	{
		avl_insert(&root, array[i]);
		i++;
	}
	return (root);
}
