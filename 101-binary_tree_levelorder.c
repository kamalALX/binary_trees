#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
void printGivenLevel(const binary_tree_t *tree, int level, void (*func)(int));

/**
 * binary_tree_levelorder - goes through a binary tree
 *using level-order traversal
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, i;

	height = binary_tree_height(tree);

	for (i = 0; i <= height; i++)
		printGivenLevel(tree, i, func);
}

/**
 * printGivenLevel - prints nodes at a given level
 * @tree: a pointer to the root node of the tree to traverse
 * @level: level at which the nodes are to be printed
 * @func: a pointer to a function to call for each node
 *
 * Return: void
 */

void printGivenLevel(
	const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);

	else if (level > 1)
	{
		printGivenLevel(tree->left, level - 1, func);
		printGivenLevel(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: Pointer to the node to insert the left-child in
 *
 * Return: Pointer to the created node, or NULL on failure
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (left_height + 1);
	return (right_height + 1);
}
