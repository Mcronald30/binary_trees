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
	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	binary_tree_t *l_lca;
	binary_tree_t *r_lca;

	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	l_lca = first->parent;
	r_lca = second->parent;
	if (l_lca == NULL || first == r_lca || (!l_lca->parent && r_lca))
	{
		return (binary_trees_ancestor(first, r_lca));
	}
	else if (r_lca == NULL || l_lca == second || (!r_lca->parent && l_lca))
	{
		return (binary_trees_ancestor(l_lca, second));
	}
	return (binary_trees_ancestor(l_lca, r_lca));
}
