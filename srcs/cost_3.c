/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:40:07 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/26 03:37:47 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	both_up_b_to_a(t_stack **a, t_stack **b, int nb)
{
	int	i;

	i = find_position_a(a, nb);
	if (i < find_index(b, nb))
		i = find_index(b, nb);
	return (i);
}

int	both_down_b_to_a(t_stack **a, t_stack **b, int nb)
{
	int	i;

	i = 0;
	if (find_position_a(a, nb))
		i = stack_len(*a) - find_position_a(a, nb);
	if ((i < (stack_len(*b) - find_index(b, nb))) && find_index(b, nb))
		i = stack_len(*b) - find_index(b, nb);
	return (i);
}

int	a_down_b_up_b_to_a(t_stack **a, t_stack **b, int nb)
{
	int	i;

	i = 0;
	if (find_position_a(a, nb))
		i = stack_len(*a) - find_position_a(a, nb);
	i += find_index(b, nb);
	return (i);
}

int	a_up_b_down_b_to_a(t_stack **a, t_stack **b, int nb)
{
	int	i;

	i = 0;
	if (find_index(b, nb))
		i = stack_len(*b) - find_index(b, nb);
	i += find_position_a(a, nb);
	return (i);
}

