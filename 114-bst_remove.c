#include <stdlib.h>
#include "binary_trees.h"

/**
 * get_successor - Finds the next successor
 * @node: Tree node to check.
 * Return: The minimum value of the right subtree.
 */
int get_successor(bst_t *node)
{
	int l = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		l = get_successor(node->left);
		if (l == 0)
		{
			return (node->n);
		}
		return (l);
	}
}

/**
 * replace_with_successor - Gets the next successor using the min
 * value in the right subtree
 * @root: Node that has two children.
 * Return: The value found.
 */
int replace_with_successor(bst_t *root)
{
	int new_value = 0;

	new_value = get_successor(root->right);
	root->n = new_value;
	return (new_value);
}

/**
 * remove_type - Removes a node depending on its children.
 * @root: Node to remove.
 * Return: 0 if it has no children or another value if it has.
 */
int remove_type(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
		root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (replace_with_successor(root));
}

/**
 * bst_remove - Removes a node from a BST tree.
 * @root: Root of the tree.
 * @value: Node with this value to remove.
 * Return: The modified tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);

	return (root);
}
