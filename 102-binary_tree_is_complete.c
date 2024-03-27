#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
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
