/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpawlows <kpawlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:31:59 by kpawlows          #+#    #+#             */
/*   Updated: 2023/01/25 17:41:20 by kpawlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct node {
	int		val;
	int		split;
	struct	node *next;
} node_t;

int	input_read(node_t **a, char **s, int n);
int	push_swap(int argc, char **argv);

void	sort_three(node_t **a, int n);
void	sort_rev_three(node_t **b, int n);
void	sort_small(node_t **a, node_t **b, int n);
void	sort_med(node_t **a, node_t **b, int n);
void	sort_big(node_t **a, node_t **b);

int	rot_to_idx(node_t **stack, char *which, int idx);
int	rot_to_idx_larger(node_t **stack, char *which, int idx);
void	push_larger(node_t **a, node_t **b, int min);
void	push_smaller(node_t **a, node_t **b, int max);

int	find_median(node_t **stack);
int	find_larger_idx(node_t **stack, int min);
int	find_smaller_idx(node_t **stack, int max);
int	find_largest_idx(node_t **a);

void	do_things(node_t **a, node_t **b, char *inst);
void	do_swap(node_t *a, node_t *b, char *inst);
void	do_rotate(node_t **a, node_t **b, char *inst);
void	do_rotate_rev(node_t **a, node_t **b, char *inst);
void	do_push(node_t **stack1, node_t **stack2);

int	input_str_check(char **s, int n);
void	input_to_lst(node_t **stack, int *values, int n);
int	input_int_check(int *val, int n);
long	ps_atoi(const char *s);

void	ps_sortarr(int *v, int n);
int	arr_check_sort(int *val, int n);
int	*lst_to_arr(node_t **stack, int n);

void	lst_add_top(node_t **head, int val, int split);
void	lst_add_bottom(node_t *head, int val, int split);
int	lst_del_first(node_t **head);
int	lst_del_last(node_t *head);
void	lst_free(node_t **lst);

int	lst_count_el(node_t **stack);
int	lst_check_sort(node_t **stack);
void	lst_swap(node_t *head);
void	lst_rotate(node_t **stack);
void	lst_rev_rotate(node_t **stack);

void	lst_print(node_t *head);
void	arr_print(int *arr, int n);
int	stepcounter();

#endif