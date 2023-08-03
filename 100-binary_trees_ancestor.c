#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 * Return: pointer to the lowest common ancestor node of the two given nodes.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *depth, *node;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	depth = first->parent;
	node = second->parent;
	if (depth == NULL || first == node || (!depth->parent && node))
	{
		return (binary_trees_ancestor(first, node));
	}
	else if (node == NULL || depth == second || (!node->parent && depth))
	{
		return (binary_trees_ancestor(depth, second));
	}
	return (binary_trees_ancestor(depth, node));
}
