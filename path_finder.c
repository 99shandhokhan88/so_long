/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:17:28 by vzashev           #+#    #+#             */
/*   Updated: 2023/10/31 06:32:34 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_p(t_so_long *game, int x, int y, char p)
{
	if (game->map[x][y - 1] == p || game->map[x - 1][y] == p ||
	game->map[x][y + 1] == p || game->map[x + 1][y] == p)
		return (1);
	else
		return (0);
}

void	ft_change(t_so_long *game, int a, int b)
{
	if (game->map[a][b] == '0')
		game->map[a][b] = '2';
	else if (game->map[a][b] == '2')
		game->map[a][b] = '0';
	if (game->map[a][b] == 'E')
		game->map[a][b] = 'U';
	else if (game->map[a][b] == 'U')
		game->map[a][b] = 'E';
	if (game->map[a][b] == 'C')
		game->map[a][b] = 'S';
	else if (game->map[a][b] == 'S')
		game->map[a][b] = 'C';
	if (game->map[a][b] == 'N')
		game->map[a][b] = 'M';
	else if (game->map[a][b] == 'M')
		game->map[a][b] = 'N';
	return ;
}

int	ft_control_path(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if ((game->map[i][j] == '0' || game->map[i][j] == 'E' ||
			game->map[i][j] == 'C' || game->map[i][j] == 'N') && 
			(ft_check_p(game, i, j, 'P') || 
			ft_check_p(game, i, j, '2') || ft_check_p(game, i, j, 'U') || 
			ft_check_p(game, i, j, 'S') || ft_check_p(game, i, j, 'M')))
			{
				ft_change(game, i, j);
				return (ft_control_path(game));
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_scan(t_so_long *game)
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
			if (game->map[a][b] == 'C' || game->map[a][b] == 'E' || 
				game->map[a][b] == '0')
				return (0);
			b++;
		}
		a++;
	}
	return (1);
}

int	ft_check_path(t_so_long *game)
{
	int	v;
	int	z;

	v = 0;
	z = 0;
	ft_control_path(game);
	if (ft_scan(game))
	{
		while (game->map[v])
		{
			z = 0;
			while (game->map[v][z])
			{
				if (game->map[v][z] == '2' || game->map[v][z] == 'S' ||
				game->map[v][z] == 'U' || game->map[v][z] == 'M')
					ft_change(game, v, z);
				z++;
			}
			v++;
		}
		return (1);
	}
	else
		return (0);
}
