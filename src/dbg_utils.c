/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:57:53 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 03:34:03 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_print(node_t *head)
{
	node_t	*current;

	current = head;
	while (current != NULL)
	{
		printf("%d\t", current->val);
		if (current->split == 1)
			printf(" | ");
		printf("\n");
		current = current->next;
	}
}

void	arr_print(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

int	stepcounter(void)
{
	static int	steps = -1;

	steps++;
	return (steps);
}

/*
if (lst_check_sort(&a) == -1)
	{
		printf("sorted :)\n");
		printf("steps : %d\n", stepcounter());
	}
	lst_print(a);
	lst_print(b);
*/