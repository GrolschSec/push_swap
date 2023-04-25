/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:48:57 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/05/16 21:45:29 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*temps;
	char	*tempd;

	temps = (char *) src;
	tempd = (char *) dest;
	i = 0;
	while (i < n)
	{
		tempd[i] = temps[i];
		i++;
	}
	return ((void *)tempd);
}
