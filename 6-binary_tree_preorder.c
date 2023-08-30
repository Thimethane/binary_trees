#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * Description: In pre-order traversal, we visit the current node, then
 * recursively visit the left subtree, and finally recursively visit
 * the right subtree.
 *
 * If tree or func is NULL, do nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	/* Visit the current node */
	func(tree->n);
	/* Recursively visit the left subtree */
	binary_tree_preorder(tree->left, func);
	/* Recursively visit the right subtree */
	binary_tree_preorder(tree->right, func);
}
