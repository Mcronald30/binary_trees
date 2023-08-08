#include "binary_trees.h"

/**
 * recur_insert_node - Recursively inserts a node
 * with a value into an AVL tree.
 * @tree: Pointer to the root node of the AVL tree.
 * @parent: Parent node of the current node being checked.
 * @new: Pointer to store the newly inserted node.
 * @nval: Value to be inserted into the tree.
 * Return: Pointer to the new root after insertion, or NULL.
 */
avl_t *recur_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	int bal_val;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, nval));

	if ((*tree)->n > nval)
	{
		(*tree)->left = recur_insert_node(&(*tree)->left, *tree, new, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = recur_insert_node(&(*tree)->right, *tree, new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}

	bal_val = binary_tree_balance(*tree);
	if (bal_val > 1 && (*tree)->left->n > nval)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bal_val > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bal_val < -1 && (*tree)->right->n < nval)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (bal_val < -1 && (*tree)->right->n > nval)

		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Pointer to the root node of the AVL tree to be inserted.
 * @value: The value to be stored in the new node.
 * Return: The inserted node or NULL if insertion fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	recur_insert_node(tree, *tree, &new_node, value);
	return (new_node);
}
