/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:06:46 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/24 17:08:34 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, t_ops **ops, int b)
{
	t_stack	*temp;

	if (!(*stack_b))
		return ;
	temp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (b == 1)
		add_operation(ops, "pa");
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_ops **ops, int b)
{
	t_stack	*temp;

	if (!(*stack_a))
		return ;
	temp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (b == 1)
		add_operation(ops, "pb");
}
