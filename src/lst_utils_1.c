/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:03:45 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/02 01:11:23 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_add_top(t_node **head, int val)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return ;
	new->val = val;
	new->next = *head;
	*head = new;
}

void	lst_add_bottom(t_node *head, int val)
{
	t_node	*new_last;

	new_last = head;
	while (new_last->next != NULL)
		new_last = new_last->next;
	new_last->next = malloc(sizeof(t_node));
	new_last = new_last->next;
	new_last->val = val;
	new_last->next = NULL;
}

int	lst_del_first(t_node **head)
{
	int		retval;
	t_node	*next_node;

	retval = (*head)->val;
	next_node = (*head)->next;
	free(*head);
	*head = next_node;
	return (retval);
}

int	lst_del_last(t_node *head)
{
	int		ret_val;
	t_node	*new_last;

	new_last = head;
	while (new_last->next->next != NULL)
		new_last = new_last->next;
	ret_val = new_last->next->val;
	free(new_last->next);
	new_last->next = NULL;
	return (ret_val);
}

void	lst_free(t_node **lst)
{
	t_node	*tmp;

	while ((*lst) != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}
