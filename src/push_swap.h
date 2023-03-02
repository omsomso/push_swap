/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:31:59 by kpawlows          #+#    #+#             */
/*   Updated: 2023/03/02 01:23:16 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct node {
	int			val;
	struct node	*next;
}	t_node;

int		input_read(t_node **a, char **argv, int argc, char ***s);
int		input_read_add(t_node **a, int n, int *val);
void	free_everything(char ***s, t_node **a, t_node **b);
int		push_swap(int argc, char **argv);

void	sort(t_node **a, t_node **b);
void	sort_three(t_node **a, int n);
void	sort_rev_three(t_node **b, int n);
void	sort_small(t_node **a, t_node **b, int n);
void	sort_med(t_node **a, t_node **b, int n);
void	sort_big(t_node **a, t_node **b);

int		rot_to_idx(t_node **stack, char *which, int idx);
int		rot_to_idx_larger(t_node **stack, char *which, int idx);
void	push_larger(t_node **a, t_node **b, int min);
void	push_smaller(t_node **a, t_node **b, int max);
void	add_op(t_node **a, t_node **b);

int		find_median(t_node **stack);
int		find_larger_idx(t_node **stack, int min);
int		find_smaller_idx(t_node **stack, int max);
int		find_largest_idx(t_node **a);
int		find_split(t_node **stack, int nice);
int		numerology(t_node **a, t_node **b, int iter, int n2);

void	do_things(t_node **a, t_node **b, char *inst);
void	do_swap(t_node *a, t_node *b, char *inst);
void	do_rotate(t_node **a, t_node **b, char *inst);
void	do_rotate_rev(t_node **a, t_node **b, char *inst);
void	do_push(t_node **stack1, t_node **stack2);

int		input_str_check(char **s, int n);
void	input_to_lst(t_node **stack, int *values, int n);
int		input_int_check(int *val, int n);
long	ps_atoi(const char *s);
char	**dup_ptr_arr(char **s);

void	ps_sortarr(int *v, int n);
int		arr_check_sort(int *val, int n);
int		*lst_to_arr(t_node **stack, int n);

void	lst_add_top(t_node **head, int val);
void	lst_add_bottom(t_node *head, int val);
int		lst_del_first(t_node **head);
int		lst_del_last(t_node *head);
void	lst_free(t_node **lst);

int		lst_count_el(t_node **stack);
int		lst_check_sort(t_node **stack);
void	lst_swap(t_node *head);
void	lst_rotate(t_node **stack);
void	lst_rev_rotate(t_node **stack);
int		find_smallest_idx(t_node **a);

#endif