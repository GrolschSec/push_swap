/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:12:50 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/26 00:52:38 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	move_both_up_to_b(t_stack **src, t_stack **dest, t_ops **ops, int nb)
{
	while ((*src)->value != nb && find_position_b(dest, nb) > 0)
		rr(src, dest, ops);
	while ((*src)->value != nb)
		ra(src, ops, 1);
	while (find_position_b(dest, nb) > 0)
		rb(dest, ops, 1);
	pb(src, dest, ops, 1);
	return (-1);
}

int	move_both_down_to_b(t_stack **src, t_stack **dest, t_ops **ops, int nb)
{
	while ((*src)->value != nb && find_position_b(dest, nb) > 0)
		rrr(src, dest, ops);
	while ((*src)->value != nb)
		rra(src, ops, 1);
	while (find_position_b(dest, nb) > 0)
		rrb(dest, ops, 1);
	pb(src, dest, ops, 1);
	return (-1);
}

int	move_a_down_b_up_to_b(t_stack **src, t_stack **dest, t_ops **ops, int nb)
{
	while ((*src)->value != nb)
		rra(src, ops, 1);
	while (find_position_b(dest, nb) > 0)
		rb(dest, ops, 1);
	pb(src, dest, ops, 1);
	return (-1);
}

int	move_a_up_b_down_to_b(t_stack **src, t_stack **dest, t_ops **ops, int nb)
{
	while ((*src)->value != nb)
		ra(src, ops, 1);
	while (find_position_b(dest, nb) > 0)
		rrb(dest, ops, 1);
	pb(src, dest, ops, 1);
	return (-1);
}
