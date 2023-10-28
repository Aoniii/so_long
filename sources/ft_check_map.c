/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:37:31 by snourry           #+#    #+#             */
/*   Updated: 2022/05/23 19:37:31 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libft/libft.h"

static int	ft_message(int player, int exit)
{
	if (player == 0)
		ft_eprint("The map doesn't contain any start boxes !");
	else if (player > 1)
		ft_eprint("The map contains too many start boxes !");
	else if (exit == 0)
		ft_eprint("The map doesn't contain any output boxes !");
	else if (exit > 1)
		ft_eprint("The map contains too many output boxes !");
	return (0);
}

static int	ft_error_and_ep(t_game game)
{
	int	i[4];

	i[0] = -1;
	i[2] = 0;
	i[3] = 0;
	while (++i[0] < game.height)
	{
		i[1] = -1;
		while (++i[1] < game.lenght)
		{
			if (game.map[i[0]][i[1]] == ERROR)
				return (ft_eprint("The map contains an wrong character !"), 0);
			else if (game.map[i[0]][i[1]] == PLAYER)
				i[2]++;
			else if (game.map[i[0]][i[1]] == EXIT)
				i[3]++;
		}
	}
	if (i[2] == 1 && i[3] == 1)
		return (1);
	return (ft_message(i[2], i[3]));
}

static int	ft_check_wall(t_game game)
{
	int	index;

	index = -1;
	while (++index < game.lenght)
		if (game.map[0][index] != WALL ||
			game.map[game.height - 1][index] != WALL)
			return (0);
	index = -1;
	while (++index < game.height)
		if (game.map[index][0] != WALL ||
			game.map[index][game.lenght - 1] != WALL)
			return (0);
	return (1);
}

int	ft_get_item(t_game game)
{
	int	item;
	int	i[2];

	item = 0;
	i[0] = -1;
	while (++i[0] < game.height)
	{
		i[1] = -1;
		while (++i[1] < game.lenght)
			if (game.map[i[0]][i[1]] == ITEM)
				item++;
	}
	return (item);
}

t_game	ft_check_map(t_game game)
{
	game.valid = 0;
	if (!ft_error_and_ep(game))
		return (game);
	if (!ft_check_wall(game))
		return (ft_eprint("The map contours are not walls !"), game);
	if (!ft_get_item(game))
		return (ft_eprint("The map doesn't contain any item !"), game);
	game.valid = 1;
	return (game);
}
