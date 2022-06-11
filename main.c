#include "so_long.h"
#include <fcntl.h>

void	ft_sizeofmap(int fd, t_map *map)
{
	char	*str;
	int	i;

	i = 0;
	map->l = 1;
	map->i = 0;
	str = get_next_line(fd);
	while (str[i] != '\0')
	{
		if (map->i == 0)
		{
			while (str[map->i] != '\n')
				map->i++;
		}
		if (str[i] == '\n')
			map->l++;
		i++;
	}

}

void	ft_mapallocation(t_map *map)
{
	int	i;

	i = 0;
	map->str = malloc(sizeof(char *) * (map->l));
	while (map->l > 0)
	{

		map->str[map->l] = malloc(sizeof(char) * map->i);
		map->l--;
	}
}

void	ft_add(t_map *map, int fd, char *str)
{
	int		i;
	char	*tmp;
	int		a;

	i = 0;
	a = 0;
	map->i = 0;
	map->l = 0;
	(void)fd;
	while (str[map->i] != '\n')
		map->i++;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			map->l++;
		i++;
	}
	//printf ("map->l === %d\n", map->l);
	tmp = malloc(sizeof(char) * map->i);
	map->str = malloc(sizeof(char *) * map->l + 1);
	while (map->l >= 0)
	{
		map->str[map->l] = malloc(sizeof(char) * map->i);
		map->l--;
	}
	map->l = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			map->str[map->l] = tmp;
			printf("%s=====\n", map->str[map->l]);
			map->l++;
			a = 0;
			i++;
		}
		tmp[a++] = str[i++];
	}
	// tmp[a] = str[i];
	//printf("hi\n");

	 printf ("map ========== %s\n", map->str[3]);
}

int	main()
{
	int		fd;
	char *p;
	t_map map;
	int	i;

	i = 0;
	fd = open ("map.txt", O_RDONLY);
	p = NULL;
	// ft_sizeofmap(fd, &map);
	// ft_mapallocation(&map);
		char	*str;
	str = get_next_line(fd);
	while (str != NULL)
	{
		p = ft_strjoin(p, str);
		free(str);
		str = get_next_line(fd);
	}
	// map.l = 0;
	// char	*str;
	// str = get_next_line(fd);
	// while (str != NULL)
	// {
	// 	map.str = ft_strjoin(p, str);
	// 	free(str);
	// 	str = get_next_line(fd);
	// 	map.l++;
	// }
	ft_add(&map, fd, p);
	//printf("%s\n", map.str[0]);
	// while (p[i] != '\0')
	// {
	// 	printf ("p[i] ======== %c\n", p[i]);
	// 	i++;
	// }
	//printf ("map->l ======== %s\n", map.str[1]);
	// printf ("L ======= %d\n", map.l);
	// printf ("I ======= %d\n", map.i);
	// printf ("%s", str);
	// str = get_next_line(fd);
	// printf ("\n----------------\n");
	// printf ("%s", str);
	
}