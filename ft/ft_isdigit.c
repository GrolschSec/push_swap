/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:44:00 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/05/03 13:44:02 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*#include <ctype.h>
#include <stdio.h>

 int    main(void)
 {
     printf("%d\n", ft_isdigit('1'));
     printf("%d\n", isdigit('1'));
     return (0);
 }*/
