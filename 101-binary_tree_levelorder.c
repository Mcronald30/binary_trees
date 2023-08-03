#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - binary tree using level-order traversal
 * @tree: root node of the tree to traverse.
 * @func: function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1000);
	if (queue == NULL)
		return;

	int front = 0;
	int rear = -1;

	queue[++rear] = (binary_tree_t *)tree;

	while (front <= rear)
	{
		binary_tree_t *current = queue[front++];
		func(current->n);

		if (current->left)
			queue[++rear] = current->left;

		if (current->right)
			queue[++rear] = current->right;
	}
	free(queue);
}
