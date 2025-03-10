/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:28:39 by jsantann          #+#    #+#             */
/*   Updated: 2022/08/18 02:28:41 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*var1;
	unsigned char	*var2;

	var1 = (unsigned char *)(s1);
	var2 = (unsigned char *)(s2);
	if (n == 0)
	{
		return (0);
	}
	while (n != 0)
	{
		if (*var1 != *var2)
		{
			return (*var1 - *var2);
		}
		var1++;
		var2++;
		n--;
	}
	return (0);
}
