#include "binary_trees.h"

/**
 * bst_search - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 * @value: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}

/**
 * bst_min - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 * @value: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

int bst_min(bst_t *tree)
{
	int mini;
	bst_t *node;

	node = tree;

	while (node != NULL)
	{
		mini = node->n;
		node = node->left;
	}
	return (mini);
}

/**
 * bst_remove - checks if a binary tree is full
 * @root: Pointer to the node to insert the left-child in
 * @value: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;
	int mini;

	if (root == NULL)
		return (NULL);

	node = bst_search(root, value);

	if (node->left == NULL && node->right == NULL)
	{
		if (node->parent != NULL && node == node->parent->left)
			node->parent->left = NULL;
		else if (node->parent != NULL && node == node->parent->right)
			node->parent->right = NULL;
		free(node);
		node = NULL;
	}
	else if (node->left == NULL || node->right == NULL)
	{
		if (node->parent != NULL && node == node->parent->left)
		{
			if (node->left != NULL)
			{
				node->parent->left = node->left;
				node->left->parent = node->parent;
			}
			if (node->right != NULL)
			{
				node->parent->left = node->right;
				node->right->parent = node->parent;
			}
		}
		else if (node->parent != NULL && node == node->parent->right)
		{
			if (node->left != NULL)
			{
				node->parent->right = node->left;
				node->left->parent = node->parent;
			}
			if (node->right != NULL)
			{
				node->parent->right = node->right;
				node->right->parent = node->parent;
			}
		}
		else if (node->parent == NULL && node->left != NULL)
		{
			root = node->left;
			node->left->parent = NULL;
		}
		else if (node->parent == NULL && node->right != NULL)
		{
			root = node->right;
			node->right->parent = NULL;
		}
		free(node);
		node = NULL;
	}
	else if (node->left != NULL && node->right != NULL)
	{
		mini = bst_min(node->right);
		root = bst_remove(root, mini);
		node->n = mini;
	}
	return (root);
}
