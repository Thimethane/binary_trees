#include "binary_trees.h"
#include <limits.h>

/**
 * is_avl - Helper function to check if a binary tree is an AVL tree.
 * @tree: A pointer to the root node of the tree.
 * @min: The minimum allowed value for nodes in the tree.
 * @max: The maximum allowed value for nodes in the tree.
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise.
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	balance_factor = left_height - right_height;
	if (balance_factor < -1 || balance_factor > 1)
		return (0);
	return (is_avl(tree->left, min, tree->n) &&
			is_avl(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Check if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX));
}
/**
 * binary_tree_height - Measure the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return (1 + (left_height > right_height ? left_height : right_height));
}
