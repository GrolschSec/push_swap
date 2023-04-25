/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:07:14 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/24 17:08:56 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stack_a, t_ops **ops, int b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	last = *stack_a;
	while (last->next)
		last = last->next;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = NULL;
	last->next = temp;
	if (b == 1)
		add_operation(ops, "ra");
}

void	rb(t_stack **stack_b, t_ops **ops, int b)
{
	t_stack	*temp;
	t_stack	*last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	last = *stack_b;
	while (last->next)
		last = last->next;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = NULL;
	last->next = temp;
	if (b == 1)
		add_operation(ops, "rb");
}

void	rr(t_stack **stack_a, t_stack **stack_b, t_ops **ops)
{
	ra(stack_a, ops, 0);
	rb(stack_b, ops, 0);
	add_operation(ops, "rr");
}
