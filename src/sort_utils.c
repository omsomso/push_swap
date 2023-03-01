/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:29:54 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/01 12:41:21 by kpawlows         ###   ########.fr       */
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

void	rot_to_val(t_node **stack, char *which, int val)
{
	int	i;
	int	n;
	int	idx;
	int	*v;

	i = 0;
	n = lst_count_el(stack);
	idx = 0;
	v = lst_to_arr(stack, n);
	while (i < n)
	{
		if (v[i] == val)
			idx = i;
		i++;
	}
	free(v);
	rot_to_idx(stack, which, idx);
}

void	push_larger_add(t_node **a, t_node **b, int s_idx)
{
	int	i;
	int	n;
	int	idx;
	int	lrg_n = 0;
	int	sml_n = 0;
	int	*va;
	int	*vb;
	int	val;
	t_node	*current;
	int	otv;

	current = *b;
	i = 0;
	otv = 0;
	idx = 0;
	if (*b == NULL)
		return ;
	i = 0;
	//n = lst_count_el(b);
	va = lst_to_arr(a, lst_count_el(a));
	vb = lst_to_arr(b, lst_count_el(b));
	val = vb[s_idx];
	//rotate b until val from pa is in its place
	//rotate b until val > b->val

	//find the index of b in which a is in its place
	//if val is the biggest, i need to find the biggest element of b and rot to it
	//if val is the smallest, i need to find the smalest element of b and rot to ti
	//if val is somewhere in between, nothing works and im tired

	//rot a and b and add action buffer to print ss/rr/rrr when 2 actions cancel out
	//count how many larger vals are in a
	while (i < lst_count_el(a))
	{
		if (val < va[i])
			lrg_n++;
		i++;
	}
	i = 0;
	//count how many smaller vals are in a
	while (i < lst_count_el(b))
	{
		if (val > vb[i])
			sml_n++;
		i++;
	}
	idx = lrg_n - sml_n;
	if (idx < 0)
		idx = sml_n - lrg_n;
	if (idx == lst_count_el(b))
		return ;
	/*while (current != NULL)
	{
		if (current->val > val)
			otv++;
		current = current->next;
	}*/
	/*if (otv == 0)
	{
		free(va);
		return ;
	}*/
	//current = *b;
	//vb = lst_to_arr(b, lst_count_el(b));
	rot_to_idx(a, "a", idx);
	free(va);
}

void	push_larger(t_node **a, t_node **b, int min)
{
	int		largern;
	int		largeridx;
	t_node	*current;

	largern = 0;
	current = *b;

	//calculate how many larger numbers there are
	while (current != NULL)
	{
		if (current->val > min)
			largern++;
		current = current->next;
	}
	// if there are none, just push a
	if (largern == 0)
		do_things(a, b, "pa");
	//else, find the idxs of the larger numbers and pa until there are none
	while (largern-- > 0)
	{
		largeridx = find_larger_idx(b, min);
		//push_larger_add(a, b, largeridx);
		rot_to_idx(b, "b", largeridx);
		do_things(a, b, "pa");
	}
	(*a)->split = 1;
}

int	numerology(t_node **a, t_node **b, int iter, int n2)
{
	int		val;
	int		*v;
	int		n;
	int		nice;

	n = lst_count_el(a);
	if (n != 0)
	{
		v = lst_to_arr(a, n);
		ps_sortarr(v, n);
	}
	nice = n2 / 5 - (iter * 2);
	if (iter == 1)
		nice = n / 3 - (n % (n / 3));
	//if (iter == 1)
	//	nice = 30;
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
	//printf("%d\n", nice);
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
	(*b)->split = 1;
}
