/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:20:28 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/02 01:25:55 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_split(t_node **stack, int nice)
{
	int		val;
	int		*v;
	int		n;

	n = lst_count_el(stack);
	if (n != 0)
	{
		v = lst_to_arr(stack, n);
		ps_sortarr(v, n);
	}
	val = v[n / nice];
	free(v);
	return (val);
}
