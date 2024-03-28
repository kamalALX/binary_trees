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
    avl_t *new_node, *parent, *unbalanced_node;

    if (tree == NULL)
        return NULL;

    new_node = bst_insert(tree, value);
    if (new_node == NULL)
        return NULL;

    unbalanced_node = NULL;
    parent = new_node->parent;
    while (parent != NULL)
    {
        int balance_factor;

        balance_factor = binary_tree_balance(parent);
        if (balance_factor > 1 || balance_factor < -1)
        {
            unbalanced_node = parent;
            break;
        }
        parent = parent->parent;
    }

    if (unbalanced_node != NULL)
    {
        if (value < unbalanced_node->n)
        {
            if (value < unbalanced_node->left->n)
                *tree = binary_tree_rotate_right(unbalanced_node);
            else
            {
                unbalanced_node->left = binary_tree_rotate_left(unbalanced_node->left);
                *tree = binary_tree_rotate_right(unbalanced_node);
            }
        }
        else
        {
            if (value > unbalanced_node->right->n)
                *tree = binary_tree_rotate_left(unbalanced_node);
            else
            {
                unbalanced_node->right = binary_tree_rotate_right(unbalanced_node->right);
                *tree = binary_tree_rotate_left(unbalanced_node);
            }
        }
    }

    return new_node;
}
