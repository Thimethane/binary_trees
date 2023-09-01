#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs level-order traversal of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function traverses the binary tree in level-order and
 * calls the provided function for each visited node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *temp;
	queue_t *queue = NULL;

	if (!tree || !func)
		return;
	enqueue(&queue, (binary_tree_t *)tree);
	while (queue)
	{
		temp = dequeue(&queue);
		func(temp->n);
		if (temp->left)
			enqueue(&queue, temp->left);

		if (temp->right)
			enqueue(&queue, temp->right);
	}
}

/**
 * enqueue - Adds a node to the end of the queue
 * @rear: Pointer to the rear of the queue
 * @node: Pointer to the node to add
 *
 * Description: This function adds a node to the end of the queue.
 */
void enqueue(queue_t **rear, binary_tree_t *node)
{
	queue_t *new_node = malloc(sizeof(queue_t));

	if (!new_node)
		exit(1);
	new_node->node = node;
	new_node->next = NULL;
	if (!*rear)
	{
		new_node->prev = NULL;
		*rear = new_node;
	}
	else
	{
		new_node->prev = *rear;
		(*rear)->next = new_node;
		*rear = new_node;
	}
}

/**
 * dequeue - Removes and returns the front node of the queue
 * @front: Pointer to the front of the queue
 *
 * Return: Pointer to the front node of the queue,
 * or NULL if the queue is empty
 *
 * Description: This function removes and returns the front node of the queue.
 */
binary_tree_t *dequeue(queue_t **front)
{
	binary_tree_t *node;
	queue_t *temp;

	if (!*front)
		return (NULL);
	node = (*front)->node;
	temp = *front;
	*front = (*front)->next;
	if (*front)
		(*front)->prev = NULL;
	free(temp);
	return (node);
}
