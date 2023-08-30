#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree using in-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * Description: In in-order traversal, we recursively visit the left subtree,
 * then visit the current node, and
 * finally recursively visit the right subtree.
 *
 * If tree or func is NULL, do nothing.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	/* Recursively visit the left subtree */
	binary_tree_inorder(tree->left, func);
	/* Visit the current node */
	func(tree->n);
	/* Recursively visit the right subtree */
	binary_tree_inorder(tree->right, func);
}
