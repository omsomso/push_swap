/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:18:14 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/01 12:39:47 by kpawlows         ###   ########.fr       */
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

void	sort_med2(t_node **a, t_node **b, int n)
{
	int	count = 0;

	while (count < 2)
	{
		while (lst_count_el(a) > 0)//(count < 5)////(lst_check_sort(a) == 0)
		{
			count++;
			if (lst_count_el(b) == 0)
			{
				do_things(a, b, "pb");
			}
			push_smaller(a, b, (*b)->val);
			do_things(a, b, "ra");
				//break ;
		}
		while (lst_count_el(b) > 0)
		{
			push_larger(a, b, find_median(b));
			//do_things(a, b, "pa");
		}
	}
}

int	find_split(t_node **stack, int nice)
{
	int		val;
	int		*v;
	int		n;
	//int		nice;

	n = lst_count_el(stack);
	if (n != 0)
	{
		v = lst_to_arr(stack, n);
		ps_sortarr(v, n);
	}
	//int	r = 4;
	val = v[n / nice];
	//if (val < v[0])
	//	val = -2147483648;
	//if (n > 0 && nice > 0 && nice < n)
	//	val = v[nice];
	//if (nice < 0)
		//val = v[n / 2];
	free(v);
	return (val);
}

int	find_small_split(t_node **stack, int nice)
{
	int		val;
	int		*v;
	int		n;
	static int	iter = 0;
	//int		nice;

	iter++;
	n = lst_count_el(stack);
	if (n != 0)
	{
		v = lst_to_arr(stack, n);
		ps_sortarr(v, n);
	}
	if (nice > n)
		nice = n;
	val = v[nice];
	//if (val < v[0])
	//	val = -2147483648;
	//if (n > 0 && nice > 0 && nice < n)
	//	val = v[nice];
	//if (nice < 0)
		//val = v[n / 2];
	free(v);
	return (val);
}

void	sort_med3(t_node **a, t_node **b, int n)
{
	int	split;

	while (lst_count_el(a) > 0)
		push_smaller(a, b, find_small_split(a, 10));
	/*if (lst_count_el(b) != 0)
	{
		if (lst_count_el(b) != 0)
		{
			if ()
			while ((*a)-> next)
			do_things(a, b, "pa");
		}
		
	}*/
//	while (lst_count_el(a) > 0)
//		push_smaller(a, b, find_split(a, 3));
	while (lst_count_el(b) > 0)
	{
		rot_to_idx(b, "b", find_largest_idx(b));
		do_things(a, b, "pa");
	}
}

void	sort_med(t_node **a, t_node **b, int n)
{
	int	split;
	int	i;

	i = 1;
	while (lst_count_el(a) > n / 10)
	{
		push_smaller(a, b, numerology(a, b, i, n));
		i++;
	}
		//add_op(a, b);
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
	int i = 1;
	while (lst_count_el(a) > 0)//(lst_check_sort(a) == 0)
	{
		push_smaller(a, b, find_split(a, 4));//numerology(a, b, i, 500));
		//push_smaller(a, b, find_median(a));
		i++;
	}
	while (lst_count_el(b) > 0)
		push_larger(a, b, find_split(b, 8));//find_median(b));
	while (lst_count_el(a) > 0)
		push_smaller(a, b, find_split(a, 20));
	while (lst_count_el(b) > 0)
	{
		rot_to_idx(b, "b", find_largest_idx(b));
		do_things(a, b, "pa");
	}
}
