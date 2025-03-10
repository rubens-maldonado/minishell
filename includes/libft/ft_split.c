/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:23:57 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/13 18:43:50 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	n_words;

	i = -1;
	n_words = 0;
	while (s[i + 1] == c)
		i++;
	while (s[++i])
	{
		if ((s[i] != c) && (i == 0 || s[i - 1] == c))
			n_words++;
		if (s[i] == '\'')
		{
			i++;
			while (s[i] && s[i] != '\'')
				i++;
		}
		if (s[i] == '\"')
		{
			i++;
			while (s[i] && s[i] != '\"')
				i++;
		}
	}
	return (n_words);
}

static	size_t	count_latter(const char *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		if (s[i] == '\"' || s[i] == '\'')
		{
			i++;
			size++;
			while (s[i] != '\"' && s[i] != '\'')
			{
				size++;
				i++;
			}
		}
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	j;
	size_t	n_words;

	i = 0;
	j = 0;
	n_words = count_words(s, c);
	ptr = ft_calloc(sizeof(char *), (n_words + 1));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0' && j < n_words)
	{
		while (s[i] == c && s[i])
			i++;
		ptr[j] = ft_substr(s, i, count_latter(s, c, i));
		i = i + count_latter(s, c, i);
		j++;
	}
	ptr[j] = NULL;
	return (ptr);
}
