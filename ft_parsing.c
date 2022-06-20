/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 07:36:28 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/20 07:36:31 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read(int fd, char *p)
{
	char	*str;

	str = get_next_line(fd);
	if (str == NULL)
	{
		free (str);
		ft_putstr("ERROR...MAP IS EMPTY !!!\n");
		return (NULL);
	}
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
	map->str = malloc(sizeof(char *) * map->l + 1);
	map->l --;
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
	free (str);
}
