/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:08:46 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 02:28:54 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(node_t **stack)
{
	int		val;
	int		*v;
	int		n;
	node_t	*current;

	n = 1;
	val = 0;
	current = (*stack);
	while (current->next != NULL && current->next->split == 0)
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

int	find_larger_idx(node_t **stack, int min)
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

int	find_smaller_idx(node_t **stack, int max)
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

int	find_largest_idx(node_t **a)
{
	int		i;
	int		idx;
	int		max;
	node_t	*current;

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
