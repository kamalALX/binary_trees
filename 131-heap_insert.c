#include "binary_trees.h"

/**
 * newNode - create a new node.
 * @root: root of the tree.
 * @value: value to insert into node.
 * Return: returns the newlly created node.
*/

heap_t *newNode(heap_t *root, int value)
{
	heap_t *node;

	node = (heap_t *) malloc(sizeof(heap_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = root;
	return (node);
}

/**
 * swap - waps the values of two nodes.
 * @a: first node
 * @b: second node
*/

void swap(heap_t *a, heap_t *b)
{
	int temp;

	temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *queue[1024];
	int rear, front;
	heap_t *temp_node, *new_node;

	new_node = newNode(NULL, value);
	if (new_node == NULL)
		return (NULL);
	if (*root == NULL)
		return (*root = new_node);
	rear = 0;
	front = 0;
	queue[rear++] = *root;

	while (front < rear)
	{
		temp_node = queue[front++];
		if (temp_node->left == NULL)
		{
			new_node->parent = temp_node;
			temp_node->left = new_node;
			break;
		}
		else
			queue[rear++] = temp_node->left;
		if (temp_node->right == NULL)
		{
			new_node->parent = temp_node;
			temp_node->right = new_node;
			break;
		}
		else
			queue[rear++] = temp_node->right;
	}
	while (new_node->parent != NULL && new_node->n > new_node->parent->n)
	{
		swap(new_node, new_node->parent);
		new_node = new_node->parent;
	}
	return (new_node);
}

