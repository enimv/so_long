#include "so_long.h"

int	key_hook(int key, t_map *map)
{
    (void)key;
    ft_find_player(map);
    if (key == 126)
        ft_up(map);
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
                //printf ("map ==== %c\n", map->str[map->l][map->i]);
                return ;
            }
            map->i++;
        }
        map->i = 0;
        map->l++;
    }
    
}

void    ft_up(t_map *map)
{
    int tmp;

    tmp = map->str[map->l][map->i];
    map->str[map->l][map->i] = map->str[map->l - 1][map->i];
    map->str[map->l - 1][map->i] = tmp;
    printf ("map =========== %c\n", map->str[map->l - 1][map->i]);
    printf ("map =========== %c\n", map->str[map->l][map->i]);
    ft_mlx_image(map);
}