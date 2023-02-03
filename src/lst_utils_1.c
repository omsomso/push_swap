/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:03:45 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 00:45:33 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_add_top(node_t **head, int val, int split)
{
	node_t	*new;

	new = malloc(sizeof(node_t));
	if (new == NULL)
		return ;
	new->val = val;
	new->split = split;
	new->next = *head;
	*head = new;
}

void	lst_add_bottom(node_t *head, int val, int split)
{
	node_t	*new_last;

	new_last = head;
	while (new_last->next != NULL)
		new_last = new_last->next;
	new_last->next = malloc(sizeof(node_t));
	new_last = new_last->next;
	new_last->val = val;
	new_last->split = split;
	new_last->next = NULL;
}

int	lst_del_first(node_t **head)
{
	int		retval;
	node_t	*next_node;

	retval = (*head)->val;
	next_node = (*head)->next;
	free(*head);
	*head = next_node;
	return (retval);
}

int	lst_del_last(node_t *head)
{
	int		ret_val;
	node_t	*new_last;

	new_last = head;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	ret_val = new_last->next->val;
	free(new_last->next);
	new_last->next = NULL;
	return (ret_val);
}

void	lst_free(node_t **lst)
{
	node_t	*tmp;

	while ((*lst) != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}
