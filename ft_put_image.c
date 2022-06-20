/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:28:56 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/20 07:29:00 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_background(t_map *map, t_image *image)
{
	map->i = 0;
	map->l = 0;
	while (map->str[map->l])
	{
		while (map->str[map->l][map->i])
		{
			mlx_put_image_to_window (map->mlx, map->mlx_win,
				image->space, map->i * 60, map->l * 60);
			map->i++;
		}
		map->i = 0;
		map->l++;
	}
}

void	ft_mlx_image(t_map *map)
{
	t_image	image;

	ft_xpm_to_image(&image, map);
	ft_put_background(map, &image);
	map->i = 0;
	map->l = 0;
	while (map->str[map->l])
	{
		while (map->str[map->l][map->i])
		{
			ft_put_image(map, &image);
		}
		map->i = 0;
		map->l++;
	}
}

void	ft_put_image(t_map *map, t_image *image)
{
	while (map->str[map->l][map->i])
	{
		if (map->str[map->l][map->i] == '1')
			mlx_put_image_to_window (map->mlx, map->mlx_win,
				image->wall, map->i * 60, map->l * 60);
		if (map->str[map->l][map->i] == 'C')
			mlx_put_image_to_window (map->mlx, map->mlx_win,
				image->obj, map->i * 60, map->l * 60);
		if (map->str[map->l][map->i] == 'E')
			mlx_put_image_to_window (map->mlx, map->mlx_win,
				image->exit, map->i * 60, map->l * 60);
		if (map->str[map->l][map->i] == 'P')
			mlx_put_image_to_window (map->mlx, map->mlx_win,
				image->player, map->i * 60, map->l * 60);
		map->i++;
	}
}
