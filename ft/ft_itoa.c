/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:21:26 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/05/11 18:06:54 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_numsize(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			size;
	char		*str;
	long int	nl;

	nl = n;
	size = ft_numsize(nl);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	if (nl < 0)
	{
		str[0] = '-';
		nl *= -1;
	}
	str[size] = '\0';
	if (nl == 0)
		str[0] = '0';
	while (nl != 0)
	{
		str[--size] = nl % 10 + '0';
		nl /= 10;
	}
	return (str);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%d", ft_numsize(0));	
}*/