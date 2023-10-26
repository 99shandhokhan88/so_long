/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:18:18 by vzashev           #+#    #+#             */
/*   Updated: 2023/10/27 01:20:35 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_ber(char *str)
{
	int	len;

	len = 0;
	len = ft_strlen(str);
	if (str[len - 1] == 'r' && str[len - 2] == 'e' && str[len - 3] == 'b'
		&& str[len - 4] == '.')
		return (0);
	else
	{
		ft_printf("Error: the map is not a .ber file!\n");
		exit (1);
	}
}

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
