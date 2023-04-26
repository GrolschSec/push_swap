/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 02:06:49 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/26 03:49:15 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	move_both_up_to_a(t_stack **src, t_stack **dest, t_ops **ops, int nb)
{
	while ((*dest)->value != nb && find_position_a(src, nb) > 0)
		rr(src, dest, ops);
	while ((*dest)->value != nb)
		rb(dest, ops, 1);
	while (find_position_a(src, nb) > 0)
		ra(src, ops, 1);
	pa(src, dest, ops, 1);
	return (-1);
}

int	move_both_down_to_a(t_stack **src, t_stack **dest, t_ops **ops, int nb)
{
	while ((*dest)->value != nb && find_position_a(src, nb) > 0)
		rrr(src, dest, ops);
	while ((*dest)->value != nb)
		rrb(dest, ops, 1);
	while (find_position_a(src, nb) > 0)
		rra(src, ops, 1);
	pa(src, dest, ops, 1);
	return (-1);
}

int	move_a_down_b_up_to_a(t_stack **src, t_stack **dest, t_ops **ops, int nb)
{
	while ((*dest)->value != nb)
		rrb(dest, ops, 1);
	while (find_position_a(src, nb) > 0)
		ra(src, ops, 1);
	pa(src, dest, ops, 1);
	return (-1);
}

int	move_a_up_b_down_to_a(t_stack **src, t_stack **dest, t_ops **ops, int nb)
{
	while ((*dest)->value != nb)
		rb(dest, ops, 1);
	while (find_position_a(src, nb) > 0)
		rra(src, ops, 1);
	pa(src, dest, ops, 1);
	return (-1);
}
