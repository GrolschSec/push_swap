/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:56:37 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/25 21:37:24 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_best_move_a_to_b(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	tmp = *a;
	i = both_down_a_to_b(a, b, (*a)->value);
	while (tmp)
	{
		if (i > both_up_a_to_b(a, b, tmp->value))
			i = both_up_a_to_b(a, b, tmp->value);
		if (i > both_down_a_to_b(a, b, tmp->value))
			i = both_down_a_to_b(a, b, tmp->value);
		if (i > a_up_b_down_a_to_b(a, b, tmp->value))
			i = a_up_b_down_a_to_b(a, b, tmp->value);
		if (i > a_down_b_up_a_to_b(a, b, tmp->value))
			i = a_down_b_up_a_to_b(a, b, tmp->value);
		tmp = tmp->next;
	}
	return (i);
}

int	find_position_b(t_stack **stack, int nb)
{
	int		i;
	t_stack	*cursor_one;
	t_stack	*cursor_two;

	i = 1;
	cursor_one = *stack;
	if (nb > (*stack)->value && nb < get_last_element(stack)->value)
		i = 0;
	else if (nb > find_max(stack) || nb < find_min(stack))
		i = find_index(stack, find_max(stack));
	else
	{
		cursor_two = (*stack)->next;
		while (cursor_one->value < nb || cursor_two->value > nb)
		{
			cursor_one = cursor_one->next;
			cursor_two = cursor_one->next;
			i++;
		}
	}
	return (i);
}
