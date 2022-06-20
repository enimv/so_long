#include "so_long.h"

void    ft_up(t_map *map)
{
	int tmp;

	if (map->str[map->l - 1][map->i] == '1')
		return ;
	if (map->str[map->l - 1][map->i] == 'E' && ft_check_obj(map) == 1)
		return ;
	else if (map->str[map->l - 1][map->i] == 'E' && ft_check_obj(map) == 0)
		{
			map->str[map->l - 1][map->i] = map->str[map->l][map->i];
			ft_mlx_image(map);
			ft_exit (map);
		}
	if (map->str[map->l - 1][map->i] == 'C')
		map->str[map->l - 1][map->i] = '0';
	tmp = map->str[map->l][map->i];
	map->str[map->l][map->i] = map->str[map->l - 1][map->i];
	map->str[map->l - 1][map->i] = tmp;
	ft_printf ("move number = %d\n", map->nmoves++);
	ft_mlx_image(map);
}

void    ft_down(t_map *map)
{
	int tmp;

	if (map->str[map->l + 1][map->i] == '1')
		return ;
	if (map->str[map->l + 1][map->i] == 'E' && ft_check_obj(map) == 1)
		return ;
	else if (map->str[map->l + 1][map->i] == 'E' && ft_check_obj(map) == 0)
		{
			map->str[map->l + 1][map->i] = map->str[map->l][map->i];
			ft_mlx_image(map);
			ft_exit (map);
		}
	if (map->str[map->l + 1][map->i] == 'C')
		map->str[map->l + 1][map->i] = '0';
	tmp = map->str[map->l][map->i];
	map->str[map->l][map->i] = map->str[map->l + 1][map->i];
	map->str[map->l + 1][map->i] = tmp;
	ft_printf ("move number = %d\n", map->nmoves++);
	ft_mlx_image(map);
}

void    ft_left(t_map *map)
{
	int tmp;

	if (map->str[map->l][map->i - 1] == '1')
		return ;
	if (map->str[map->l][map->i - 1] == 'E' && ft_check_obj(map) == 1)
		return ;
	else if (map->str[map->l][map->i - 1] == 'E' && ft_check_obj(map) == 0)
		{
			map->str[map->l][map->i - 1] = map->str[map->l][map->i];
			ft_mlx_image(map);
			ft_exit (map);
		}
	if (map->str[map->l][map->i - 1] == 'C')
		map->str[map->l][map->i - 1] = '0';
	tmp = map->str[map->l][map->i];
	map->str[map->l][map->i] = map->str[map->l][map->i - 1];
	map->str[map->l][map->i - 1] = tmp;
	ft_printf ("move number = %d\n", map->nmoves++);
	ft_mlx_image(map);
}

void    ft_right(t_map *map)
{
	int tmp;

	if (map->str[map->l][map->i + 1] == '1')
		return ;
	if (map->str[map->l][map->i + 1] == 'E' && ft_check_obj(map) == 1)
		return ;
	else if (map->str[map->l][map->i + 1] == 'E' && ft_check_obj(map) == 0)
		{
			map->str[map->l][map->i + 1] = map->str[map->l][map->i];
			ft_mlx_image(map);
			ft_exit (map);
		}
	if (map->str[map->l][map->i + 1] == 'C')
		map->str[map->l][map->i + 1] = '0';
	tmp = map->str[map->l][map->i];
	map->str[map->l][map->i] = map->str[map->l][map->i + 1];
	map->str[map->l][map->i + 1] = tmp;
	ft_printf ("move number = %d\n", map->nmoves++);
	ft_mlx_image(map);
}