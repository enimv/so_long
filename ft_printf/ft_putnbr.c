/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:00:33 by aoueldma          #+#    #+#             */
/*   Updated: 2022/04/22 03:02:48 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(long nbr)
{
	int	i;

	i = 0;
	if (nbr >= 0 && nbr <= 9)
		i += ft_putchar(nbr + 48);
	else if (nbr < 0)
	{
		i += ft_putchar('-');
		i += ft_putnbr(nbr * -1);
	}
	else if (nbr > 9)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	return (i);
}	
