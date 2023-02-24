/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:42:26 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/24 15:22:01 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_ptrptr(char ***s)
{
	int	i;

	i = -1;
	while (s[0][++i] != NULL)
		free(s[0][i]);
	if (s[0] != NULL)
		free(s[0]);
	if (s != NULL)
		free(s);
}

int	input_read(t_node **a, char **argv, int argc, char ***s)
{
	int		*val;
	int		i;
	int		n;

	n = 0;
	i = -1;
	if (argc == 1)
		s[0] = ft_split(argv[0], ' ');
	else
		s[0] = argv;
	while (s[0][n] != NULL)
		n++;
	if (input_str_check(s[0], n) == 0)
		return (0);
	val = malloc(sizeof(int) * n);
	if (val == NULL)
		return (0);
	while (++i < n)
		val[i] = (int) ps_atoi(s[0][i]);
	return (input_read_add(a, n, val));
}

int	input_read_add(t_node **a, int n, int *val)
{
	int		valid_int;

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

void	sort(t_node **a, t_node **b)
{
	int	n;

	n = lst_count_el(a);
	if (n <= 6)
		sort_small(a, b, n);
	if (n > 6 && n <= 120)
		sort_med(a, b, n);
	if (n > 120)
		sort_big(a, b);
}

int	push_swap(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		valid_input;
	char	***s;

	a = NULL;
	b = NULL;
	s = malloc(sizeof(char **));
	valid_input = input_read(&a, ++argv, argc - 1, s);
	if (valid_input != 1)
	{
		if (valid_input == 0)
			ft_putstr_fd("Error\n", 2);
		if (argc == 2)
			free_ptrptr(s);
		return (1);
	}
	sort(&a, &b);
	/*n = lst_count_el(&a);
	if (n <= 6)
		sort_small(&a, &b, n);
	if (n > 6 && n <= 120)
		sort_med(&a, &b, n);
	if (n > 120)
		sort_big(&a, &b);*/
	lst_free(&a);
	lst_free(&b);
	if (argc == 2)
		free_ptrptr(s);
	return (0);
}
