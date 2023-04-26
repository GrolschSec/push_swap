/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:05:39 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/26 06:49:21 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push(t_stack **stack, int value)
{
	t_stack	*node;
	t_stack	*last;

	node = new_node(value);
	if (!stack || !node)
		return ;
	if (!(*stack))
	{
		*stack = node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = node;
}

void	create_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
}

void	push_integers(t_stack **stack_a, int *integers, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		push(stack_a, integers[i]);
		i++;
	}
}

int	stack_len(t_stack *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	len = 1;
	while (stack->next)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
