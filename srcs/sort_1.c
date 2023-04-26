/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:43:43 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/26 06:51:09 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a_to_b(t_stack **a, t_stack **b, t_ops **ops)
{
	pb(a, b, ops, 1);
	if (stack_len(*a) > 3 && !is_sorted(a))
		pb(a, b, ops, 1);
	if (stack_len(*a) > 3 && !is_sorted(a))
		a_to_b_until_three(a, b, ops);
	if (!is_sorted(a))
		sort_three(a, ops);
}

void	push_b_to_a(t_stack **a, t_stack **b, t_ops **ops)
{
	int		i;
	t_stack	*tmp;

	while (*b)
	{
		tmp = *b;
		i = find_best_move_b_to_a(a, b);
		while (i >= 0)
		{
			if (i == both_up_b_to_a(a, b, tmp->value))
				i = move_both_up_to_a(a, b, ops, tmp->value);
			else if (i == both_down_b_to_a(a, b, tmp->value))
				i = move_both_down_to_a(a, b, ops, tmp->value);
			else if (i == a_down_b_up_b_to_a(a, b, tmp->value))
				i = move_a_down_b_up_to_a(a, b, ops, tmp->value);
			else if (i == a_up_b_down_b_to_a(a, b, tmp->value))
				i = move_a_up_b_down_to_a(a, b, ops, tmp->value);
			else
				tmp = tmp->next;
		}
	}
}

void	a_to_b_until_three(t_stack **a, t_stack **b, t_ops **ops)
{
	int		i;
	t_stack	*tmp;

	while (stack_len(*a) > 3 && !is_sorted(a))
	{
		tmp = *a;
		i = find_best_move_a_to_b(a, b);
		while (i >= 0)
		{
			if (i == both_up_a_to_b(a, b, tmp->value))
				i = move_both_up_to_b(a, b, ops, tmp->value);
			else if (i == both_down_a_to_b(a, b, tmp->value))
				i = move_both_down_to_b(a, b, ops, tmp->value);
			else if (i == a_up_b_down_a_to_b(a, b, tmp->value))
				i = move_a_up_b_down_to_b(a, b, ops, tmp->value);
			else if (i == a_down_b_up_a_to_b(a, b, tmp->value))
				i = move_a_down_b_up_to_b(a, b, ops, tmp->value);
			else
				tmp = tmp->next;
		}
	}
}
