#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: The binary tree to calculate the height for.
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
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);

	if (tree)
	{
		l_h = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r_h = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	}
	return ((l_h > r_h) ? l_h : r_h);
	}
}

/**
 * binary_tree_bal - Measures the balance factor of a binary tree.
 * @tree: The binary tree to measure.
 * Return: The balance factor.
 */
int binary_tree_bal(const binary_tree_t *tree)
{
	int r_h = 0, l_h = 0, bal_factor = 0;

	if (tree)
	{
		l_h = ((int)binary_tree_height(tree->left));
		r_h = ((int)binary_tree_height(tree->right));
		bal_factor = l_h - r_h;
	}
	return (bal_factor);
}

/**
 * is_perfect_tree - Checks if a tree is perfect.
 * @tree: The tree to check.
 * Return: 0 if not perfect, otherwise the level of height.
 */
int is_perfect_tree(const binary_tree_t *tree)
{
	int l_level = 0, r_level = 0;

	if (tree->left && tree->right)
	{
		l_level = 1 + is_perfect_tree(tree->left);
		r_level = 1 + is_perfect_tree(tree->right);

		if (r_level == l_level && r_level != 0 && l_level != 0)
			return (r_level);

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
 * binary_tree_is_perfect - Checks if a binary
 * tree is perfect.
 * @tree: The binary tree to check.
 * Return: 1 if perfect, otherwise 0.
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
		result = is_perfect_tree(tree);
		if (result != 0)
		{
			return (1);
		}
		return (0);
	}
}

/**
 * binary_tree_is_heap - Checks if a binary tree is
 * a valid Max Binary Heap.
 * @tree: The binary tree to check.
 * Return: 1 if a valid Max Binary Heap, otherwise 0.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int balance_val;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}

	balance_val = binary_tree_bal(tree);

	if (balance_val == 0)
	{
		return (binary_tree_is_perfect(tree->left)
				&& binary_tree_is_heap(tree->right));
	}
	else if (balance_val == 1)
	{
		return (binary_tree_is_heap(tree->left)
				&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}
