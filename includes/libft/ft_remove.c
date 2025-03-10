/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:26:29 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/12 18:46:39 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remove(char *str, size_t i)
{
	size_t	new_len;
	size_t	old_len;
	size_t	count;
	char	*result;

	old_len = ft_strlen(str);
	new_len = old_len - i + 1;
	count = 0;
	result = malloc(sizeof(char *) * new_len);
	while (count < new_len)
	{
		result[count] = str[i];
		i++;
		count++;
	}
	result[count] = '\0';
	return (result);
}
