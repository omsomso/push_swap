/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:57:53 by kpawlows          #+#    #+#             */
/*   Updated: 2023/02/26 17:14:54 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_print(t_node *head)
{
	t_node	*current;

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

/*printf("%d steps\n", stepcounter());
if (lst_check_sort(&a) == -1)
{
	printf("sorted :)\n");
	printf("steps : %d\n", stepcounter());
}
lst_print(a);
lst_print(b);*/
