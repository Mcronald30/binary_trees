#include "binary_trees.h"

/**
 * array_to_bst - Converts an array into a BST
 * @array: Array to be converted to a BST tree.
 * @size: Size of the array.
 * Return: Pointer to create BST tree from the array.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}
	return (root);
}
