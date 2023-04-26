/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:57:20 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/26 07:53:11 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		stack_a = string_case(argv);
		if (!stack_a)
			ft_error(3);
	}
	else
	{
		if (check_args(argc, argv) != 1)
			ft_error(2);
		stack_a = init_stack(argc - 1, &argv[1]);
		if (!stack_a)
			ft_error(3);
	}
	stack_b = NULL;
	if (is_sorted(&stack_a))
		return (free_stack(&stack_a), 0);
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

t_stack	*string_case(char **argv)
{
	char	**args;
	t_stack	*stack_a;
	int		len;

	args = check_string(argv[1]);
	if (!args)
		ft_error(1);
	len = tab_len(args);
	if (check_args(len, args) != 1)
	{
		free_tab(args);
		ft_error(2);
	}
	stack_a = init_stack(len, args);
	if (!stack_a)
	{
		free_tab(args);
		ft_error(3);
	}
	free_tab(args);
	return (stack_a);
}
