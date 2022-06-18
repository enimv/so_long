#include "so_long.h"

int	key_hook(int key, t_map *map)
{
	ft_find_player(map);
	if (key == 126)
		ft_up(map);
	if (key == 125)
		ft_down(map);
	if (key == 124)
		ft_right(map);
	if (key == 123)
		ft_left(map);
	return (0);
}

void    ft_find_player(t_map *map)
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