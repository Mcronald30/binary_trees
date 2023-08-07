#include "binary_trees.h"
#include <stdlib.h>

/**
 * balance_and_rotate - Measures the balance factor of an
 * AVL tree and performs rotations if necessary.
 * @tree: The AVL tree to balance.
 */
void balance_and_rotate(avl_t **tree)
{
	int b_val;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	balance_and_rotate(&(*tree)->left);
	balance_and_rotate(&(*tree)->right);

	b_val = binary_tree_balance((const binary_tree_t *)*tree);

	if (b_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (b_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * find_successor - Finds the successor (minimum value)
 * in a binary search tree.
 * @node: The root of the tree to search.
 * Return: The minimum value found.
 */
int find_successor(bst_t *node)
{
	int left_value = 0;

	if (node == NULL)
		return (0);

	else
	{
		left_value = find_successor(node->left);

		if (left_value == 0)
			return (node->n);

		return (left_value);
	}
}

/**
 * handle_removal_type - Handles the removal of a
 * node based on its children.
 * @root: The node to remove.
 * Return: 0 if it has no children, otherwise a diff value.
 */
int handle_removal_type(bst_t *root)
{
	int new_value = 0;

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
	{
		new_value = find_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * remove_from_bst - Removes a node from a Binary Search Tree (BST).
 * @root: The root of the tree.
 * @value: The value of the node to remove.
 * Return: The updated tree after removal.
 */
bst_t *remove_from_bst(bst_t *root, int value)
{
	int removal_type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		remove_from_bst(root->left, value);
	else if (value > root->n)
		remove_from_bst(root->right, value);
	else if (value == root->n)
	{
		removal_type = handle_removal_type(root);

		if (removal_type != 0)
			remove_from_bst(root->right, removal_type);
	}
	else
		return (NULL);

	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: The root of the AVL tree.
 * @value: The value of the node to remove.
 * Return: The updated AVL tree after removal.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *updated_root = (avl_t *) remove_from_bst((bst_t *) root, value);

	if (updated_root == NULL)
		return (NULL);

	balance_and_rotate(&updated_root);
	return (updated_root);
}
