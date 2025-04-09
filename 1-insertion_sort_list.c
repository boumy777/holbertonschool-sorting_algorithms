#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort.
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			/* Swap temp and temp->prev */
			listint_t *prev = temp->prev;

			if (prev->prev)
				prev->prev->next = temp;
			temp->prev = prev->prev;

			prev->next = temp->next;
			if (temp->next)
				temp->next->prev = prev;

			temp->next = prev;
			prev->prev = temp;

			/* Update head if necessary */
			if (!temp->prev)
				*list = temp;

			print_list(*list);
		}
		current = current->next;
	}
}

