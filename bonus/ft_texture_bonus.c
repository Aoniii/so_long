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

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	ft_put_texture(t_game game, void *texture, int x, int y)
{
	mlx_put_image_to_window(game.mlx, game.win, texture, x * 32, y * 32);
}

static void	*ft_regtex(void *mlx, char *file)
{
	int		width;
	int		height;

	return (mlx_xpm_file_to_image(mlx, file, &width, &height));
}

t_game	ft_init_texture(t_game game)
{
	t_texture	texture;

	texture.wall = ft_regtex(game.mlx, "assets/sprites/wall.xpm");
	texture.floor = ft_regtex(game.mlx, "assets/sprites/floor.xpm");
	texture.player = ft_regtex(game.mlx, "assets/sprites/player.xpm");
	texture.item = ft_regtex(game.mlx, "assets/sprites/item.xpm");
	texture.exit = ft_regtex(game.mlx, "assets/sprites/exit.xpm");
	texture.player1 = ft_regtex(game.mlx, "assets/sprites/bonus/player1.xpm");
	texture.player2 = ft_regtex(game.mlx, "assets/sprites/bonus/player2.xpm");
	texture.player3 = ft_regtex(game.mlx, "assets/sprites/bonus/player3.xpm");
	texture.font = ft_regtex(game.mlx, "assets/sprites/bonus/font.xpm");
	texture.enemy = ft_regtex(game.mlx, "assets/sprites/bonus/enemy.xpm");
	game.texture = texture;
	return (game);
}

void	ft_place_texture(t_game *game)
{
	int	height;
	int	lenght;

	height = -1;
	while (++height < game->height)
	{
		lenght = -1;
		while (++lenght < game->lenght)
		{
			if (game->map[height][lenght] == WALL)
				ft_put_texture(*game, game->texture.wall, lenght, height);
			else if (game->map[height][lenght] == FLOOR)
				ft_put_texture(*game, game->texture.floor, lenght, height);
			else if (game->map[height][lenght] == PLAYER)
				ft_put_texture(*game, game->texture.player, lenght, height);
			else if (game->map[height][lenght] == EXIT)
				ft_put_texture(*game, game->texture.exit, lenght, height);
			else if (game->map[height][lenght] == ITEM)
				ft_put_texture(*game, game->texture.item, lenght, height);
			else if (game->map[height][lenght] == ENEMY)
				ft_put_texture(*game, game->texture.enemy, lenght, height);
		}
	}
	game->move--;
	game = ft_print_move(game);
}
