#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *_node;

	if (list == NULL || (*list)->next == NULL)
		return;
	_node = (*list)->next;
	while (_node)
	{
		while ((_node->prev) && (_node->prev->n > _node->n))
		{
			_node = swap_node(_node, list);
			print_list(*list);
		}
		_node = _node->next;
	}
}
/**
 *swap_node - swap a node
 *@node: node
 *@list: node list
 *Return: return a pointer to a node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *prv = node->prev, *cur = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	prv->next = cur->next;
	if (cur->next)
		cur->next->prev = prv;
	cur->next = prv;
	cur->prev = prv->prev;
	prv->prev = cur;
	if (cur->prev)
		cur->prev->next = cur;
	else
		*list = cur;
	return (cur);
}
