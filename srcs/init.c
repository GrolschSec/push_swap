/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:40:56 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/22 16:55:59 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		*integers;

	stack_a = NULL;
	integers = (int *)malloc(sizeof(int) * (argc - 1));
	if (!integers)
		return (NULL);
	i = 0;
	while (++i < argc)
		integers[i - 1] = atoi(argv[i]);
	push_integers(&stack_a, integers, argc - 1);
	init_index(&stack_a, integers, argc -1);
	free(integers);
	return (stack_a);
}

void	sort_int_tab(int *integers, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (integers[i] > integers[j])
			{
				temp = integers[i];
				integers[i] = integers[j];
				integers[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	init_index(t_stack **stack, int *integers, int len)
{
	int		i;
	t_stack	*node;

	if (!stack || !*stack || !integers)
		return ;
	sort_int_tab(integers, len);
	node = *stack;
	while (node != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (node->value == integers[i])
			{
				node->index = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
}
