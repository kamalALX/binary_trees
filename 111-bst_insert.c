#include "binary_trees.h"


/**
 * binary_tree_node - function that creates a binary tree node
 *
 * @parent: ointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return: returns a pointer to the new node, or NULL on failure
*/

binary_tree_t *binary_tree_node0(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	return (new_node);
}

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->right = NULL;
	new_node->parent = parent;

	if (parent->left == NULL)
		new_node->left = NULL;
	else
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}

	parent->left = new_node;
	return (new_node);
}

#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->parent = parent;

	if (parent->right == NULL)
		new_node->right = NULL;
	else
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	parent->right = new_node;
	return (new_node);
}

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
        return (*tree = binary_tree_node0(*tree, value));
    if (value <= (*tree)->n)
    {
        if ((*tree)->left == NULL)
            return ((*tree)->left = binary_tree_insert_left(*tree, value));
        return (bst_insert(&((*tree)->left), value));
    }
    if ((*tree)->right == NULL)
        return ((*tree)->right = binary_tree_insert_right(*tree, value));
    return (bst_insert(&((*tree)->right), value));
}
