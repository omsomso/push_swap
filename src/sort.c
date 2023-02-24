/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:18:14 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/24 06:09:49 by kpawlows         ###   ########.fr       */
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
	int	med;
	int	i;

	i = 1;
	med = find_median(a) / 4;
	if (n < 50)
	{
		i = 50;
		med = find_median(a);
	}
	while (lst_check_sort(a) == 0)
	{
		push_smaller(a, b, med);
		i++;
		if (i < 5)
		med = find_median(a) - find_median(a) / i;
		else
			med = find_median(a);
	}
	while (lst_count_el(b) > 0)
	{
		rot_to_idx(b, "b", find_largest_idx(b));
		do_things(a, b, "pa");
	}
}

void	sort_big(t_node **a, t_node **b)
{
	while (lst_check_sort(a) == 0)
		push_smaller(a, b, find_median(a));
	while (lst_count_el(b) > 0)
		push_larger(a, b, find_median(b));
	while (lst_check_sort(a) == 0)
		push_smaller(a, b, find_median(a));
	while (lst_count_el(b) > 0)
	{
		rot_to_idx(b, "b", find_largest_idx(b));
		do_things(a, b, "pa");
	}
}
