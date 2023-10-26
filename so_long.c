#include "so_long.h"

/*int	ft_read_map(char *argv, t_so_long *game)
{
	char	*str;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	str = malloc(sizeof(char) * 1000);
	read(fd, str, 1000);
	game->map = ft_split(str, '\n');
	if (!game->map)
		exit(0);
	while (game->map[game->rows])
	{
		game->cols = 0;
		while (game->map[game->rows][game->cols])
			game->cols++;
		game->rows++;
	}
	close(fd);
	free(str);
	return (1);
}
*/






int	ft_get_height(char *c)
{
	int	x;
	int	a;

	x = 0;
	a = 0;
	while (c[x++])
	{
		if (c[x] == '\n')
			a++;
	}
	a++;
	return (a);
}

void	ft_find_p(t_so_long *game, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (game->map[a][b] == c)
			{
				game->x = a;
				game->y = b;
				return ;
			}
			b++;
		}
		a++;
	}
	return ;
}

int	ft_read_map(char *map, t_so_long *game)
{
	int			fd1;
	char		*line;

	fd1 = open(map, O_RDONLY);
	if (fd1 == -1)
		return (0);
	line = get_next_line(fd1);
	game->rows = ft_get_height(line);
	game->map = ft_split(line, '\n');
	game->cols = (int)ft_strlen(game->map[0]);
	free (line);
	if (!game->map)
		return (0);
    ft_find_p(game, 'P');
	return (0);
}
