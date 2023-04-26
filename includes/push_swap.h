/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:04:16 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/26 02:21:40 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include "../ft/libft.h"
# include <errno.h>
# include <limits.h>
# include <math.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				w_pos;
	int				cost;
	int 			cost_a;
	int				t_cost;
	int				len_a;
	int 			len_b;
	struct s_stack	*next;
}					t_stack;

typedef struct s_ops
{
	char			*name;
	struct s_ops	*next;
}				t_ops;

/*init.c*/
t_stack	*init_stack(int argc, char **argv);
void	init_index(t_stack **stack, int *integers, int len);
void	sort_int_tab(int *integers, int len);
/*parse.c*/
int		is_within_int_range(const char *str);
int		check_double(int *nums, int actual, int size);
int		check_args(int argc, char **argv);
/*stack.c*/
void	push_integers(t_stack **stack_a, int *integers, int count);
void	create_stacks(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack, int value);
t_stack *get_last_element(t_stack **stack);
t_stack	*new_node(int value);
int		stack_len(t_stack *stack);
/*swap.c*/
void	sa(t_stack **stack_a, t_ops **ops, int b);
void	sb(t_stack **stack_b, t_ops **ops, int b);
void	ss(t_stack **stack_a, t_stack **stack_b, t_ops **ops);
/*push.c*/
void	pa(t_stack **stack_a, t_stack **stack_b, t_ops **ops, int b);
void	pb(t_stack **stack_a, t_stack **stack_b, t_ops **ops, int b);
/*rotate.c*/
void	ra(t_stack **stack_a, t_ops **ops, int b);
void	rb(t_stack **stack_b, t_ops **ops, int b);
void	rr(t_stack **stack_a, t_stack **stack_b, t_ops **ops);
/*reverse_rotate.c*/
void	rra(t_stack **stack_a, t_ops **ops, int b);
void	rrb(t_stack **stack_b, t_ops **ops, int b);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_ops **ops);
/*ops.c*/
void	print_operations(t_ops *ops);
void	add_operation(t_ops **head, char *name);
/*error.c*/
void	ft_error(int errcode);
void	print_stack(t_stack *stack);
/*free.c*/
void	free_stack(t_stack **stack);
void	free_operations(t_ops *ops);
/*push_swap.c*/
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **a, t_ops **ops);
void	cost_based_algorithm(t_stack **a, t_stack **b, t_ops **ops);
/*sort_1.c*/
void	push_a_to_b(t_stack **a, t_stack **b, t_ops **ops);
void	push_b_to_a(t_stack **a, t_stack **b, t_ops **ops);
void	a_to_b_until_three(t_stack **a, t_stack **b, t_ops **ops);
/*sort_utils.c*/
int		is_sorted(t_stack **stack);
int		find_min(t_stack **stack);
int		find_max(t_stack **stack);
int		find_index(t_stack **stack, int nb);
/*cost_1.c*/
int		find_best_move_a_to_b(t_stack **a, t_stack **b);
int		find_position_b(t_stack **stack, int nb);
int		find_position_a(t_stack **stack, int nb);
int		find_best_move_b_to_a(t_stack **a, t_stack **b);
/*cost_2.c*/
int		both_up_a_to_b(t_stack **a, t_stack **b, int nb);
int		both_down_a_to_b(t_stack **a, t_stack **b, int nb);
int		a_down_b_up_a_to_b(t_stack **a, t_stack **b, int nb);
int		a_up_b_down_a_to_b(t_stack **a, t_stack **b, int nb);
/*cost_3.c*/
int		both_up_b_to_a(t_stack **a, t_stack **b, int nb);
int		both_down_b_to_a(t_stack **a, t_stack **b, int nb);
int		a_down_b_up_b_to_a(t_stack **a, t_stack **b, int nb);
int		a_up_b_down_b_to_a(t_stack **a, t_stack **b, int nb);
/*move_1.c*/
int		move_both_up_to_b(t_stack **src, t_stack **dest, t_ops **ops, int nb);
int		move_both_down_to_b(t_stack **src, t_stack **dest, t_ops **ops, int nb);
int		move_a_down_b_up_to_b(t_stack **src, t_stack **dest, t_ops **ops, int nb);
int		move_a_up_b_down_to_b(t_stack **src, t_stack **dest, t_ops **ops, int nb);
/*move_2.c*/
int		move_both_up_to_a(t_stack **src, t_stack **dest, t_ops **ops, int nb);
int		move_both_down_to_a(t_stack **src, t_stack **dest, t_ops **ops, int nb);
int		move_a_down_b_up_to_a(t_stack **src, t_stack **dest, t_ops **ops, int nb);
int		move_a_up_b_down_to_a(t_stack **src, t_stack **dest, t_ops **ops, int nb);
#endif