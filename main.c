/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:30:32 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/20 07:30:35 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_arg_check(int ac, char **av, int fd)
{
	if (ac != 2)
	{
		ft_putstr("ERROR...ARGUMMENT NOT VALID !!!\n");
		return (1);
	}
	if (ft_ber_check(av) == 1)
	{
		ft_putstr("ERROR...MAP MUST END WIHT .BER !!!\n");
		return (1);
	}
	if (fd <= 0)
	{
		ft_putstr("ERROR...MAP NOT FOUND !!!\n");
		return (1);
	}
	return (0);
}

int	ft_comp(char **av, int i)
{
	char	*str;
	int		a;

	str = "ber\0";
	a = 2;
	while (av[1][i] != '.')
	{
		if (av[1][i] != str[a])
			return (1);
		i--;
		a--;
	}
	str = NULL;
	free (str);
	return (0);
}

int	ft_ber_check(char **av)
{
	int	i;

	i = 0;
	while (av[1][i + 1])
		i++;
	if (ft_comp(av, i) == 1)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*p;
	t_map	map;
	int		i;

	i = 0;
	map.nmoves = 1;
	fd = open (av[1], O_RDONLY);
	if (ft_arg_check(ac, av, fd) == 1)
		return (0);
	p = NULL;
	if (ft_sizeofmap(ft_read(fd, p), &map) == 1)
		return (0);
	if (ft_map_checker(&map) == 1)
		return (0);
	ft_mlx_win(&map);
	return (0);
}
