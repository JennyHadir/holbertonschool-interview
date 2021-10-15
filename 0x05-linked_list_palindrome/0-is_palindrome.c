#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * recursive_palindrome - Recursive palindrom
 * @head: double pointer of the  head node
 * @tail: double pointer of the tail node
 * Return: 1 if is a palindrome 0 otherwise
 */
int recursive_palindrome(listint_t **head, listint_t *tail)
{
	if (tail == NULL)
		return (1);

	if (recursive_palindrome(head, tail->next) && (*head)->n == tail->n)
	{
		*head = (*head)->next;
		return (1);
	}
    return (0);
}

/**
 * is_palindrome - Check if a linked list is palindromeor not
 * @head: double pointer of head node
 * Return: 1 if is a palindrome 0 otherwise
 */

int is_palindrome(listint_t **head)
{
	if (head == NULL && *head == NULL)
		return (1);
    return (recursive_palindrome(head, *head));
}
