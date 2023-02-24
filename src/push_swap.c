/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:42:26 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/24 06:22:10 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_read(t_node **a, char **s, int n)
{
	int	*val;
	int	i;
	int	valid_int;

	(void) a;
	i = -1;
	if (input_str_check(s, n) == 0)
		return (0);
	val = malloc(sizeof(int) * n);
	if (val == NULL)
		return (0);
	while (++i < n)
		val[i] = (int) ps_atoi(s[i]);
	valid_int = input_int_check(val, n);
	if (valid_int != 0)
	{
		free(val);
		if (valid_int == 1)
			return (0);
		if (valid_int == 2)
			return (2);
	}
	input_to_lst(a, val, n);
	free(val);
	return (1);
}

int	push_swap(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		valid_input;

	a = NULL;
	b = NULL;
	valid_input = input_read(&a, ++argv, argc - 1);
	if (valid_input != 1)
	{
		if (valid_input == 0)
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
