#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on the binary tree
 * @tree: root node of the tree.
 * Return: new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}

	binary_tree_t *pivot = tree->right;

	tree->right = pivot->left;

	if (pivot->left != NULL)
	{
		pivot->left->parent = tree;
	}

	pivot->left = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;

	return (pivot);
}
