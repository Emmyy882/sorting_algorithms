#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to the head of the linked list.
 * @l: The left item to swap.
 * @r: The right item to swap.
 *
 * Description: This function swaps two nodes in a doubly linked list.
 *              It updates the links between the nodes accordingly.
 */
void swap_nodes(listint_t **list, listint_t *l, listint_t *r)
{
	listint_t *tmp0 = NULL, *tmp1 = NULL, *tmp2 = NULL, *tmp3 = NULL;

	if ((l == NULL) || (r == NULL) || (list == NULL) || (l == r))
		return;
	tmp0 = l->prev, tmp1 = l->next, tmp2 = r->prev, tmp3 = r->next;
	if (l->prev == r)
	{
		l->next = r, l->prev = tmp2, r->next = tmp1, r->prev = l;
		if (tmp2 != NULL)
			tmp2->next = l;
		if (tmp1 != NULL)
			tmp1->prev = r;
	}
	else if (l->next == r)
	{
		l->next = tmp3, l->prev = r, r->next = l, r->prev = tmp0;
		if (tmp0 != NULL)
			tmp0->next = r;
		if (tmp3 != NULL)
			tmp3->prev = l;
	}
	else
	{
		l->next = tmp3, l->prev = tmp2, r->next = tmp1, r->prev = tmp0;
		if (tmp0 != NULL)
			tmp0->next = r;
		if (tmp1 != NULL)
			tmp1->prev = r;
		if (tmp2 != NULL)
			tmp2->next = l;
		if (tmp3 != NULL)
			tmp3->prev = l;
	}
	if (l->prev == NULL)
		*list = l;
	if (r->prev == NULL)
		*list = r;
}

/**
 * get_tail - Retrieves the tail node of a doubly linked list.
 * @list: A pointer to the head of the linked list.
 *
 * Return: The tail of the linked list, otherwise NULL.
 *
 * Description: This function traverses the linked list from the head
 *              to the tail and returns the tail node of the list.
 */
listint_t *get_tail(listint_t **list)
{
	listint_t *node = NULL;

	if (list != NULL)
	{
		node = *list;
		while ((node != NULL) && (node->next != NULL))
			node = node->next;
	}
	return (node);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list
 * using the cocktail shaker sort algorithm.
 * @list: The list to be sorted.
 *
 * Description: This function implements the cocktail shaker sort algorithm
 *              to sort a doubly linked list in ascending order. The algorithm
 *              works by iterating through the list in both directions,
 *              swapping adjacent elements if they are out of order. This
 *              process is repeated until no more swaps are needed, indicating
 *              that the list is sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	char swapped = FALSE;
	listint_t *node = NULL, *next = NULL, *tmp;

	if (list == NULL)
		return;
	do {
		node = *list;
		next = (node == NULL ? NULL : node->next);
		swapped = FALSE;
		while ((node != NULL) && (next != NULL))
		{
			tmp = next;
			if (node->n > next->n)
			{
				swap_nodes(list, node, next);
				swapped = TRUE;
				print_list(*list);
			}
			node = tmp, next = (node == NULL ? NULL : node->next);
		}
		if (!swapped)
			break;
		swapped = FALSE;
		next = get_tail(list);
		node = next == NULL ? NULL : next->prev;
		while ((node != NULL) && (next != NULL))
		{
			tmp = node;
			if (node->n > next->n)
			{
				swap_nodes(list, node, next);
				swapped = TRUE;
				print_list(*list);
			}
			next = tmp, node = next == NULL ? NULL : next->prev;
		}
	} while (swapped);
}
