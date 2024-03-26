#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_full - Inserts a node as the left-child of another node
 * @node: Pointer to the node to insert the left-child in
 *
 * Return: Pointer to the created node, or NULL on failure
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
    if (tree->left == tree->right && tree->left == NULL)
        return (1);

    if(binary_tree_is_full(tree->left) && (binary_tree_is_full(tree->right)))
        return (1);
    return (0);
}

/**
 * binary_tree_height0 - Inserts a node as the left-child of another node
 * @tree: Pointer to the node to insert the left-child in
 *
 * Return: Pointer to the created node, or NULL on failure
 */

int binary_tree_height0(const binary_tree_t *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height0(tree->left);
	right_height = binary_tree_height0(tree->right);

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

	return (binary_tree_height0(tree->left) - binary_tree_height0(tree->right));

}

/**
 * binary_tree_height - Inserts a node as the left-child of another node
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
 * binary_tree_nodes_c -  counts the nodes
 * @tree: pointer to the root node of the tree to count the number of nodes.
 *
 * Return: If tree is NULL, the function must return 0.
*/

size_t binary_tree_nodes_count(const binary_tree_t *tree)
{
	size_t left_leaves, right_leaves;

	if (tree == NULL)
		return (0);

	left_leaves = binary_tree_nodes_count(tree->left);
	right_leaves = binary_tree_nodes_count(tree->right);

	return (left_leaves + right_leaves + 1);
}

/**
 * binary_tree_is_perfect - Inserts a node as the left-child of another node
 * @node: Pointer to the node to insert the left-child in
 *
 * Return: Pointer to the created node, or NULL on failure
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int number_of_nodes;
    int height_of_tree;

	if (tree == NULL)
		return (0);
    if (binary_tree_balance(tree) == 0 && binary_tree_is_full(tree))
    {
        height_of_tree = binary_tree_height(tree);
        number_of_nodes = pow(2, height_of_tree + 1) - 1;
        if (number_of_nodes == (int)binary_tree_nodes_count(tree))
            return (1);
    }
    return (0);
}
