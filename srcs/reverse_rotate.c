/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:07:01 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/24 17:09:24 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stack_a, t_ops **ops, int b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (b == 1)
		add_operation(ops, "rra");
}

void	rrb(t_stack **stack_b, t_ops **ops, int b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (b == 1)
		add_operation(ops, "rrb");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_ops **ops)
{
	rra(stack_a, ops, 0);
	rrb(stack_b, ops, 0);
	add_operation(ops, "rrr");
}

