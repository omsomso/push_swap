/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:42:26 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 17:41:32 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_read(node_t **a, char **s, int n)
{
	int	*val;
	int	i;

	(void) a;
	i = 0;
	if (input_str_check(s, n) == 0)
		return (0);
	val = malloc(sizeof(int) * n);
	if (val == NULL)
		return (0);
	while (i < n)
	{
		val[i] = (int) ps_atoi(s[i]);
		i++;
	}
	if (input_int_check(val, n) == 0)
	{
		free(val);
		return (0);
	}
	input_to_lst(a, val, n);
	free(val);
	return (1);
}

int	push_swap(int argc, char **argv)
{
	node_t	*a;
	node_t	*b;

	a = NULL;
	b = NULL;
	if (input_read(&a, ++argv, argc - 1) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (argc - 1 <= 6)
		sort_small(&a, &b, argc - 1);
	if (argc - 1 > 6 && argc - 1 <= 120)
		sort_med(&a, &b, argc - 1);
	if (argc - 1 > 120)
		sort_big(&a, &b);
	lst_free(&a);
	lst_free(&b);
	return (0);
}
