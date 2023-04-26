/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:57:20 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/26 05:43:46 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		len;

	if (argc < 2)
		ft_error(1);
	else if (argc == 2)
	{
		
		args = check_string(argv[1]);
		if (!args)
			ft_error(1);
		len = tab_len(args);
		if (check_args(len, args) != 1)
			return (free_tab(args), ft_error(2), 1);
		stack_a = init_stack(len, args);
		if (!stack_a)
			return (free_tab(args), ft_error(3), 1);
		free_tab(args);
	}
	else
	{
		if (check_args(argc, argv) != 1)
			ft_error(2);
		stack_a = init_stack(argc, argv);
		if (!stack_a)
			ft_error(3);
	}
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}

char	**check_string(char *argv)
{
	int		i;
	char	**str;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) || argv[i] == 32)
			i++;
		else
			return (NULL);
	}
	str = ft_split(argv, ' ');
	if (!str)
		return (NULL);
	return (str);
}
