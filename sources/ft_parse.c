/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:29:29 by snourry           #+#    #+#             */
/*   Updated: 2022/05/21 19:29:29 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"
#include <fcntl.h>

static char	*ft_map_to_char(int fd)
{
	char	*map;
	char	*str;
	char	buffer[42];
	int		read_count;

	read_count = 1;
	map = malloc(sizeof(char));
	map[0] = 0;
	while (read_count)
	{
		read_count = read(fd, buffer, 41);
		if (read_count)
		{
			buffer[read_count] = 0;
			str = map;
			map = ft_strjoin(str, buffer);
			free(str);
			str = NULL;
		}
	}
	return (map);
}

static int	ft_get_height(char **map)
{
	int	index;

	index = 0;
	while (map[index])
		index++;
	return (index);
}

static enum e_object	ft_get_objet(char c)
{
	if (c == '1')
		return (WALL);
	if (c == '0')
		return (FLOOR);
	if (c == 'E')
		return (EXIT);
	if (c == 'C')
		return (ITEM);
	if (c == 'P')
		return (PLAYER);
	return (ERROR);
}

static enum e_object	**ft_map(char **map, t_game game)
{
	enum e_object	**object;
	int				index;
	int				i;

	index = -1;
	object = malloc(sizeof(enum e_object *) * game.height);
	while (++index < game.height)
		object[index] = malloc(sizeof(enum e_object) * game.lenght);
	index = -1;
	while (++index < game.height)
	{
		i = -1;
		while (++i < game.lenght)
			object[index][i] = ft_get_objet(map[index][i]);
		free(map[index]);
		map[index] = NULL;
	}
	free(map);
	map = NULL;
	return (object);
}

t_game	ft_parsing(char	*map_name)
{
	t_game	game;
	char	**map;
	int		fd;

	game.valid = 0;
	game.move = 0;
	game.map = NULL;
	fd = open(map_name, 0);
	if (fd == -1)
		return (ft_eprint("This file doesn't exist !"), game);
	if (!ft_is_ber(map_name))
		return (ft_eprint("The map isn't a .ber !"), game);
	map = ft_free_split(ft_map_to_char(fd), '\n');
	game.height = ft_get_height(map);
	game.lenght = ft_strlen(map[0]);
	if (game.height < 3 || !ft_check_lenght(map, game))
	{
		ft_free_tab(map, game.height);
		if (game.height < 3)
			return (ft_eprint("The map height isn't good !"), game);
		return (ft_eprint("The map lenght isn't even !"), game);
	}
	game.map = ft_map(map, game);
	close(fd);
	return (game.lenght--, game.valid = 1, game);
}
