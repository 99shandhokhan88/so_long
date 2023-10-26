/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:13:15 by vzashev           #+#    #+#             */
/*   Updated: 2023/10/27 01:16:55 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_so_long *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
}

int	ft_close(t_so_long *game)
{
	ft_free_map(game);
	exit(0);
}

void	ft_init(t_so_long *game)
{
	game->stats.player = 0;
	game->stats.escape = 0;
	game->stats.enemies = 0;
	game->stats.coins = 0;
	game->flag = 0;
	game->time = 0;
	game->moves = 0;
}

void	ft_up_img(t_so_long *game)
{
	int	size;

	game->player = \
	mlx_xpm_file_to_image(game->mlx, "skins/player.xpm", &size, &size);
	game->wall = \
	mlx_xpm_file_to_image(game->mlx, "skins/wall.xpm", &size, &size);
	game->floor = \
	mlx_xpm_file_to_image(game->mlx, "skins/floor.xpm", &size, &size);
	game->escape = \
	mlx_xpm_file_to_image(game->mlx, "skins/escape.xpm", &size, &size);
	game->coin = \
	mlx_xpm_file_to_image(game->mlx, "skins/coin.xpm", &size, &size);
	game->enemy = \
	mlx_xpm_file_to_image(game->mlx, "skins/enemy.xpm", &size, &size);
}

int	main(int argc, char **argv)
{
	t_so_long	game;

	if (argc != 2)
	{
		ft_printf("Error: the game requires only 2 args!\n");
		return (0);
	}
	ft_init(&game);
	ft_read_map(argv[1], &game);
	ft_is_ber(argv[1]);
	if (ft_map_check(&game) == 0)
		exit (1);
	if (!ft_check_path(&game))
	{
		printf("Error: the path of the map is not valid!\n");
		exit (1);
	}
	game.mlx = mlx_init();
	ft_up_img(&game);
	game.win = mlx_new_window(game.mlx, game.cols * 64, game.rows * 64, \
			"so_long by vzashev");
	ft_draw_map(&game);
	mlx_key_hook(game.win, ft_move, &game);
	mlx_hook(game.win, 17, 0, ft_close, &game);
	mlx_loop(game.mlx);
}
