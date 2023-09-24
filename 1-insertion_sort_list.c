#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integer
 * in ascending order
 *                        using the insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the doubly linked list.
 *
 * Description: This function implements the insertion sort algorithm to sort a
 *              doubly linked list of integers in ascending order. It compares
 *              adjacent nodes and swaps them if they are in
 *              the wrong order until
 *              the entire list is sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *next = NULL;

	if (list == NULL || *list == NULL)
		return;

	temp = (*list)->next;
	for (; temp; temp = next)
	{
		next = temp->next;
		while (temp->prev && temp->prev->n > temp->n)
		{
			/* Swap adjacent nodes */
			temp->prev->next = temp->next;
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;
			if (!temp->prev)
				*list = temp;
			else
				temp->prev->next = temp;

			/* Print the current state of the list */
			print_list(*list);
		}
		temp = next;
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to a pointer to the head of the doubly linked list.
 * @l: The left node to swap.
 * @r: The right node to swap.
 *
 * Description: This function swaps two nodes in a doubly linked list.
 *              It updates the necessary pointers to maintain the integrity
 *              of the list after the swap.
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
 * insertion_sort_list2 - Sorts a doubly linked list of integers
 * in ascending order
 *                         using the insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the doubly linked list.
 *
 * Description: This function sorts a doubly linked list of
 * integers in ascending order
 *              using the insertion sort algorithm. It compares
 *              each node with the previous
 *              nodes and swaps them if necessary until the entire
 *              list is sorted.
 */
void insertion_sort_list2(listint_t **list)
{
	listint_t *node0 = NULL, *node1 = NULL, *node2 = NULL, *tmp = NULL;

	if (list != NULL)
	{
		node0 = *list == NULL ? NULL : (*list)->next;
		while (node0 != NULL)
		{
			node1 = node0;
			node2 = node1->prev;
			node0 = node0->next;
			while ((node1 != NULL) && (node2 != NULL))
			{
				tmp = node2;
				if (node2->n > node1->n)
				{
					swap_nodes(list, node1, node2);

					/* Print the current state of the list */
					print_list(*list);
				}
				node1 = tmp;
				node2 = tmp->prev;
			}
		}
	}
}
