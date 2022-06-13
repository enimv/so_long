#include "so_long.h"

int ft_map_checker(t_map *map)
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
	if (map->l >= map->i)
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

int	ft_wall_length_check(t_map *map)
{
	int	j;
	int	x;

	j = 0;
	x = 0;
	while (map->str[j][map->i])
	{
		if (map->str[j][map->i] != '1')
		{
			ft_putstr("ERROR...MAP WALL MUST BE SURROUNDED BY 1 !!!\n");
			return (1);
		}
		if (map->str[j][map->i + 1] == '\0')
		{
			if (x > 1)
				break ;
			j = map->l - 1;
			map->i = -1;
			x++;
		}
		map->i++;
	}
	if (ft_wall_width_check(map) == 1)
		return (1);
	return (0);
}

int	ft_wall_width_check(t_map *map)
{
	map->l = 0;
	while (map->str[map->l])
	{
		if (map->str[map->l][0] != '1' || map->str[map->l][map->i] != '1')
		{
			ft_putstr("ERROR...MAP WALL MUST BE SURROUNDED BY 1 !!!\n");
			return (1);
		}
		map->l++;
	}
	return (0);
}

int	ft_player_check(t_map *map)
{
	int	x;

	map->l = 0;
	map->i = 0;
	x = 0;
	while (map->str[map->l] != NULL)
	{
		while (map->str[map->l][map->i])
		{
			if (map->str[map->l][map->i] == 'P')
				x++;
			map->i++;
		}
		map->l++;
		map->i = 0;
	}
	if (x > 1 || x == 0)
	{
		ft_putstr("ERROR...YOU MUST INSERT ONE PLYAYER STARTING POSITION !!!\n");
		return (1);
	}
	return (0);
}

int	ft_exit_check(t_map *map)
{
	int	x;

	map->l = 0;
	map->i = 0;
	x = 0;
	while (map->str[map->l] != NULL)
	{
		while (map->str[map->l][map->i])
		{
			if (map->str[map->l][map->i] == 'E')
				x++;
			map->i++;
		}
		map->l++;
		map->i = 0;
	}
	if (x > 1 || x == 0)
	{
		ft_putstr("ERROR...YOU MUST INSERT ONE MAP EXIT !!!\n");
		return (1);
	}
	return (0);
}