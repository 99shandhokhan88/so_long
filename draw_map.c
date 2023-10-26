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
				if (game->flag == 0)
					mlx_put_image_to_window(game->mlx, game->win, \
					game->enemy, b * 64, a * 64);
				game->flag = 1 - game->flag;
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
				mlx_loop_hook(game->mlx, ft_animation, game);
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

int	ft_animation(t_so_long *game)
{
	if (game->time == 1000)
	{
		game->time = 0;
		ft_draw_enemy(game);
	}
	game->time++;
	return (0);
}

void	ft_draw_map(t_so_long *game)
{
	ft_draw(game);
	ft_draw_pne(game);
}
