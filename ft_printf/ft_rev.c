/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 02:28:26 by aoueldma          #+#    #+#             */
/*   Updated: 2022/04/22 03:41:48 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_rev(char *str)
{
	int		i;
	int		r;
	char	*ret;

	r = 0;
	ret = malloc(sizeof(char) * ft_strlen(str) + 1);
	i = ft_strlen(str);
	i--;
	while (i >= 0)
	{
		ret[r++] = str[i--];
	}
	ret[r] = '\0';
	ft_putstr(ret);
	free(ret);
	return (r);
}
