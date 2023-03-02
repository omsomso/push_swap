/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:29:54 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/02 01:22:30 by kpawlows         ###   ########.fr       */
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
}

int	numerology(t_node **a, t_node **b, int iter, int n2)
{
	int		val;
	int		*v;
	int		n;
	int		nice;

	n = lst_count_el(a);
	v = lst_to_arr(a, n);
	ps_sortarr(v, n);
	nice = n2 / 5 - (iter * 2);
	if (iter == 1)
		nice = n / 3 - (n % (n / 3));
	if (iter == 2)
		nice = n / 4;
	if (nice >= n || nice > 0)
		val = find_median(a) / iter + 1;
	if (val < v[0])
		val = -2147483648;
	if (n > 0 && nice > 0 && nice < n)
		val = v[nice];
	if (nice < 0)
		val = v[n / 2];
	free(v);
	return (val);
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
		i++;
	}
}
