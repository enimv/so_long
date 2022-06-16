#ifndef SO_LONG_H
# define SO_LONG_H
# include  <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./get_next_line/get_next_line.h"
#include <fcntl.h>
#include <mlx.h>
#include <string.h>
typedef struct map
{
	int	l;
	char	**str;
	int	i;
}	t_map;

typedef struct player
{
	int	l;
	int	i;
}	t_player;

typedef struct exit
{
	int	l;
	int	i;
}	t_exit;

typedef struct mlx
{
	void *mlx;
	void *mlx_win;
}	t_mlx;
char	*ft_read(int fd,char *p);
int		ft_sizeofmap(char *str, t_map *map);
void	ft_mapallocation(t_map *map, char *str);
void	ft_add(t_map *map, char *str);
int 	ft_map_checker(t_map *map);
int		ft_putstr(char *str);
int		ft_wall_check(t_map *map);
int		ft_player_check(t_map *map);
int		ft_exit_check(t_map *map);
int		ft_char_checker(t_map *map);
int		ft_map_shape_check(t_map	*map);
int		ft_wall_width_check(t_map *map);
int		ft_wall_length_check(t_map *map);
int		ft_ber_check(char **av);
int		ft_arg_check(int ac, char **av, int fd);
void	ft_mlx_win(t_map *map);
void	ft_get_len(t_map *map);
void	ft_mlx_image(t_map *map, t_mlx *mlx);
#endif