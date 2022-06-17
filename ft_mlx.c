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

// int	key_hook(int key)
// {
// 	//(void)dt;
// 	printf("key is%d\n", key);
// 	return (0);
// }
void	ft_mlx_win(t_map *map)
{
	//t_mlx	mlx;
	//int		key;

	ft_get_len(map);
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, (map->i * 60), (map->l * 60), "so_long");
	ft_mlx_image(map);
	mlx_key_hook(map->mlx_win, key_hook, map);
	mlx_loop(map->mlx);
}

void ft_xpm_to_image(t_image *image, t_map *map)
{
	int	s;

	s = 60;
	image->space = mlx_xpm_file_to_image(map->mlx, "space2.xpm", &s, &s);
	image->wall = mlx_xpm_file_to_image(map->mlx, "wall.xpm", &s, &s);
	image->player = mlx_xpm_file_to_image(map->mlx, "player.xpm", &s, &s);
	image->obj = mlx_xpm_file_to_image(map->mlx, "obj.xpm", &s, &s);
	image->exit = mlx_xpm_file_to_image(map->mlx, "opendoor.xpm", &s, &s);
}

void	ft_mlx_image(t_map *map)
{
	t_image image;

	map->i = 0;
	map->l = 0;
	ft_xpm_to_image(&image, map);
	while (map->str[map->l])
	{
		while (map->str[map->l][map->i])
		{
			mlx_put_image_to_window (map->mlx, map->mlx_win, image.space, map->i * 60, map->l * 60);
			map->i++;
		}
		map->i = 0;
		map->l++;
	}
	map->i = 0;
	map->l = 0;
	while (map->str[map->l])
	{
		while (map->str[map->l][map->i])
		{
			//if (map->str[map->l][map->i] == '0')
			if (map->str[map->l][map->i] == '1')
				mlx_put_image_to_window (map->mlx, map->mlx_win, image.wall, map->i * 60, map->l * 60);
			if (map->str[map->l][map->i] == 'C')
				mlx_put_image_to_window (map->mlx, map->mlx_win, image.obj, map->i * 60, map->l * 60);
			if (map->str[map->l][map->i] == 'E')
				mlx_put_image_to_window (map->mlx, map->mlx_win, image.exit, map->i * 60, map->l * 60);
			if (map->str[map->l][map->i] == 'P')
				mlx_put_image_to_window (map->mlx, map->mlx_win, image.player, map->i * 60, map->l * 60);
			map->i++;
		}
		map->i = 0;
		map->l++;
	}
}