#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - measure the height of a binary tree
 * @tree: root node of the tree.
 * Return: Nothing
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left)
			left_height = 1 + binary_tree_height(tree->left);

		if (tree->right)
			right_height = 1 + binary_tree_height(tree->right);

		return ((left_height > right_height) ? left_height : right_height);
	}
}

/**
 * binary_tree_depth - find the depth of a specified node.
 * @tree: root node of the tree.
 * Return: Nothing
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - create a linked list with depth level
 * @head: pointer to head of linked list
 * @tree: root node of the tree.
 * @level: depth of node to store
 * Return: NULL.
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *current, *data;

	current = malloc(sizeof(link_t));
	if (current == NULL)
	{
		return;
	}

	current->n = level;
	current->node = tree;

	if (*head == NULL)
	{
		current->next = NULL;
		*head = current;
	}
	else
	{
		data = *head;
		while (data->next != NULL)
		{
			data = data->next;
		}

		current->next = NULL;
		data->next = current;
	}
}

/**
 * recursion - complete tree and store each node in linked_node
 * @head: pointer to head of linked list.
 * @tree: root node of the tree.
 * Return: Nothing
 */
void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - binary tree using level-order traversal
 * @tree: root node of the tree to traverse.
 * @func: function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *data;
	size_t height = 0, queue = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);

		while (queue <= height)
		{
			data = head;
			while (data != NULL)
			{
				if (queue == data->n)
				{
					func(data->node->n);
				}
				data = data->next;
			}
			queue++;
		}
		while (head != NULL)
		{
			data = head;
			head = head->next;
			free(data);
		}
	}
}
