#include "binary_trees.h"

/**
 * create_tree_using_middle - Creates a tree using
 * the middle element of a sorted array.
 * @parent: The parent node of the node to be created.
 * @array: The sorted array.
 * @begin: The starting position of the array.
 * @last: The ending position of the array.
 * Return: The created tree.
 */
avl_t *create_tree_using_middle(avl_t *parent,
		int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		 aux = binary_tree_node((binary_tree_t *)parent, array[mid]);

		 if (aux == NULL)
			 return (NULL);

		 root = (avl_t *)aux;
		 root->left = create_tree_using_middle(root, array, begin, mid - 1);
		 root->right = create_tree_using_middle(root, array, mid + 1, last);
		 return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - Creates an AVL tree
 * from a sorted array.
 * @array: The sorted array.
 * @size: The size of the sorted array.
 * Return: The AVL tree created from the sorted array.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (create_tree_using_middle
			(NULL, array, 0, ((int)(size)) - 1));
}
