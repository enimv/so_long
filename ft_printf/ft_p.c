/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:42:16 by aoueldma          #+#    #+#             */
/*   Updated: 2022/04/22 03:53:22 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pcountnbr(unsigned long nbr)
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

static int	ft_proll(unsigned long nbr, char *str)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		if (nbr % 16 > 9)
		{
			str[i++] = ft_alpha(nbr % 16);
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

static int	ft_plowhexa(unsigned long nbr)
{
	char	*str;

	if (nbr == 0)
	{
		ft_putnbr(0);
		return (1);
	}
	str = malloc(sizeof(*str) * (ft_pcountnbr(nbr) + 1));
	if (!str)
		return (0);
	return (ft_proll(nbr, str));
}

int	ft_p(unsigned long nbr)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_plowhexa(nbr);
	return (i);
}
