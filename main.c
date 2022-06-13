#include "so_long.h"
#include <fcntl.h>

int		ft_ber_check(int ac, char **av)
{
	int	i;
	char	*str;
	int		a;

	i = 0;
	(void)ac;
	(void)av;
	//str = malloc(sizeof(char) * 3);
	str = "ber";
	while (av[1][i] && av[1][i] != '.')
		i++;
	while (str[a])
	return (1);
}

char	*ft_read(int fd,char *p)
{
	char	*str;
	str = get_next_line(fd);
	while (str != NULL)
	{
		p = ft_strjoin(p, str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (p);
}

void	ft_sizeofmap(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str[map->i] != '\n')
		map->i++;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			map->l++;
		i++;
	}
	ft_mapallocation(map, str);
}

void	ft_mapallocation(t_map *map, char *str)
{
	map->str = malloc(sizeof(char *) * map->l + 1);
	while (map->l >= 0)
	{
		map->str[map->l] = malloc(sizeof(char) * map->i);
		map->l--;
	}
	ft_add(map, str);
}

void	ft_add(t_map *map, char *str)
{
	int		i;

	i = 0;
	map->l = 0;
	map->i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			map->l++;
			map->i = 0;
			i++;
		}
		map->str[map->l][map->i++] = str[i++];
	}
	map->str[++map->l] = NULL;
}
	
int	main(int ac, char **av)
{
	int		fd;
	char *p;
	t_map map;
	int	i;
	if (ac != 2 )
		return (0);
	if (ft_ber_check(ac, av) == 1)
		return (0);
	i = 0;
	fd = open (av[1], O_RDONLY);
	p = NULL;
	ft_sizeofmap(ft_read(fd, p), &map);
	free (p);
	ft_map_checker(&map);

}