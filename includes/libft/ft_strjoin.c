/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:24:53 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/23 10:53:05 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_value;
	size_t	len_string1;
	size_t	len_string2;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	len_string1 = ft_strlen(s1);
	len_string2 = ft_strlen(s2);
	i = 0;
	j = 0;
	new_value = malloc((len_string1 + len_string2 + 1) * sizeof(char));
	if (!new_value)
		return (0);
	while (i < len_string1)
	{
		new_value[i] = s1[i];
		i++;
	}
	while (j < len_string2)
		new_value[i++] = s2[j++];
	new_value[i] = '\0';
	free(s1);
	return (new_value);
}
