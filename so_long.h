#ifndef SO_LONG_H
# define SO_LONG_H
# include  <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./get_next_line/get_next_line.h"
typedef struct map
{
	int	l;
	char	**str;
	int	i;
}	t_map;

char	*ft_read(int fd,char *p);
void	ft_sizeofmap(char *str, t_map *map);
void	ft_mapallocation(t_map *map, char *str);
void	ft_add(t_map *map, char *str);
int ft_mapchecker(t_map *map);
#endif