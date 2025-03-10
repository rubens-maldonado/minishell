/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:24:15 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/25 00:31:31 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	tmp = malloc(len);
	if (tmp)
		ft_memcpy(tmp, s1, len);
	return (tmp);
}
