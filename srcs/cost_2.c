/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:45:24 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/25 20:53:43 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	both_up_a_to_b(t_stack **a, t_stack **b, int nb)
{
	int	i;

	i = find_position_b(b, nb);
	if (i < find_index(a, nb))
		i = find_index(a, nb);
	return (i);
}

int	both_down_a_to_b(t_stack **a, t_stack **b, int nb)
{
	int	i;

	i = 0;
	if (find_position_b(b, nb))
		i = stack_len(*b) - find_position_b(b, nb);
	if ((i < (stack_len(*a) - find_index(a, nb))) && find_index(a, nb))
		i = stack_len(*a) - find_index(a, nb);
	return (i);
}

int	a_down_b_up_a_to_b(t_stack **a, t_stack **b, int nb)
{
	int	i;

	i = 0;
	if (find_index(a, nb))
		i = stack_len(*a) - find_index(a, nb);
	i += find_position_b(b, nb);
	return (i);
}

int	a_up_b_down_a_to_b(t_stack **a, t_stack **b, int nb)
{
	int	i;

	i = 0;
	if (find_position_b(b, nb))
		i = stack_len(*b) - find_position_b(b, nb);
	i += find_index(a, nb);
	return (i);
}

