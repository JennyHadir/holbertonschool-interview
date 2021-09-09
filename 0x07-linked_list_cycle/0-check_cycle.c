#include "lists.h"
/**
* check_cycle - checks if a linked list has a cycle
* @list: pointer to list
* Return: 1 if it has a cycle 0 otherwise
*/
int check_cycle(listint_t *list)
{
	if (list == NULL)
		return (0);
	while (list)
	{
		if (list->next >= list)
			return (1);
		list = list->next;
	}
	return (0);
}