/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:07:29 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/24 17:08:16 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **stack_a, t_ops **ops, int b)
{
	t_stack	*temp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (b == 1)
		add_operation(ops, "sa");
}

void	sb(t_stack **stack_b, t_ops **ops, int b)
{
	t_stack	*temp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (b == 1)
		add_operation(ops, "sb");
}

void	ss(t_stack **stack_a, t_stack **stack_b, t_ops **ops)
{
	sa(stack_a, ops, 0);
	sb(stack_b, ops, 0);
	add_operation(ops, "ss");
}