#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: node to measure the depth.
 * Return: The depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->parent != NULL)
		return (1 + binary_tree_depth(tree->parent));

	return (0);
}
