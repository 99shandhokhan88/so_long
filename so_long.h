/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 01:30:03 by vzashev           #+#    #+#             */
/*   Updated: 2023/10/27 18:30:17 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./mlx_linux/mlx.h"
# include "./libft/libft.h"

typedef struct s_stats
{
	int	player;
	int	coins;
	int	enemies;
	int	escape;
}	t_stats;

typedef struct s_so_long
{
	t_stats	stats;
	char	**map;
	char	*img;
	void	*mlx;
	void	*win;
	void	*player;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*enemy;
	void	*escape;
	int		exit_count;
	int		collect_count;
	int		rows;
	int		cols;
	int		moves;
	int		x;
	int		y;
	int		flag;
	int		time;
}	t_so_long;

int		ft_move(int key, t_so_long *game);
void	ft_free_map(t_so_long *game);
int		ft_close(t_so_long *game);
void	ft_init(t_so_long *game);
void	ft_up_img(t_so_long *game);
int		ft_animation(t_so_long *game);
int		ft_check_path(t_so_long *game);
int		ft_get_height(char *c);
void	ft_draw_map(t_so_long *game);
int	ft_shape(t_so_long *game);
int	ft_walls_2(t_so_long *game);
int	ft_walls(t_so_long *game);
int	ft_elems2(t_so_long *game, int i, int j);
int	ft_elems(t_so_long *game);
void		ft_map_check2(t_so_long *game);
int		ft_is_ber(char *str);
void		ft_map_check(t_so_long *game);
int		ft_read_map(char *map, t_so_long *game);

#endif
