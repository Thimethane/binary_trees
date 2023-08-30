#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes in a binary tree with at least one child
 * @tree: Pointer to the root node of the tree to count nodes
 *
 * Return: The number of nodes with at least one child in the binary tree.
 * If tree is NULL, return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left || tree->right)
		return (binary_tree_nodes(tree->left) + 
				1 + binary_tree_nodes(tree->right));
	return (0);
}
