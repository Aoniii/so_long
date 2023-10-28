/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:24:53 by snourry           #+#    #+#             */
/*   Updated: 2022/06/14 20:54:28 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

static t_pos	ft_get_player_pos(t_game game);
static t_game	*ft_new_pos(t_game *game, int x, int y);

int	ft_move(int k, t_game *game)
{
	if (k == 65307)
		ft_free(game);
	else if (k == 119 || k == 97 || k == 115 || k == 100)
	{
		if (k == 119)
			game = ft_new_pos(game, -1, 0);
		else if (k == 97)
			game = ft_new_pos(game, 0, -1);
		else if (k == 115)
			game = ft_new_pos(game, 1, 0);
		else if (k == 100)
			game = ft_new_pos(game, 0, 1);
	}
	return (0);
}

static t_pos	ft_get_player_pos(t_game game)
{
	t_pos	pos;

	pos.x = -1;
	while (++pos.x < game.height)
	{
		pos.y = -1;
		while (++pos.y < game.lenght)
			if (game.map[pos.x][pos.y] == PLAYER)
				return (pos);
	}
	return (pos);
}

t_game	*ft_print_move(t_game *game)
{
	char	*itoa;
	char	*msg;
	int		height;
	int		i;

	i = -1;
	height = game->height * 32;
	game->move++;
	itoa = ft_itoa(game->move);
	msg = ft_strjoin("Move : ", itoa);
	while (++i < game->lenght)
		ft_put_texture(*game, game->texture.font, i, height / 32);
	mlx_string_put(game->mlx, game->win, 10, height + 16, 0xFFFFFF, msg);
	free(itoa);
	free(msg);
	itoa = NULL;
	msg = NULL;
	return (game);
}

static void	ft_sprite(t_game *game, t_pos pos, int x, int y)
{
	if (x == -1)
		ft_put_texture(*game, game->texture.player3, pos.y + y, pos.x + x);
	else if (y == -1)
		ft_put_texture(*game, game->texture.player2, pos.y + y, pos.x + x);
	else if (x == 1)
		ft_put_texture(*game, game->texture.player, pos.y + y, pos.x + x);
	else
		ft_put_texture(*game, game->texture.player1, pos.y + y, pos.x + x);
}

static t_game	*ft_new_pos(t_game *game, int x, int y)
{
	t_pos	pos;
	int		item;

	pos = ft_get_player_pos(*game);
	item = ft_get_item(*game);
	if (game->map[pos.x + x][pos.y + y] == ENEMY)
		ft_free(ft_print_move(game));
	else if (game->map[pos.x + x][pos.y + y] != WALL)
	{
		if (game->map[pos.x + x][pos.y + y] == EXIT)
		{
			if (item == 0)
				ft_free(ft_print_move(game));
			return (game);
		}
		game->map[pos.x + x][pos.y + y] = PLAYER;
		game->map[pos.x][pos.y] = FLOOR;
		ft_sprite(game, pos, x, y);
		ft_put_texture(*game, game->texture.floor, pos.y, pos.x);
		game = ft_print_move(game);
	}
	return (game);
}
