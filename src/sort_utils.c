/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:29:54 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/27 01:32:24 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_to_idx(t_node **stack, char *which, int idx)
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

int	rot_to_idx_larger(t_node **stack, char *which, int idx)
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

void	push_larger(t_node **a, t_node **b, int min)
{
	int		largern;
	int		largeridx;
	t_node	*current;

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

void	add_op(t_node **a, t_node **b)
{
	if((*a) != NULL && b != NULL)
	{
		if ((*a)->next != NULL && (*a)->val > (*a)->next->val)
			do_things(a, b, "sa");
		if ((*b)->next != NULL && (*b)->val < (*b)->next->val)
			do_things(a, b, "sb");
		/*if (((*a)->next != NULL && (*a)->val > (*a)->next->val) && ((*b)->next != NULL && (*b)->val < (*b)->next->val))
			do_things(a, b, "ss");*/
		/*t_node	*last_a;
		last_a = *a;
		while (last_a->next != NULL)
			last_a = last_a->next;
		if ((*a)->val > last_a->val)
			do_things(a, b, "ra");*/
	}

		//int	n = lst_count_el(a);
		/*if ((*a)->next != NULL && (*a)->val > (*a)->next->val)
			do_things(a, b, "sa");*/
		/*if (((*a)->next != NULL && (*b)->next != NULL) && ((*b)->val < (*b)->next->val) && )
			do_things(a, b, "sb");*/
}

void	push_smaller(t_node **a, t_node **b, int max)
{
	int		i;
	int		smallern;
	int		smalleridx;
	t_node	*current;

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
		//add_op(a, b);
		i++;
	}
	(*b)->split = 1;
}
