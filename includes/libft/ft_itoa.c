/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 19:58:15 by jsantann          #+#    #+#             */
/*   Updated: 2022/08/15 09:20:37 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	count_elements(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		count;
	unsigned int	num;

	count = count_elements(n);
	str = (char *)malloc(count + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	str[count--] = '\0';
	if (n == 0)
		str[0] = '0';
	num = n;
	while (num > 0)
	{
		str[count--] = 48 + (num % 10);
		num = num / 10;
	}
	return (str);
}
