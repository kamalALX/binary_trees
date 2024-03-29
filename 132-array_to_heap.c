#include "binary_trees.h"

/**
 * array_to_heap - checks if a binary tree is full
 * @array: Pointer to the node to insert the left-child in
 * @size: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	size_t i;

	if (!array)
		return (NULL);

	i = 0;
	while (i < size)
	{
		heap_insert(&root, array[i]);
		i++;
	}
	return (root);
}
