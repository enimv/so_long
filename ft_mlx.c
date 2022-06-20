/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 03:10:03 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/20 03:20:01 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_len(t_map *map)
{
	map->i = 0;
	map->l = 0;
	while (map->str[map->l])
	{
		if (map->i == 0)
		{
			while (map->str[map->l][map->i])
				map->i++;
		}
		map->l++;
	}
}

int	ft_exit(void)
{
	exit (0);
}

void	ft_mlx_win(t_map *map)
{
	ft_get_len(map);
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, (map->i * 60),
			(map->l * 60), "so_long");
	ft_mlx_image(map);
	mlx_key_hook(map->mlx_win, key_hook, map);
	mlx_hook(map->mlx_win, 17, 1L << 2, ft_exit, map);
	mlx_loop(map->mlx);
}

void	ft_xpm_to_image(t_image *image, t_map *map)
{
	int	s;

	s = 60;
	image->space = mlx_xpm_file_to_image(map->mlx,
			"images/space.xpm", &s, &s);
	image->wall = mlx_xpm_file_to_image(map->mlx,
			"images/wall.xpm", &s, &s);
	image->player = mlx_xpm_file_to_image(map->mlx,
			"images/player.xpm", &s, &s);
	image->obj = mlx_xpm_file_to_image(map->mlx,
			"images/obj2.xpm", &s, &s);
	image->exit = mlx_xpm_file_to_image(map->mlx,
			"images/opendoor.xpm", &s, &s);
}
