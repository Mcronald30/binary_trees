#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: To calculate the height for.
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_h = 0;
	size_t r_h = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l_h = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			r_h = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((l_h > r_h) ? l_h : r_h);
	}
}

/**
 * is_subtree_avl - Auxiliary function to check if a subtree is AVL.
 * @tree: The root of the subtree to check.
 * @lower: The lower bound for node values in the subtree.
 * @upper: The upper bound for node values in the subtree.
 * Return: 1 if the subtree is AVL, 0 if not.
 */
int is_subtree_avl(const binary_tree_t *tree, int lower, int upper)
{
	size_t h_l, h_r, balance_factor;

	if (tree != NULL)
	{
		if (tree->n > upper || tree->n < lower)
		{
			return (0);
		}
		h_l = binary_tree_height(tree->left);
		h_r = binary_tree_height(tree->right);
		balance_factor = (h_l > h_r) ? h_l - h_r : h_r - h_l;
		if (balance_factor > 1)
		{
			return (0);
		}
		return (is_subtree_avl(tree->left, lower, tree->n - 1) &&
				is_subtree_avl(tree->right, tree->n + 1, upper));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: The binary tree to check.
 * Return: 1 if the tree is AVL, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (is_subtree_avl(tree, INT_MIN, INT_MAX));
}
