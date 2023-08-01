#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: root node of the tree
 * Return: If tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_h = 0;
	size_t r_h = 0;

	if (tree == NULL)
		return (0);

	l_h = binary_tree_height(tree->left);
	r_h = binary_tree_height(tree->right);

	return (1 + (l_h > r_h ? l_h : r_h));
}
