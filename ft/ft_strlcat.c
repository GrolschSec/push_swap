/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:57:06 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/05/16 21:59:10 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	ldst_copy;
	size_t	i;

	ldst = ft_strlen(dst);
	ldst_copy = ldst;
	i = 0;
	if (ldst_copy >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[i] != 0 && ldst < dstsize - 1)
	{
		dst[ldst] = src[i];
		i++;
		ldst++;
	}
	dst[ldst] = '\0';
	return (ldst_copy + ft_strlen(src));
}
