/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:14:36 by aoueldma          #+#    #+#             */
/*   Updated: 2022/04/22 02:50:31 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		i += ft_putstr("(null)");
	else
	{
		while (str[i])
		{
			i += ft_putchar(str[i]);
		}
	}
	return (i);
}
