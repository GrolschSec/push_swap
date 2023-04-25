/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlouvrie <rlouvrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 23:53:49 by rlouvrie          #+#    #+#             */
/*   Updated: 2022/05/16 22:21:05 by rlouvrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char s)
{
	if (s == c || s == 0)
		return (1);
	return (0);
}

static int	ft_count_str(const char *s, char c)
{
	int	i;
	int	strs;

	strs = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (ft_isset(c, s[i]) == 0 && ft_isset(c, s[i + 1]) == 1)
			strs++;
		i++;
	}
	return (strs);
}	

static void	ft_clean_malloc(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

static void	ft_fill_tab(char **tab, char *s, char c, int strs)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	k = 0;
	l = 0;
	while (l < strs)
	{
		while (ft_isset(c, s[i]) == 1)
			i++;
		j = 0;
		while (ft_isset(c, s[j + i]) == 0)
			j++;
		tab[l] = malloc(sizeof(char) * (j + 1));
		if (!tab[l])
			return (ft_clean_malloc(tab));
		k = 0;
		while (k < j)
			tab[l][k++] = s[i++];
		tab[l][k] = '\0';
		l++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		strs;

	if (!s)
		return (NULL);
	strs = ft_count_str(s, c);
	tab = malloc(sizeof(char *) * (strs + 1));
	if (tab == NULL)
		return (NULL);
	tab[strs] = 0;
	ft_fill_tab(tab, (char *)s, c, strs);
	return (tab);
}
