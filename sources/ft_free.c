/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:40:45 by snourry           #+#    #+#             */
/*   Updated: 2022/06/13 01:02:40 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

t_game	ft_free_map(t_game game)
{
	enum e_object	**map;
	int				index;

	map = game.map;
	if (!map)
		return (game);
	index = -1;
	while (++index < game.height)
	{
		free(map[index]);
		map[index] = NULL;
	}
	free(map);
	map = NULL;
	return (game);
}

static t_game	ft_free_texture(t_game game)
{
	mlx_destroy_image(game.mlx, game.texture.exit);
	mlx_destroy_image(game.mlx, game.texture.floor);
	mlx_destroy_image(game.mlx, game.texture.item);
	mlx_destroy_image(game.mlx, game.texture.player);
	mlx_destroy_image(game.mlx, game.texture.wall);
	return (game);
}

int	ft_free(t_game *game)
{
	*game = ft_free_texture(*game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	*game = ft_free_map(*game);
	free(game->mlx);
	game->mlx = NULL;
	game->win = NULL;
	exit(0);
}

void	ft_free_tab(char **tab, int height)
{
	int	index;

	index = -1;
	while (++index < height)
	{
		free(tab[index]);
		tab[index] = NULL;
	}
	free(tab);
	tab = NULL;
}
