/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:08:30 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/26 15:13:42 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_things(t_node **a, t_node **b, char *inst)
{
	if (inst[0] == 'p')
	{
		if (inst[1] == 'a')
			do_push(a, b);
		if (inst[1] == 'b')
			do_push(b, a);
	}
	if (inst[0] == 'r')
		do_rotate(a, b, inst);
	if (inst[0] == 's')
		do_swap(*a, *b, inst);
	ft_putendl_fd(inst, 1);
	stepcounter();
}

void	do_swap(t_node *a, t_node *b, char *inst)
{
	if (inst[1] == 'a')
		lst_swap(a);
	if (inst[1] == 'b')
		lst_swap(b);
	if (inst[1] == 's')
	{
		lst_swap(a);
		lst_swap(b);
	}
}

void	do_rotate(t_node **a, t_node **b, char *inst)
{
	if (inst[2] == '\0')
	{
		if (inst[1] == 'a')
			lst_rotate(a);
		if (inst[1] == 'b')
			lst_rotate(b);
		if (inst[1] == 'r')
		{
			lst_rotate(a);
			lst_rotate(b);
		}
	}
	else if (inst[3] == '\0')
		do_rotate_rev(a, b, inst);
}

void	do_rotate_rev(t_node **a, t_node **b, char *inst)
{
	if (inst[2] == 'a')
		lst_rev_rotate(a);
	if (inst[2] == 'b')
		lst_rev_rotate(b);
	if (inst[2] == 'r')
	{
		lst_rev_rotate(a);
		lst_rev_rotate(b);
	}
}

void	do_push(t_node **stack1, t_node **stack2)
{
	int	tmp_val;
	int	tmp_split;

	if (*stack2 == NULL)
		return ;
	tmp_val = (*stack2)->val;
	tmp_split = (*stack2)->split;
	lst_del_first(stack2);
	lst_add_top(stack1, tmp_val, tmp_split);
}
