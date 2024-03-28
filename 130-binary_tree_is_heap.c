#include "binary_trees.h"

/**
 * isComplete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
*/

int isComplete(binary_tree_t *tree)
{
	binary_tree_t *queue[1024];
	int rear = 0, front = 0;
	binary_tree_t *temp_node;
	int flag = 0;

	if (tree == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front != rear)
	{
		temp_node = queue[front++];
		if (temp_node->left)
		{
			if (flag == 1)
				return (0);
			queue[rear++] = temp_node->left;
		}
		else
		{
			flag = 1;
		}
		if (temp_node->right)
		{
			if (flag == 1)
				return (0);
			queue[rear++] = temp_node->right;
		}
		else
		{
			flag = 1;
		}
	}
	return (1);
}

/**
 * isHeap - checks if a binary tree is a heap
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a heap, 0 otherwise
 */

int isHeap(binary_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->right == NULL)
		return (tree->n >= tree->left->n);

	if (tree->n >= tree->left->n && tree->n >= tree->right->n)
		return (isHeap(tree->left) && isHeap(tree->right));
	else
		return (0);
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid Max Binary Heap, and 0 otherwise
*/

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (isComplete((binary_tree_t *)tree) && isHeap((binary_tree_t *)tree))
		return (1);

	return (0);
}

