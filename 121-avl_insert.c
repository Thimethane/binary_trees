#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: A double pointer to the root node of the AVL tree.
 * @value: The value to insert in the tree.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int balance;

	if (!tree)
		return (NULL);
	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));
	if (value < (*tree)->n)
		(*tree)->left = avl_insert(&((*tree)->left), value);
	else if (value > (*tree)->n)
		(*tree)->right = avl_insert(&((*tree)->right), value);
	else
		return (NULL);
	(*tree)->height = 1 + binary_tree_height((*tree)->left);
	if ((*tree)->height < binary_tree_height((*tree)->right))
		(*tree)->height = 1 + binary_tree_height((*tree)->right);
	balance = binary_tree_balance(*tree);
	if (balance > 1)
	{
		if (value < (*tree)->left->n)
			return binary_tree_rotate_right(*tree);
		else
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			return binary_tree_rotate_right(*tree);
		}
	}
	if (balance < -1)
	{
		if (value > (*tree)->right->n)
			return binary_tree_rotate_left(*tree);
		else
		{
			(*tree)->right = binary_tree_rotate_right((*tree)->right);
			return binary_tree_rotate_left(*tree);
		}
	}
	return (*tree);
}
/**
 * max - Returns the maximum of two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The maximum value between a and b.
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}
