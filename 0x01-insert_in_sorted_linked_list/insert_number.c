#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list
 * @head : pointer to the first node of a list
 * @number : number to insert
 * Return: Adresse of a new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = NULL, *tmp = NULL;

	if (!head)
		return (NULL);
	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->n = number;
	node->next = NULL;
	if(!*head)
		*head = node;
	else if (number < (*head)->n)
	{
		node->next = *head;
		*head = node;
	}
	else
	{
		tmp = *head;
		while (tmp->next && tmp->next->n < number)
		{
			tmp = tmp->next;
		}
		node->next = tmp->next;
		tmp->next = node;
	}
	return (node);		
}