#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * Description: In post-order traversal, we recursively visit the subtree,
 * then recursively visit the right subtree,
 * and finally visit the current node.
 *
 * If tree or func is NULL, do nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	/* Recursively visit the left subtree */
	binary_tree_postorder(tree->left, func);
	/* Recursively visit the right subtree */
	binary_tree_postorder(tree->right, func);
	/* Visit the current node */
	func(tree->n);
}
