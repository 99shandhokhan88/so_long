/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:50:04 by vzashev           #+#    #+#             */
/*   Updated: 2023/10/31 05:32:34 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_check(t_so_long *game)
{
	if (ft_shape(game) == 0)
	{
		ft_printf("Error: the map is not rectangular!\n");
		exit (1);
	}
	if (!((ft_walls(game)) && (ft_walls_2(game))))
	{
		ft_printf("Error: the ground is not surrounded by walls (1)!\n");
		exit (1);
	}
	return (0);
}

int	ft_map_check2(t_so_long *game)
{
	if (!(ft_elems(game)))
	{
		ft_printf("Error: in the map there aren't");
		ft_printf(" one player, at least one coin and one exit!\n");
		exit (1);
	}
	else
		ft_map_check(game);
	return (0);
}
