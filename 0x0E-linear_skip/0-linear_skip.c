#include "search.h"

/**
 * linear_skip - Search for a value in a skip list.
 * @list: Pointer to the head of the skip list.
 * @value: Value to search for.
 * Return: Pointer to the first node where value is located.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    if (list != NULL)
    {
        
        skiplist_t *tmp, *nextTmp;
        tmp = list;
        nextTmp = tmp->express;
        while (nextTmp != NULL)
        {
            printf("Value checked at index [%ld] = [%d]\n", nextTmp->index, nextTmp->n);
            if (nextTmp->n < value)
            {
                tmp = tmp->express;
                nextTmp = nextTmp->express;
            }
            else if(value <= nextTmp->n)
            {
                printf("Value found between indexes [%ld] and [%ld]\n", tmp->index, nextTmp->index);
                while (tmp->index <= nextTmp->index)
                {
                    printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);
                    if (tmp->n == value)
                    {
                        return(tmp);

                    }
                    tmp = tmp->next;
                } 
            }
            else
            {
                return(tmp);
            }           
        }
    }
    return NULL;
}
