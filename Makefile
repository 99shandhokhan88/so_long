NAME = so_long

SRCS = main.c \
      draw_map.c \
      so_long.c  \
      check_map.c \
	  path_finder.c \
      player.c

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -g

LIBFT := libft

LIBRARY := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MINILIBX := mlx_linux/

all:
	make -C $(LIBFT)
	make -C $(MINILIBX)
	$(CC) $(FLAGS) $(SRCS) $(LIBFT)/libft.a -L/$(LIBFT)  $(LIBRARY) -o $(NAME)

clean: fclean

fclean: clean
		make re -C $(MINILIBX)
		make clean -C $(LIBFT)
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re mlxlibft
