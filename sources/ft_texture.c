/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 05:37:27 by snourry           #+#    #+#             */
/*   Updated: 2022/05/25 05:37:27 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx-linux/mlx.h"

void	ft_put_texture(t_game game, void *texture, int x, int y)
{
	mlx_put_image_to_window(game.mlx, game.win, texture, x * 32, y * 32);
}

t_game	ft_init_texture(t_game game)
{
	t_texture	texture;
	int			width;
	int			height;

	texture.wall = mlx_xpm_file_to_image(game.mlx, \
		"assets/sprites/wall.xpm", &width, &height);
	texture.floor = mlx_xpm_file_to_image(game.mlx, \
		"assets/sprites/floor.xpm", &width, &height);
	texture.player = mlx_xpm_file_to_image(game.mlx, \
		"assets/sprites/player.xpm", &width, &height);
	texture.item = mlx_xpm_file_to_image(game.mlx, \
		"assets/sprites/item.xpm", &width, &height);
	texture.exit = mlx_xpm_file_to_image(game.mlx, \
		"assets/sprites/exit.xpm", &width, &height);
	game.texture = texture;
	return (game);
}

void	ft_place_texture(t_game game)
{
	int	height;
	int	lenght;

	height = -1;
	while (++height < game.height)
	{
		lenght = -1;
		while (++lenght < game.lenght)
		{
			if (game.map[height][lenght] == WALL)
				ft_put_texture(game, game.texture.wall, lenght, height);
			else if (game.map[height][lenght] == FLOOR)
				ft_put_texture(game, game.texture.floor, lenght, height);
			else if (game.map[height][lenght] == PLAYER)
				ft_put_texture(game, game.texture.player, lenght, height);
			else if (game.map[height][lenght] == EXIT)
				ft_put_texture(game, game.texture.exit, lenght, height);
			else if (game.map[height][lenght] == ITEM)
				ft_put_texture(game, game.texture.item, lenght, height);
		}
	}
}
