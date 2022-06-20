/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:39:58 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/20 07:40:02 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_checker(t_map *map)
{
	if (ft_map_shape_check(map) == 1)
		return (1);
	if (ft_char_checker(map) == 1)
		return (1);
	if (ft_wall_length_check(map) == 1)
		return (1);
	if (ft_player_check(map) == 1)
		return (1);
	if (ft_exit_check(map) == 1)
		return (1);
	return (0);
}

int	ft_map_shape_check(t_map *map)
{
	int	l;
	int	tmp;

	tmp = map->i;
	l = 0;
	if (map->l == map->i)
	{
		ft_putstr ("ERROR...MAP SHAPE MUST BE RECTANGULAR !!!\n");
		return (1);
	}
	map->i = 0;
	while (map->str[l])
	{
		while (map->str[l][map->i])
			map->i++;
		if (map->i != tmp)
		{
			ft_putstr ("ERROR...MAP SHAPE MUST BE RECTANGULAR !!!\n");
			return (1);
		}
		l++;
	}
	return (0);
}

int	ft_char_checker(t_map *map)
{
	map->i = 0;
	map->l = 0;
	while (map->str[map->l])
	{
		while (map->str[map->l][map->i])
		{
			if (map->str[map->l][map->i] != '1'
			&& map->str[map->l][map->i] != '0'
			&& map->str[map->l][map->i] != 'P'
			&& map->str[map->l][map->i] != 'E'
			&& map->str[map->l][map->i] != 'C')
			{
				ft_putstr("ERROR...UNSUPPORTED CHARACTER IN MAP !!!\n");
				return (1);
			}
			map->i++;
		}
		map->i = 0;
		map->l++;
	}
	return (0);
}
