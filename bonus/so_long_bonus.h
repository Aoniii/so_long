/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 13:49:32 by snourry           #+#    #+#             */
/*   Updated: 2022/05/21 13:49:32 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

enum e_object
{
	WALL,
	FLOOR,
	PLAYER,
	EXIT,
	ITEM,
	ERROR,
	ENEMY,
};

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_texture
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*item;
	void	*exit;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*font;
	void	*enemy;
}			t_texture;

typedef struct s_game
{
	enum e_object	**map;
	void			*mlx;
	void			*win;
	int				height;
	int				lenght;
	int				move;
	int				valid;
	t_texture		texture;
}					t_game;

/**	check **/
int		ft_is_ber(char *map);
int		ft_check_lenght(char **map, t_game game);
int		ft_get_item(t_game game);
t_game	ft_check_map(t_game game);

/**	parsing	**/
t_game	ft_parsing(char	*map_name);
char	**ft_free_split(char const *s, char c);

/**	free	**/
t_game	ft_free_map(t_game game);
int		ft_free(t_game *game);
void	ft_free_tab(char **tab, int height);

/**	print	**/
void	ft_eprint(char *s);

/**	texture	**/
void	ft_put_texture(t_game game, void *texture, int x, int y);
t_game	ft_init_texture(t_game game);
void	ft_place_texture(t_game *game);

/**	move	**/
int		ft_move(int k, t_game *game);
t_game	*ft_print_move(t_game *game);

#endif
