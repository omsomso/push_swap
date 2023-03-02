/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:18:14 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/02 01:19:18 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a, int n)
{
	if (n <= 1)
		return ;
	if (n == 3)
	{
		if ((*a)->val > (*a)->next->val
			&& (*a)->next->val > (*a)->next->next->val)
			do_things(a, a, "ra");
		if ((*a)->next->val > (*a)->next->next->val)
			do_things(a, a, "rra");
		if ((*a)->val > (*a)->next->next->val)
			do_things(a, a, "ra");
	}
	if ((*a)->val > (*a)->next->val)
		do_things(a, a, "sa");
}

void	sort_rev_three(t_node **b, int n)
{
	if (n <= 1)
		return ;
	if (n == 3)
	{
		if ((*b)->val < (*b)->next->val
			&& (*b)->next->val < (*b)->next->next->val)
			do_things(b, b, "rb");
		if ((*b)->next->val < (*b)->next->next->val)
			do_things(b, b, "rrb");
		if ((*b)->val < (*b)->next->next->val)
			do_things(b, b, "rb");
	}
	if ((*b)->val < (*b)->next->val)
		do_things(b, b, "sb");
}

void	sort_small(t_node **a, t_node **b, int n)
{
	if (n <= 3)
	{
		sort_three(a, n);
		return ;
	}
	push_smaller(a, b, find_median(a));
	sort_three(a, lst_count_el(a));
	sort_rev_three(b, lst_count_el(b));
	while (lst_count_el(b) > 0)
		do_things(a, b, "pa");
}

void	sort_med(t_node **a, t_node **b, int n)
{
	int	i;

	i = 1;
	while (lst_count_el(a) > n / 10)
	{
		push_smaller(a, b, numerology(a, b, i, n));
		i++;
	}
	while (lst_count_el(a) > 3)
	{
		rot_to_idx(a, "a", find_smallest_idx(a));
		do_things(a, b, "pb");
	}
	sort_three(a, 3);
	while (lst_count_el(b) > 3)
	{
		rot_to_idx(b, "b", find_largest_idx(b));
		do_things(a, b, "pa");
	}
	sort_rev_three(b, 3);
	while (lst_count_el(b) > 0)
		do_things(a, b, "pa");
}

void	sort_big(t_node **a, t_node **b)
{
	while (lst_count_el(a) > 0)
		push_smaller(a, b, find_split(a, 4));
	while (lst_count_el(b) > 0)
		push_larger(a, b, find_split(b, 8));
	while (lst_count_el(a) > 0)
		push_smaller(a, b, find_split(a, 20));
	while (lst_count_el(b) > 0)
	{
		rot_to_idx(b, "b", find_largest_idx(b));
		do_things(a, b, "pa");
	}
}
