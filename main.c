#include "so_long.h"

int	ft_arg_check(int ac, char **av, int fd)
{
	if (ac != 2)
	{
		ft_putstr("ERROR...ARGUMMENT NOT VALID !!!\n");
		return (1);
	}
	if (ft_ber_check(av) == 1)
	{
		ft_putstr("ERRO...MAP MUST END WIHT .BER !!!\n");
		return (1);
	}
	if (fd <= 0)
	{
		ft_putstr("ERRO...MAP NOT FOUND !!!\n");
		return (1);
	}
	return (0);
}

int	ft_comp(char **av, int i)
{
	char	*str;
	int		a;

	//str = malloc(sizeof(char) * 4);
	str = "ber\0";
	a = 0;
	while (av[1][i])
	{
		if (av[1][i] != str[a])
			return (1);
		i++;
		a++;
	}
	str = NULL;
	free (str);
	return (0);
}

int	ft_ber_check(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == '.')
			break;
		if (av[1][i + 1] == '\0')
			return (1);
		i++;
	}
	if (ft_comp(av, (i + 1)) == 1)
		return (1);
	return (0);
}

char	*ft_read(int fd,char *p)
{
	char	*str;
	str = get_next_line(fd);
	if (str == NULL)
		return (NULL);
	while (str != NULL)
	{
		p = ft_strjoin(p, str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (p);
}

int	ft_sizeofmap(char *str, t_map *map)
{
	int	i;

	i = 0;
	map->l = 0;
	if (str == NULL)
		return (1);
	while (str[map->i] != '\n')
		map->i++;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			map->l++;
		i++;
	}
	map->l++;
	ft_mapallocation(map, str);
	return (0);
}

void	ft_mapallocation(t_map *map, char *str)
{
	printf (" i ==== %d\n", map->i);
	printf (" l ==== %d\n", map->l);

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
			map->str[map->l][map->i] = '\0';
			map->l++;
			map->i = 0;
			i++;
		}
		map->str[map->l][map->i++] = str[i++];
	}
	map->str[map->l][map->i] = '\0';
	map->str[++map->l] = NULL;
}
	
int	main(int ac, char **av)
{
	int		fd;
	char *p;
	t_map map;
	int	i;

	i = 0;
	fd = open (av[1], O_RDONLY);
	if (ft_arg_check(ac, av, fd) == 1)
		return (0);
	p = NULL;
	if (ft_sizeofmap(ft_read(fd, p), &map) == 1)
		return (0);
	free (p);
	if (ft_map_checker(&map) == 1)
		return (0);
	ft_mlx_win(&map);
	return (0);
}