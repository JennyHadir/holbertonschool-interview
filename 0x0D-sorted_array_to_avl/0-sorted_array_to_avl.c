#include "binary_trees.h"
#include <stdlib.h>
/**
 * node_creator - create a node
 * 
 * @parent: parent node
 * @n: value of the node 
 * Return: pointer to the node
 */


avl_t *node_creator(avl_t *parent, int n)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->n = n;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * node_insertion - Insert a node in the avl
 * 
 * @array: pouinter to array
 * @start: first index
 * @end: last index
 * @parent: parent node
 * Return: pointer to the root node
 */
avl_t *node_insertion(int *array, int start, int end, avl_t *parent)
{
	int mid_index;
	avl_t *root;

	if (start > end)
		return (NULL);
	mid_index = (start + end) / 2;
	root = node_creator(parent, array[mid_index]);
	if (!root)
		return (NULL);
	if (mid_index != start)
		root->left = node_insertion(array, start, mid_index - 1, root);
	if (mid_index != end)
		root->right = node_insertion(array, mid_index + 1, end, root);

	return (root);    

}

/**
 * sorted_array_to_avl - convert a sorted array to AVL
 * 
 * @array: array to convert 
 * @size: size of array
 * Return: pointer to root
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	if (!array)
		return (NULL);

	root = node_insertion(array, 0, size - 1, NULL);
	return (root);
}