/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:11:18 by vzashev           #+#    #+#             */
/*   Updated: 2023/10/31 05:24:42 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_shape(t_so_long *game)
{
	size_t	i;
	size_t	len_c;
	size_t	len_r;

	i = 0;
	len_c = game->rows;
	len_r = (int)ft_strlen(game->map[i]);
	while (i < len_c)
	{
		if (len_c == len_r)
			return (0);
		i++;
	}
	return (1);
}

int	ft_walls_2(t_so_long *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->rows)
	{
		if (game->map[j][0] != '1')
			return (0);
		j++;
	}
	i = game->cols - 1;
	j = 0;
	while (j < game->rows)
	{
		if (game->map[j][i] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	ft_walls(t_so_long *game)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	m = 0;
	while (i < game->cols)
	{
		if (game->map[0][i] != '1')
			return (0);
		i++;
	}
	j = game->rows - 1;
	i--;
	while (i >= 0)
	{
		if (game->map[j][m] != '1')
			return (0);
		m++;
		i--;
	}
	return (1);
}

int	ft_elems2(t_so_long *game, int i, int j)
{
	if (game->map[j][i] == 'C')
	{
		game->stats.coins++;
		return (0);
	}
	if (game->map[j][i] == 'E')
	{
		game->stats.escape++;
		return (0);
	}
	if (game->map[j][i] == 'N')
	{
		game->stats.enemies++;
		return (0);
	}
	if (game->map[j][i] == 'P')
	{
		game->stats.player++;
		return (0);
	}
	else
		return (1);
}

int	ft_elems(t_so_long *game)
{
	int	i;
	int	j;

	j = -1;
	while (game->map[++j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if ((ft_elems2(game, i, j)))
			{
				if (game->map[j][i] != '0' && game->map[j][i] != '1')
					return (0);
			}
			i++;
		}
	}
	if (game->stats.coins < 1 || game->stats.player != 1 
		|| game->stats.escape != 1)
		return (0);
	return (1);
}
