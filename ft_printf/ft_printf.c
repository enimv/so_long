/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:53:19 by aoueldma          #+#    #+#             */
/*   Updated: 2022/04/22 03:00:10 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checkformat(char c, va_list arg)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'u')
		return (ft_uint(va_arg(arg, unsigned int)));
	else if (c == 'x')
		return (ft_lowhexa(va_arg(arg, unsigned long)));
	else if (c == 'p')
		return (ft_p(va_arg(arg, unsigned long)));
	else if (c == 'X')
		return (ft_uphexa(va_arg(arg, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	arg;

	i = 0;
	ret = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret = ret + checkformat(str[i + 1], arg);
			i++;
		}
		else
			ret += ft_putchar(str[i]);
		i++;
	}
	return (ret);
}
