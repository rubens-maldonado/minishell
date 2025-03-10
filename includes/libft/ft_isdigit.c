/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:20:20 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 15:09:43 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char *argv)
{
	int	i;
	int	signal;

	i = 0;
	signal = 0;
	while (argv[i])
	{
		if ((argv[i] == '-' || argv[i] == '+')
			&& argv[i] && !signal)
		{
				signal = 1;
				i++;
		}
		else if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else if (argv[i] == '.' || argv[i] == ',')
			i++;
		else if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
