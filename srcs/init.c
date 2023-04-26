/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:40:56 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/26 06:49:49 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		*integers;

	stack_a = NULL;
	integers = (int *)malloc(sizeof(int) * (argc));
	if (!integers)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		integers[i] = atoi(argv[i]);
		i++;
	}
	push_integers(&stack_a, integers, argc);
	free(integers);
	return (stack_a);
}

t_stack	*get_last_element(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
