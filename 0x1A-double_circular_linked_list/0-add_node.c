#include "list.h"
/**
* create_node - Node creator
* @str: data of the new node
* Return: adress of new node, NULL on failure
*/
List *create_node(char *str)
{
	List *node = NULL;

	node = malloc(sizeof(List));
	if (!node)
		return (NULL);
	node->str = strdup(str);
	if (!node->str)
	{
		free(node->str);
		return (NULL);
	}
	node->next = node->prev = NULL;
	return (node);
}

/**
* add_node_end - add a node at the end of a list
* @list: pointer to a list
* @str: data of the new node
* Return: adress of new node, NULL on failure
*/
List *add_node_end(List **list, char *str)
{
	List *node, *end;

	if (!list || !str)
		return (NULL);
	node = create_node(str);
	if (!node)
		return (NULL);
	if (*list)
	{
		end = (*list)->prev;
		end->next = node;
		node->prev = end;
		node->next = (*list);
		(*list)->prev = node;
	}
	else
	{
		*list = node;
		node->prev = node->next = node;
	}

	return (node);
}

/**
* add_node_begin - add a node at the beginning of a list
* @list: pointer to a list
* @str: data of the new node
* Return: adress of new node, NULL on failure
*/
List *add_node_begin(List **list, char *str)
{
	List *end, *node;

	node = create_node(str);
	if (!node)
		return (NULL);
	if (*list)
	{
		end = (*list)->prev;
		end->next = node;
		(*list)->prev = node;
		node->prev = end;
		node->next = (*list);
		*list = node;
	}
	else
	{
		(*list) = node;
		node->next = node->prev = node;
	}

	return (NULL);
}