/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowhexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:00:50 by aoueldma          #+#    #+#             */
/*   Updated: 2022/04/22 02:35:06 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_alpha(unsigned int nbr)
{
	char	c;

	c = '\0';
	if (nbr == 10)
		c = 'a';
	else if (nbr == 11)
		c = 'b';
	else if (nbr == 12)
		c = 'c';
	else if (nbr == 13)
		c = 'd';
	else if (nbr == 14)
		c = 'e';
	else if (nbr == 15)
		c = 'f';
	return (c);
}

int	ft_countnbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
		nbr *= -1;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static int	ft_roll(unsigned int nbr, char *str)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		if (nbr % 16 > 9)
		{
			str[i++] = ft_alpha(nbr % 16);
		}
		if (nbr % 16 <= 9)
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

int	ft_lowhexa(unsigned int nbr)
{
	char	*str;

	if (nbr == 0)
	{
		ft_putnbr(0);
		return (1);
	}
	str = malloc(sizeof(char) * (ft_countnbr(nbr) + 1));
	if (!str)
		return (0);
	return (ft_roll(nbr, str));
}
