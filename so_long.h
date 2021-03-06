/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:42:13 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/20 07:42:19 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include  <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <string.h>

typedef struct map
{
	int		l;
	char	**str;
	int		i;
	void	*mlx;
	void	*mlx_win;
	int		nmoves;
}	t_map;

typedef struct image
{
	void	*space;
	void	*wall;
	void	*player;
	void	*exit;
	void	*obj;
}	t_image;

char	*ft_read(int fd, char *p);
int		ft_sizeofmap(char *str, t_map *map);
void	ft_mapallocation(t_map *map, char *str);
void	ft_add(t_map *map, char *str);
int		ft_map_checker(t_map *map);
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
void	ft_mlx_image(t_map *map);
void	ft_xpm_to_image(t_image *image, t_map *map);
int		key_hook(int key, t_map *map);
void	ft_find_player(t_map *map);
void	ft_up(t_map *map);
void	ft_down(t_map *map);
void	ft_right(t_map *map);
void	ft_left(t_map *map);
int		ft_check_obj(t_map *map);
int		ft_exit(void);
void	ft_put_image(t_map *map, t_image *image);
#endif
