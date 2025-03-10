/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:07:28 by jsantann          #+#    #+#             */
/*   Updated: 2023/04/12 18:47:34 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == '\t' || c == ' ' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	else
		return (0);
}
