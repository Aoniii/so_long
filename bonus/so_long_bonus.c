/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:50:33 by snourry           #+#    #+#             */
/*   Updated: 2022/05/21 13:50:33 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_eprint("Usage: ./so_long_bonus <map>"), 0);
	game = ft_parsing(argv[1]);
	if (!game.valid)
		return (ft_free_map(game), 0);
	game = ft_check_map(game);
	if (!game.valid)
		return (ft_free_map(game), 0);
	game.mlx = mlx_init();
	game = ft_init_texture(game);
	game.win = mlx_new_window(game.mlx, game.lenght * 32, \
		game.height * 32 + 32, "So Long Bonus");
	ft_place_texture(&game);
	mlx_key_hook(game.win, ft_move, &game);
	mlx_hook(game.win, 17, 1L << 17, ft_free, &game);
	mlx_loop(game.mlx);
	return (0);
}
