/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:28:09 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/20 07:28:14 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_map *map)
{
	ft_find_player(map);
	if (key == 126 || key == 13)
		ft_up(map);
	if (key == 125 || key == 1)
		ft_down(map);
	if (key == 124 || key == 2)
		ft_right(map);
	if (key == 123 || key == 0)
		ft_left(map);
	if (key == 53)
		ft_exit ();
	return (0);
}

void	ft_find_player(t_map *map)
{
	map->l = 0;
	map->i = 0;
	while (map->str[map->l])
	{
		while (map->str[map->l][map->i])
		{
			if (map->str[map->l][map->i] == 'P')
			{
				return ;
			}
			map->i++;
		}
		map->i = 0;
		map->l++;
	}
}

int	ft_check_obj(t_map *map)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	while (map->str[l])
	{
		while (map->str[l][i])
		{
			if (map->str[l][i] == 'C')
				return (1);
			i++;
		}
		l++;
		i = 0;
	}
	return (0);
}
