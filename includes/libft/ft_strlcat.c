/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:14:08 by jsantann          #+#    #+#             */
/*   Updated: 2022/08/23 20:14:12 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	offset;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	offset = dst_len;
	if (dst_len >= dstsize)
	{
		return (src_len + dstsize);
	}
	i = 0;
	if (dstsize > dst_len)
	{
		while (src[i] && i < (dstsize - dst_len) - 1)
		{
			dst[offset + i] = src[i];
			i++;
		}
	}
	dst[offset + i] = '\0';
	return (dst_len + src_len);
}
