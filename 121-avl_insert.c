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
	else
		return (*tree);
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
	avl_t *node, *follow_up;
	int bf;

	if (tree == NULL)
		return (NULL);

	bf = 0;
	follow_up = node = bst_insert(tree, value);
	while (follow_up != NULL)
	{
		bf = binary_tree_balance(follow_up);
		if (bf != -1 && bf != 0 && bf != 1)
			break;
		follow_up = follow_up->parent;
	}

	if (bf != -1 && bf != 0 && bf != 1)
	{
		if (bf > 1 && node->left != NULL && value < node->left->n)
			*tree = binary_tree_rotate_right(follow_up);
		if (bf < -1 && node->right != NULL && value > node->right->n)
			*tree = binary_tree_rotate_left(follow_up);
		if (bf > 1 && node->left != NULL && value > node->left->n)
		{
			*tree = binary_tree_rotate_left(follow_up->left);
			*tree = binary_tree_rotate_right(follow_up);
		}
		if (bf < -1 && node->right != NULL && value < node->right->n)
		{
			*tree = binary_tree_rotate_right(follow_up->right);
			*tree = binary_tree_rotate_left(follow_up);
		}
	}
	return (node);
}
