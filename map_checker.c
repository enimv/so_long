#include "so_long.h"

int ft_mapchecker(t_map *map)
{
	if (ft_charchecker(map) == 1)
		return (1);
	if (ft_wallcheck(map) == 1)
		return (1);
	if (ft_playercheck(map) == 1)
		return (1);
	if (ft_exitcheck(map) == 1)
		return (1);
	return (0);
}

int	ft_charchecker(t_map *map)
{
	map->i = 0;
	map->l = 0;
	while (map->str[map->l])
	{
		while (map->str[map->l][map->i])
		{
			printf("map->str ===== %c\n", map->str[map->l][map->i]);
			if (map->str[map->l][map->i] != '1' /*|| map->str[map->l][map->i] != '0' || map->str[map->l][map->i] != 'P' || map->str[map->l][map->i] != 'E' || map->str[map->l][map->i] != 'C'*/)
			{
				printf("wa zbiiiiii\n");
				return (1);
			}
		//	printf("map->str ===== %c\n", map->str[map->l][map->i]);
			map->i++;
		}
		printf("hooooooola\n");
		map->i = 0;
		map->l++;
	}
	printf("hooooooola\n");
	return (0);
}

int	ft_wallcheck(t_map *map)
{
	int	j;
	int	x;

	map->i = 0;
	j = 0;
	x = 0;
	while (map->str[j][map->i])
	{
		if (map->str[j][map->i] != '1')
			return (1);
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
	return (0);
}

int	ft_playercheck(t_map *map)
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
	if (x > 1)
		return (1);
	return (0);
}

int	ft_exitcheck(t_map *map)
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
	if (x > 1)
		return (1);
	return (0);
}