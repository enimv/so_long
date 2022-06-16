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

void	ft_mlx_win(t_map *map)
{
	t_mlx	mlx;

	ft_get_len(map);
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, (map->i * 60), (map->l * 60), "so_long");
	ft_mlx_image(map, &mlx);
	mlx_loop(mlx.mlx);
}

void	ft_mlx_image(t_map *map, t_mlx *mlx)
{
	void	*space;
	void	*wall;
	void	*player;
	void	*exit;
	void	*obj;
	int		s;

	map->i = 0;
	map->l = 0;
	s = 60;
	space = mlx_xpm_file_to_image(mlx->mlx, "space2.xpm", &s, &s);
	wall = mlx_xpm_file_to_image(mlx->mlx, "wall.xpm", &s, &s);
	player = mlx_xpm_file_to_image(mlx->mlx, "player.xpm", &s, &s);
	obj = mlx_xpm_file_to_image(mlx->mlx, "obj.xpm", &s, &s);
	exit = mlx_xpm_file_to_image(mlx->mlx, "opendoor.xpm", &s, &s);
	while (map->str[map->l])
	{
		while (map->str[map->l][map->i])
		{
			if (map->str[map->l][map->i] == '0')
				mlx_put_image_to_window (mlx->mlx, mlx->mlx_win, space, map->i * 60, map->l * 60);
			if (map->str[map->l][map->i] == '1')
				mlx_put_image_to_window (mlx->mlx, mlx->mlx_win, wall, map->i * 60, map->l * 60);
			if (map->str[map->l][map->i] == 'C')
				mlx_put_image_to_window (mlx->mlx, mlx->mlx_win, obj, map->i * 60, map->l * 60);
			if (map->str[map->l][map->i] == 'E')
				mlx_put_image_to_window (mlx->mlx, mlx->mlx_win, exit, map->i * 60, map->l * 60);
			if (map->str[map->l][map->i] == 'P')
				mlx_put_image_to_window (mlx->mlx, mlx->mlx_win, player, map->i * 60, map->l * 60);
			map->i++;
		}
		map->i = 0;
		map->l++;
	}
}