#include "binary_trees.h"
#include <limits.h>

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

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height >= right_height)
		return (left_height + 1);
	return (right_height + 1);
}

/**
 * binary_tree_balance -  measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of nodes.
 *
 * Return: If tree is NULL, the function must return 0.
 */

int binary_tree_balance(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right != NULL)
	{
		return (-binary_tree_height(tree->right) - 1);
	}
	else if (tree->right == NULL && tree->left != NULL)
	{
		return (binary_tree_height(tree->left) + 1);
	}
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

}

/**
 * binary_tree_is_bst_range - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 * @min: Pointer to the node to insert the left-child in
 * @max: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

int binary_tree_is_bst_range(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (binary_tree_is_bst_range(tree->left, min, tree->n) &&
			binary_tree_is_bst_range(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bf, bfl, bfr;

	if (tree == NULL)
		return (0);

	bfl = binary_tree_balance(tree->left);
	if (bfl == -1 || bfl == 0 || bfl == 1)
		bfl = 1;
	else
		bfl = 0;

	bfr = binary_tree_balance(tree->right);
	if (bfr == -1 || bfr == 0 || bfr == 1)
		bfr = 1;
	else
		bfl = 0;

	bf = binary_tree_balance(tree);
	if (bf == -1 || bf == 0 || bf == 1)
		bf = 1;
	else
		bfl = 0;

	return (binary_tree_is_bst_range(tree, INT_MIN, INT_MAX) && bf && bfl && bfl);
}
