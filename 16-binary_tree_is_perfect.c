#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree.
 * @tree: measure the height
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t l_h, r_h;

	if (tree == NULL)
	{
		return (0);
	}

	l_h = tree_height(tree->left);
	r_h = tree_height(tree->right);

	return (1 + (l_h > r_h ? l_h : r_h));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: tree to check the binary
 * Return: 1 if the tree is perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		result = tree_height(tree);
		if (result != 0)
		{
			return (1);
		}
		return (0);
	}
}
