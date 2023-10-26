static	int	ft_walls(t_so_long *game)
{
	int	i;
	int	j;
    int	m;

	i = 0;
	j = game->rows;
    m = 0;
	while (i < game->cols)
	{
		if (game->map[0][i] != '1')
			return (0);
		i++;
	}
	int	m = 0;
	i--;
	j--;
	while (i > 0)
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
	j = game->rows;
	while (i < game->rows)
	{
		if (game->map[i][j] != '1')
			return (0);
		j++;
	}


	printf("%d\n", i);
	printf("%d\n", j);
	/*while (--i > 0)
	{
		if (game->map[j - 1][i] != '1')
			return (0);
	}
	while (--j >= 0)
	{
		if (game->map[j][0] != '1' && game->map[j][game->cols - 1] != '1')
			return (0);
	}
	*/
	return (1);
}