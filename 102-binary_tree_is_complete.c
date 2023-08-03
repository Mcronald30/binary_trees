#include <stdlib.h>
#include "binary_trees.h"

/**
 * newNode - Creates a new node for a linked list.
 * @node: Pointer to a binary tree node.
 * Return: newly created node.
 */
link_t *newNode(binary_tree_t *node)
{
	link_t *current;

	current = malloc(sizeof(link_t));
	if (current == NULL)
	{
		return (NULL);
	}
	current->node = node;
	current->next = NULL;

	return (current);
}

/**
 * freeQueue - Frees the nodes in the linked list.
 * @h: head node of the linked list.
 */
void freeQueue(link_t *h)
{
	link_t *temp_node;

	while (h)
	{
		temp_node = h->next;
		free(h);
		h = temp_node;
	}
}

/**
 * push - Pushes a node into the stack.
 * @node: Pointer to a node in the binary tree.
 * @h: head node of the stack.
 * @tail: tail node of the stack.
 */
void push(binary_tree_t *node, link_t *h, link_t **tail)
{
	link_t *current;

	current = newNode(node);
	if (current == NULL)
	{
		freeQueue(h);
		exit(1);
	}
	(*tail)->next = current;
	*tail = current;
}

/**
 * pop - Pops a node from the stack.
 * @h: Pointer to the head node of the stack.
 */
void pop(link_t **h)
{
	link_t *temp_node;

	temp_node = (*h)->next;
	free(*h);
	*h = temp_node;
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: root node of the binary tree.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *h, *tail;
	int flag = 0;

	if (tree == NULL)
	{
		return (0);
	}
	h = tail = newNode((binary_tree_t *)tree);
	if (h == NULL)
	{
		exit(1);
	}
	while (h != NULL)
	{
		if (h->node->left != NULL)
		{
			if (flag == 1)
			{
				freeQueue(h);
				return (0);
			}
			push(h->node->left, h, &tail);
		}
		else
			flag = 1;
		if (h->node->right != NULL)
		{
			if (flag == 1)
			{
				freeQueue(h);
				return (0);
			}
			push(h->node->right, h, &tail);
		}
		else
			flag = 1;
		pop(&h);
	}
	return (1);
}
