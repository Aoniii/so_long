/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:57:44 by snourry           #+#    #+#             */
/*   Updated: 2022/05/22 17:57:44 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"

int	ft_is_ber(char *map)
{
	int	size;

	size = ft_strlen(map);
	if (map[size - 4] == '.' && map[size - 3] == 'b' && map[size - 2] == 'e' \
		&& map[size - 1] == 'r')
		return (1);
	return (0);
}

int	ft_check_lenght(char **map, t_game game)
{
	int	index;

	index = -1;
	while (++index < game.height - 1)
		if ((int) ft_strlen(map[index]) != game.lenght)
			return (0);
	if ((int) ft_strlen(map[index]) != game.lenght - 1)
		return (0);
	return (1);
}
