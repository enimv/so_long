/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:51:08 by aoueldma          #+#    #+#             */
/*   Updated: 2022/04/22 02:52:33 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uint(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 0 && nbr <= 9)
		i += ft_putchar(nbr + 48);
	else if (nbr < 0)
	{
		i += ft_putchar('-');
		i += ft_uint(nbr * (-1));
	}
	else
	{
		i += ft_uint(nbr / 10);
		i += ft_uint(nbr % 10);
	}
	return (i);
}
