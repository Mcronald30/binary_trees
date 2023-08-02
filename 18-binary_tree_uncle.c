#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node.
 * @node: pointer to the node to find the uncle.
 * Return: pointer to the uncle node if node NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	binary_tree_t *grandpa = node->parent->parent;

	if (grandpa->left == node->parent)
	{
		return (grandpa->right);
	}
	else
	{
		return (grandpa->left);
	}
}