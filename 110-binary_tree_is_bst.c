#include "binary_trees.h"

void binary_tree_inorder1(const binary_tree_t *tree, int queue[], int *rear);

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int i;
	int rear = 0;
	int queue[1024];

	if (tree == NULL)
		return (0);

	binary_tree_inorder1(tree, queue, &rear);

	for (i = 0; i < rear; i++)
	{
		if (queue[i] > queue[i + 1])
			return (0);
	}
	return (1);
}

/**
 * binary_tree_inorder1 - goes through a binary tree using in-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @queue: an integer array to store the node values
 * @rear: a pointer to an integer that represents the rear of the queue
 */

void binary_tree_inorder1(const binary_tree_t *tree, int queue[], int *rear)
{
	if (tree == NULL)
		return;

	binary_tree_inorder1(tree->left, queue, rear);
	queue[++(*rear)] = tree->n;
	binary_tree_inorder1(tree->right, queue, rear);
}
