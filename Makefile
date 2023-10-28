NAME = so_long
BONUS = so_long_bonus

SRCS = sources/so_long.c \
	sources/ft_parse.c \
	sources/ft_check.c \
	sources/ft_check_map.c \
	sources/ft_free.c \
	sources/ft_print.c \
	sources/ft_texture.c \
	sources/ft_move.c \
	sources/ft_free_split.c

SRCS_BONUS = bonus/so_long_bonus.c \
	bonus/ft_parse_bonus.c \
	bonus/ft_check_bonus.c \
	bonus/ft_check_map_bonus.c \
	bonus/ft_free_bonus.c \
	bonus/ft_print_bonus.c \
	bonus/ft_texture_bonus.c \
	bonus/ft_move_bonus.c \
	bonus/ft_free_split_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes

R = \e[38;5;$(shell seq 0 255 | shuf | head -n1)m
RESET = \e[0m

define logo
	clear
	@printf "$(R)"
	@printf "   ▄████████  ▄██████▄        ▄█        ▄██████▄  ███▄▄▄▄      ▄██████▄  \n"
	@printf "  ███    ███ ███    ███      ███       ███    ███ ███▀▀▀██▄   ███    ███ \n"
	@printf "  ███    █▀  ███    ███      ███       ███    ███ ███   ███   ███    █▀  \n"
	@printf "  ███        ███    ███      ███       ███    ███ ███   ███  ▄███        \n"
	@printf "▀███████████ ███    ███      ███       ███    ███ ███   ███ ▀▀███ ████▄  \n"
	@printf "         ███ ███    ███      ███       ███    ███ ███   ███   ███    ███ \n"
	@printf "   ▄█    ███ ███    ███      ███▌    ▄ ███    ███ ███   ███   ███    ███ \n"
	@printf " ▄████████▀   ▀██████▀       █████▄▄██  ▀██████▀   ▀█   █▀    ████████▀  \n"
	@printf "                             ▀                                           $(RESET)\n"
endef

$(NAME): $(OBJS)
	@$(MAKE) -C libft/
	@$(MAKE) -C minilibx-linux/
	@gcc $(CFLAGS) $(OBJS) libft/libft.a minilibx-linux/libmlx.a -o $(NAME) -lXext -lX11
	$(call logo)

$(BONUS): $(OBJS_BONUS)
	@$(MAKE) -C libft/
	@$(MAKE) -C minilibx-linux/
	@gcc $(CFLAGS) $(OBJS_BONUS) libft/libft.a minilibx-linux/libmlx.a -o $(BONUS) -lXext -lX11
	$(call logo)

all: $(NAME)

bonus: $(BONUS)

clean:
	@rm -rf ${OBJS}
	@rm -rf ${OBJS_BONUS}
	@$(MAKE) -C libft/ clean
	@$(MAKE) -C minilibx-linux/ clean
	$(call logo)

fclean:
	@rm -rf ${OBJS}
	@rm -rf ${OBJS_BONUS}
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C minilibx-linux/ clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	$(call logo)

re: fclean all

.PHONY: re all clean fclean bonus
