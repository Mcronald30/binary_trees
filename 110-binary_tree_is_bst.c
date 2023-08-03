#include "binary_trees.h"

/**
 * is_subtree_smaller - checks if a binary tree is a valid BST
 * @node: verify the condition of node in tree.
 * @max: Value to compare with.
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */
int is_subtree_smaller(const binary_tree_t *node, int max)
{
	if (node == NULL)
		return (1);

	if (node->n >= max)
		return (0);

	return (is_subtree_smaller(node->left, max)
			&& is_subtree_smaller(node->right, max));
}

/**
 * is_subtree_bigger - Checks if all nodes in the subtree are
 * bigger than the specified root value.
 * @node: verify the condition of node in tree.
 * @min: Value to compare with.
 * Return: 1 if all nodes are bigger or equal, 0 otherwise.
 */
int is_subtree_bigger(const binary_tree_t *node, int min)
{
	if (node == NULL)
		return (1);

	if (node->n <= min)
		return (0);

	return (is_subtree_bigger(node->left, min)
		&& is_subtree_bigger(node->right, min));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid
 * @tree: Node that points to the tree to check.
 * Return: 1 if it is a BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((tree->left && tree->left->n > tree->n) ||
			(tree->right && tree->right->n < tree->n))
		return (0);

	if (tree->left && tree->left->n < tree->n
			&& !is_subtree_smaller(tree->left, tree->n))
		return (0);

	if (tree->right && tree->right->n > tree->n
			&& !is_subtree_bigger(tree->right, tree->n))
		return (0);

	return (1);
}
