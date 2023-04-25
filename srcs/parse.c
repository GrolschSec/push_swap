/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:52:49 by rlouvrie          #+#    #+#             */
/*   Updated: 2023/04/18 19:53:06 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_args(int argc, char **argv)
{
	int	*nums;
	int	i;

	nums = malloc(sizeof(int) * (argc -1));
	if (!nums)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (is_within_int_range(argv[i]) != 1)
			return (free(nums), 0);
		nums[i - 1] = ft_atoi(argv[i]);
		if (nums[i - 1] == 0 && argv[i][0] != '0')
			return (free(nums), 0);
		if (check_double(nums, nums[i - 1], i - 1) != 1)
			return (free(nums), 0);
		i++;
	}
	return (free(nums), 1);
}

int	is_within_int_range(const char *str)
{
	int			sign;
	long long	value;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	value = 0;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			value = value * 10 + (*str - '0');
		else
			return (0);
		str++;
	}
	value *= sign;
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	return (1);
}

int	check_double(int *nums, int actual, int size)
{
	int	j;

	j = 0;
	while (j != size)
	{
		if (j != size && nums[j] == actual)
			return (0);
		j++;
	}
	return (1);
}
