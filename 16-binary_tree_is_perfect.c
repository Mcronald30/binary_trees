#include "binary_trees.h"

/**
 * tree_is_perfect - measures the height of a binary tree.
 * @tree: measure the height
 * Return: height of the tree, or 0 if tree is NULL
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int l_h = 0, r_h = 0;

	if (tree->left && tree->right)
	{
		l_h = 1 + tree_is_perfect(tree->left);
		r_h = 1 + tree_is_perfect(tree->right);
		if (r_h == l_h && r_h != 0 && l_h != 0)
			return (r_h);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: tree to check the binary
 * Return: 1 if the tree is perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int node = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		node = tree_is_perfect(tree);
		if (node != 0)
		{
			return (1);
		}
		return (0);
	}
}
