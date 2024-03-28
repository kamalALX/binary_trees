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

/**
 * avl_insert - checks if a binary tree is full
 * @tree: Pointer to the node to insert the left-child in
 * @value: Pointer to the node to insert the left-child in
 *
 * Return: returns 0 if tree is NULL
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;
	int bf;

	if (tree == NULL)
		return (NULL);

	bf = 0;
	node = bst_insert(tree, value);
	if (node != NULL && node->parent != NULL && node->parent->parent != NULL)
		bf = binary_tree_balance(node->parent->parent);

	if (bf != -1 && bf != 0 && bf != 1)
	{
		if (node->parent->left == node && node->parent->parent->left == node->parent)
			*tree = binary_tree_rotate_right(node->parent->parent);
		else if (node->parent->right == node && node->parent->parent->right == node->parent)
			*tree = binary_tree_rotate_left(node->parent->parent);
		else if (node->parent->right == node && node->parent->parent->left == node->parent)
		{
			*tree = binary_tree_rotate_left(node->parent);
			*tree = binary_tree_rotate_right(node->parent);
		}
		else if (node->parent->left == node && node->parent->parent->right == node->parent)
		{
			*tree = binary_tree_rotate_right(node->parent);
			*tree = binary_tree_rotate_left(node->parent);
		}
	}
	return (node);
}
