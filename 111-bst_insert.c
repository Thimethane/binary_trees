#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree (BST).
 *
 * @tree: A double pointer to the root node of the BST.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current, *parent;

	if (tree == NULL)
		return (NULL);
	current = *tree;
	parent = NULL;
	/*Check if the value is already present in the tree*/
	while (current != NULL)
	{
		parent = current;
		if (value == current->n)
			return (NULL); /* Value already exists, return NULL*/
		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}
	/*Create a new node and set its value*/
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	/*Insert the new node as a child of the parent*/
	if (parent == NULL)
		*tree = new_node; /*If tree is NULL, set the new node as the root*/
	else if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;
	return (new_node);
}
