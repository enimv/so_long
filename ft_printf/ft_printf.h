/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 03:51:54 by aoueldma          #+#    #+#             */
/*   Updated: 2022/04/22 03:52:00 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putstr(char *str);
char	ft_alpha(unsigned int nbr);
int		ft_countnbr(unsigned int nbr);
int		ft_rev(char *str);
int		ft_lowhexa(unsigned int nbr);
int		ft_p(unsigned long nbr);
int		ft_putchar(char c);
int		ft_putnbr(long nbr);
int		ft_uint(unsigned int nbr);
int		ft_uphexa(unsigned int nbr);
int		ft_printf(const char *str, ...);

#endif
