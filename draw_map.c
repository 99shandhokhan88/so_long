/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:17:09 by vzashev           #+#    #+#             */
/*   Updated: 2023/11/01 10:44:05 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	ft_draw_enemy(t_so_long *game)
{
	int	a;
	int	b;

	a = 0;
	while (game->map[a])
	{
		b = 0;
		while (game->map[a][b])
		{
			if (game->map[a][b] == 'N')
			{
				mlx_put_image_to_window(game->mlx, game->win, \
				game->enemy, b * 64, a * 64);
			}
			b++;
		}
		a++;
	}
}

static	void	ft_draw(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->escape, \
				j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->coin, \
				j * 64, i * 64);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, \
				j * 64, i * 64);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor, \
				j * 64, i * 64);
			j++;
		}
		i++;
	}
}

static	void	ft_draw_pne(t_so_long *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'N')
				ft_draw_enemy(game);
			else if (game->map[x][y] == 'P')
			{
				game->y = x;
				game->x = y;
				mlx_put_image_to_window(game->mlx, game->win, game->floor, \
				y * 64, x * 64);
				mlx_put_image_to_window(game->mlx, game->win, game->player, \
				y * 64, x * 64);
			}
			y++;
		}
		x++;
	}
}

void	ft_draw_map(t_so_long *game)
{
	ft_draw(game);
	ft_draw_pne(game);
}
