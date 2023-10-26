#include "so_long.h"


/*
int	ft_is_ber(int argc, char *argv)
{
	int	len;

	len = 0;
    (void)argc;
	while (argv[len])
		len++;
	if (argv[len] == 'r' && argv[len - 1] == 'e' && argv[len - 2] == 'b' \
	&& argv[len - 3] == '.')
		return (1);
    ft_printf("Error: the map is not a .ber file!\n");
	exit (1);
}

*/

int	ft_is_ber(char *str)
{
    int len;

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



static	int	ft_shape(t_so_long *game)
{
	size_t	i;
	size_t  len_c;
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

static	int	ft_walls(t_so_long *game)
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

static	int	ft_elems(t_so_long *game)
{
	int	i;
	int	j;

	j = -1;
	while (game->map[++j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'P')
				game->stats.player++;
			else if (game->map[j][i] == 'C')
				game->stats.coins++;
			else if (game->map[j][i] == 'E')
				game->stats.escape++;
			else if (game->map[j][i] == 'N')
				game->stats.enemies++;
			else if (game->map[j][i] != '0' && game->map[j][i] != '1')
				return (0);
			i++;
		}
	}
	if (game->stats.coins < 1 || game->stats.player < 1 || game->stats.escape < 1)
		return (0);
	return (1);
}

int	ft_map_check(t_so_long *game)
{
	if (ft_shape(game) == 0)
	{
		printf("Error: the map is not rectangular!\n");
		return (0);
	}
	if (ft_walls(game) == 0)
	{
		printf("Error: the ground is not surrounded by walls (1)!\n");
		return (0);
	}
	if (ft_elems(game) == 0)
	{
		printf("Error: in the map there aren't at least one player, one coin and one exit!\n");
		return (0);
	}
	/*if (ft_check_path() == 0)
	//{
		printf("Error: the map doesn't have a valid path!\n");
		return (0);
	}
	*/
	else
	 return (1);
	return (0);
}