/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:19:05 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/24 06:09:49 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sortarr(int *v, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			if (v[j] > v[j + 1])
			{
				tmp = v[j + 1];
				v[j + 1] = v[j];
				v[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	arr_check_sort(int *val, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (val[i] > val[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*lst_to_arr(t_node **stack, int n)
{
	int		i;
	int		*ret;
	t_node	*current;

	i = 0;
	current = *stack;
	if (n == 0)
		n = 1;
	ret = malloc (sizeof(int) * n);
	while (i < n && current != NULL)
	{
		ret[i] = current->val;
		i++;
		current = current->next;
	}
	return (ret);
}
