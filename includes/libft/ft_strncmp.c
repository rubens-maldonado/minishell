/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:17:34 by jsantann          #+#    #+#             */
/*   Updated: 2023/03/09 15:24:03 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*var1;
	unsigned char	*var2;

	var1 = (unsigned char *)(s1);
	var2 = (unsigned char *)(s2);
	if (n == 0)
		return (0);
	while (n > 0 && (*var1 != 0 || *var2 != 0))
	{
		if (var1[0] == '+')
			var1++;
		if (var2[0] == '+')
			var2++;
		if (*var1 != *var2)
			return (*var1 - *var2);
		var1++;
		var2++;
		n--;
	}
	return (0);
}
