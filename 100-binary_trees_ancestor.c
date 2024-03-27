#include "binary_trees.h"

/**
 * binary_trees_ancestor -  finds the lowest common ancestor of two nodes.
 * @first: a pointer to the first node.
 * @second: a pinter to the second node.
 * Return: returns NULL if no common ancestor was found,
*/

binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *n, *m;

	if (first == NULL || second == NULL)
		return (NULL);

	n = (binary_tree_t *)first;
	while (n)
	{
		m = (binary_tree_t *)second;
		while (m)
		{
			if (m == n)
				return (m);
			m = m->parent;
		}
		n = n->parent;
	}
	return (NULL);
}
