/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:47:18 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/05/16 22:18:43 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	index_end(char const *s1, char const *set, size_t ib)
{
	size_t	ie;

	ie = ft_strlen(s1);
	while (ft_isset(s1[ie - 1], set) == 1 && ie > ib)
		ie--;
	return (ie);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	ib;
	size_t	ie;
	size_t	size;
	size_t	i;

	if (s1 == 0)
		return (NULL);
	ib = 0;
	while (ft_isset(s1[ib], set) == 1)
		ib++;
	ie = index_end(s1, set, ib);
	size = ie - ib;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = s1[ib];
		i++;
		ib++;
	}
	str[i] = '\0';
	return (str);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s;
	s = ft_strtrim("tripouille   xxx", " x");
	printf("%s\n", s);
	printf("%d\n", strcmp(s, "tripouille"));
	return (0);
}*/