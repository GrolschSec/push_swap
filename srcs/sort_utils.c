/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:15:32 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/26 06:11:43 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = (*stack)->value;
	tmp = *stack;
	while (tmp)
	{
		if (i > tmp->value)
			return (0);
		i = tmp->value;
		tmp = tmp->next;
	}
	return (1);
}

int	find_min(t_stack **stack)
{
	t_stack *tmp;
	int		nb;

	tmp = *stack;
	nb = tmp->value;
	while (tmp)
	{
		if (tmp->value < nb)
			nb = tmp->value;
		tmp = tmp->next;
	}
	return (nb);
}

int	find_max(t_stack **stack)
{
	t_stack *tmp;
	int		nb;

	tmp = *stack;
	nb = tmp->value;
	while (tmp)
	{
		if (tmp->value > nb)
			nb = tmp->value;
		tmp = tmp->next;
	}
	return (nb);
}

int	find_index(t_stack **stack, int nb)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp->value != nb)
	{
		i++;
		tmp = tmp->next;
	}
	tmp->position = 0;
	return (i);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
