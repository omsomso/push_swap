/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:03:45 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/02 01:10:38 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_count_el(t_node **stack)
{
	int		n;
	t_node	*current;

	n = 0;
	current = *stack;
	while (current != NULL)
	{
		n++;
		current = current->next;
	}
	return (n);
}

int	lst_check_sort(t_node **stack)
{
	t_node	*current;
	int		i;

	current = *stack;
	if (current == NULL)
		return (0);
	i = 0;
	while (current->next != NULL)
	{
		if (current->val > current->next->val)
			return (0);
		i++;
		current = current->next;
	}
	return (-1);
}

void	lst_swap(t_node *head)
{
	int	tmp_val;

	if (head == NULL || head->next == NULL)
		return ;
	tmp_val = head->val;
	head->val = head->next->val;
	head->next->val = tmp_val;
}

void	lst_rotate(t_node **stack)
{
	int	tmp_val;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp_val = (*stack)->val;
	lst_del_first(stack);
	lst_add_bottom(*stack, tmp_val);
}

void	lst_rev_rotate(t_node **stack)
{
	int		tmp_val;
	t_node	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp_val = tmp->val;
	lst_del_last(*stack);
	lst_add_top(stack, tmp_val);
}
