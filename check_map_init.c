/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:50:04 by vzashev           #+#    #+#             */
/*   Updated: 2023/10/27 18:29:29 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_map_check(t_so_long *game)
{
	if (ft_shape(game) == 0)
	{
		printf("Error: the map is not rectangular!\n");
		exit (1);
	}
	if (ft_walls(game) == 0)
	{
		printf("Error: the ground is not surrounded by walls (1)!\n");
		exit (1);
	}
}

void    ft_map_check2(t_so_long *game)
{
	if (ft_walls_2(game) == 0)
	{
		printf("Error: the ground is not ");
		printf("surrounded by walls (1)!\n");
		exit (1);
	}
	if (ft_elems(game) == 0)
	{
		printf("Error: in the map there aren't at");
		printf(" least one player, one coin and one exit!\n");
		exit (1);
	}
}
