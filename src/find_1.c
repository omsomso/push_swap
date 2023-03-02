/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:08:46 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/02 01:21:01 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(t_node **stack)
{
	int		val;
	int		*v;
	int		n;
	t_node	*current;

	n = 1;
	val = 0;
	current = (*stack);
	while (current->next != NULL)
	{
		n++;
		current = current->next;
	}
	v = lst_to_arr(stack, n);
	ps_sortarr(v, n);
	val = v[n / 2];
	free(v);
	return (val);
}

int	find_larger_idx(t_node **stack, int min)
{
	int	i;
	int	j;
	int	*v;

	i = 0;
	j = lst_count_el(stack) - 1;
	v = lst_to_arr(stack, lst_count_el(stack));
	while (i <= j)
	{
		if (v[i] > min)
		{
			free(v);
			return (i);
		}
		i++;
		if (v[j] > min)
		{
			free(v);
			return (j);
		}
		j--;
	}
	free(v);
	return (-1);
}

int	find_smaller_idx(t_node **stack, int max)
{
	int	i;
	int	j;
	int	*v;

	i = 0;
	j = lst_count_el(stack) - 1;
	v = lst_to_arr(stack, lst_count_el(stack));
	while (i <= j)
	{
		if (v[i] < max)
		{
			free(v);
			return (i);
		}
		i++;
		if (v[j] < max)
		{
			free(v);
			return (j);
		}
		j--;
	}
	free(v);
	return (-1);
}

int	find_largest_idx(t_node **a)
{
	int		i;
	int		idx;
	int		max;
	t_node	*current;

	if (*a == NULL)
		return (-1);
	i = 0;
	idx = 0;
	current = *a;
	max = current->val;
	while (current != NULL)
	{
		if (current->val > max)
		{
			max = current->val;
			idx = i;
		}
		i++;
		current = current->next;
	}
	return (idx);
}

int	find_smallest_idx(t_node **a)
{
	int		i;
	int		idx;
	int		min;
	t_node	*current;

	if (*a == NULL)
		return (-1);
	i = 0;
	idx = 0;
	current = *a;
	min = current->val;
	while (current != NULL)
	{
		if (current->val < min)
		{
			min = current->val;
			idx = i;
		}
		i++;
		current = current->next;
	}
	return (idx);
}
