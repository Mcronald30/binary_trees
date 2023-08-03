#include "binary_trees.h"

/**
 * bst_search - Searches for a specific value in
 * the tree and returns the node containing it.
 * @tree: Tree to traverse.
 * @value: Value to search for.
 * Return: a pointer to the node containing a value
 * equals to value if tree is NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *search;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		search = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		search = bst_search(tree->right, value);
	}
	else if (value == tree->n)
	{
		return ((bst_t *)tree);
	}
	else
	{
		return (NULL);
	}
	return (search);
}
