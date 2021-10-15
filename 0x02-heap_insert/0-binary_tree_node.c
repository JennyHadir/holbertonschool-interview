#include "binary_trees.h"
/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: The value to put in the new node
 * Return: Pointer to the new node otherwise NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new;
	
	new = malloc(sizeof(binary_tree_t));
	if (new == NULL) {
		return (NULL);
	}
	if (parent == NULL) {
		new->parent = NULL;
    }
	else {
		new->parent = parent;
    }
	new->right = NULL;
	new->left = NULL;
	new->n = value;
	return (new);
}