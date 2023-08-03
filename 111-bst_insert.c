#include "binary_trees.h"

/**
 * bst_insert - Inserts nodes to create a BST
 * @tree: Pointer to the tree to create BST
 * @value: Value of the node to insert.
 * Return: Pointer to the BST tree.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *temp;
	binary_tree_t *data;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		data = binary_tree_node((binary_tree_t *)(*tree), value);
		current = (bst_t *)data;
		*tree = current;
	}
	else
	{
		temp = *tree;
		if (value < temp->n)
		{
			if (temp->left)
				current = bst_insert(&temp->left, value);
			else
			{
				data = binary_tree_node((binary_tree_t *)temp, value);
				current = temp->left = (bst_t *)data;
			}
		}
		else if (value > temp->n)
		{
			if (temp->right)
				current = bst_insert(&temp->right, value);
			else
			{
				data = binary_tree_node((binary_tree_t *)temp, value);
				current = temp->right = data;
			}
		}
		else
			return (NULL);
	}
	return (current);
}
