/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:00:58 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 17:25:34 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_str_check(char **s, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (s[i][j])
		{
			if (ft_isdigit(s[i][j]) == 0 && s[i][j] != '-')
				return (0);
			j++;
		}
		if (ps_atoi(s[i]) > 2147483647 || ps_atoi(s[i]) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

long	ps_atoi(const char *s)
{
	long	res;
	long	sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] && ft_isdigit(s[i]) == 1)
	{
		res *= 10;
		res += (s[i] - '0');
		i++;
	}
	return (res * sign);
}

int	input_int_check(int *val, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = i;
		while (j < n)
		{
			if (val[i] == val[j] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	if (arr_check_sort(val, n) == 1)
		return (0);
	return (1);
}

void	input_to_lst(node_t **stack, int *values, int n)
{
	int		i;
	node_t	*new_node;

	i = n - 1;
	while (i >= 0)
	{
		new_node = malloc(sizeof(node_t));
		if (new_node == NULL)
			return ;
		new_node->val = values[i];
		new_node->split = 0;
		new_node->next = *stack;
		*stack = new_node;
		i--;
	}
}
