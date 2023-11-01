NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = cc
OBJ = $(SRC:%.c=%.o)
SRC =	./ft_printf_utils_1.c \
		./ft_printf_utils_2.c \
		./ft_printf.c \
		./ft_strchr.c \
		./ft_strdup.c \
		./ft_strjoin.c \
		./ft_strlen.c \
		./ft_strncmp.c \
		./ft_split.c \
		./get_next_line.c \
		./ft_substr.c \
		./ft_itoa.c

%.o: %.c
	$(CC) ${FLAGS} -c $< -o $@
all : $(NAME)
$(NAME) :
	$(CC) -c $(FLAGS) -I ./ $(SRC)
	ar rcs $(NAME) $(OBJ)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all clean fclean re