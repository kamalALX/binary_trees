#include "binary_trees.h"

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
