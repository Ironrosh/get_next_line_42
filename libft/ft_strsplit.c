/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:20:41 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/16 18:24:19 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_wl(const char *s, char c)
{
	int		i;
	int		word_len;

	word_len = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		i++;
		word_len++;
	}
	return (word_len);
}

static int		ft_cw(const char *s, char c)
{
	int			i;
	int			words;

	words = 0;
	i = 0;
	if (s[i] != c && s[i])
	{
		i++;
		words++;
	}
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] != c && s[i])
				words++;
		}
		i++;
	}
	return (words);
}

static	char	**ft_free_dbarr(char **arr, int l)
{
	int		i;

	i = 0;
	while (i < l && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		l;
	char	**split;

	i = 0;
	l = i;
	if (!s || (!(split = (char**)malloc(sizeof(char*) * (ft_cw(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			if (!(split[l] = (char*)malloc(sizeof(char) * (ft_wl(s, c) + 1))))
				return (ft_free_dbarr(split, l));
			while (*s && *s != c)
				split[l][i++] = (char)*s++;
			split[l][i] = '\0';
			l++;
			i = 0;
		}
	}
	split[l] = NULL;
	return (split);
}
