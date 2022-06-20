/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uphexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:42:04 by aoueldma          #+#    #+#             */
/*   Updated: 2022/04/22 03:55:09 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_uproll(unsigned int nbr, char *str)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		if (nbr % 16 > 9)
		{
			str[i++] = ft_alpha(nbr % 16) - 32;
		}
		else if (nbr % 16 <= 9)
		{
			str[i++] = (nbr % 16) + 48;
		}
		nbr /= 16;
	}
	str[i] = '\0';
	i = ft_rev(str);
	free (str);
	return (i);
}

int	ft_uphexa(unsigned int nbr)
{
	char	*str;
	int		i;
	int		r;

	i = 0;
	r = 0;
	if (nbr == 0)
	{
		ft_putnbr(0);
		return (1);
	}
	str = malloc(sizeof(char) * (ft_countnbr(nbr) + 1));
	if (!str)
		return (0);
	return (ft_uproll(nbr, str));
}	
