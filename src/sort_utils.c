/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:29:54 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 03:41:27 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_to_idx(node_t **stack, char *which, int idx)
{
	int	i;

	i = 0;
	if (idx > lst_count_el(stack) / 2)
	{
		while (idx < lst_count_el(stack))
		{
			if (which[0] == 'a')
				do_things(stack, stack, "rra");
			if (which[0] == 'b')
				do_things(stack, stack, "rrb");
			idx++;
			i++;
		}
	}
	else
		i = rot_to_idx_larger(stack, which, idx);
	return (i);
}

int	rot_to_idx_larger(node_t **stack, char *which, int idx)
{
	int	i;

	i = 0;
	while (idx > 0)
	{
		if (which[0] == 'a')
			do_things(stack, stack, "ra");
		if (which[0] == 'b')
			do_things(stack, stack, "rb");
		idx--;
		i++;
	}
	return (i);
}

void	push_larger(node_t **a, node_t **b, int min)
{
	int		largern;
	int		largeridx;
	node_t	*current;

	largern = 0;
	current = *b;
	while (current != NULL)
	{
		if (current->val > min)
			largern++;
		current = current->next;
	}
	if (largern == 0)
		do_things(a, b, "pa");
	while (largern-- > 0)
	{
		largeridx = find_larger_idx(b, min);
		rot_to_idx(b, "b", largeridx);
		do_things(a, b, "pa");
	}
	(*a)->split = 1;
}

void	push_smaller(node_t **a, node_t **b, int max)
{
	int		i;
	int		smallern;
	int		smalleridx;
	node_t	*current;

	i = 0;
	smallern = 0;
	current = *a;
	while (current != NULL)
	{
		if (current->val < max)
			smallern++;
		current = current->next;
	}
	if (smallern == 0)
		do_things(a, b, "pb");
	while (i < smallern)
	{
		smalleridx = find_smaller_idx(a, max);
		rot_to_idx(a, "a", smalleridx);
		do_things(a, b, "pb");
		i++;
	}
	(*b)->split = 1;
}
