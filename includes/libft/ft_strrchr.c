/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:18:28 by jsantann          #+#    #+#             */
/*   Updated: 2022/08/23 20:18:32 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	temp = (char *) s;
	i = ft_strlen(temp);
	while (i >= 0)
	{
		if (temp[i] == (char)c)
		{
			return (&temp[i]);
		}
		i--;
	}
	return (NULL);
}
