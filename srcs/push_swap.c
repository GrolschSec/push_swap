/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:17:30 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/25 21:41:51 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a, t_ops **ops)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		ra(a, ops, 1);
		sa(a, ops, 1);
	}
	else if (((*a)->value > (*a)->next->value
			&& (*a)->next->value < (*a)->next->next->value)
		&& (*a)->value > (*a)->next->next->value)
		ra(a, ops, 1);
	else if (((*a)->value > (*a)->next->value
			&& (*a)->next->value < (*a)->next->next->value)
		&& (*a)->value < (*a)->next->next->value)
		sa(a, ops, 1);
	else if (((*a)->value < (*a)->next->value
			&& (*a)->next->value > (*a)->next->next->value)
		&& (*a)->value < (*a)->next->next->value)
	{
		rra(a, ops, 1);
		sa(a, ops, 1);
	}
	else if (((*a)->value < (*a)->next->value
			&& (*a)->next->value > (*a)->next->next->value)
		&& (*a)->value > (*a)->next->next->value)
		rra(a, ops, 1);
}

void	cost_based_algorithm(t_stack **a, t_stack **b, t_ops **ops)
{
	push_a_to_b(a, b, ops);	
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_ops	*ops;
	int		len;

	(void)b;
	ops = NULL;
	len = stack_len(*a);
	if (len == 2 && !is_sorted(a))
		sa(a, &ops, 1);
	else if (len == 3)
		sort_three(a, &ops);
	else if (len > 3)
		cost_based_algorithm(a, b, &ops);
	print_operations(ops);
	free_operations(ops);
}