#include "so_long.h"

/*

int ft_find_path(t_so_long *test, int x, int y)
{
    int top = 0;
    int right = 0;
    int left = 0;
    int bottom = 0;

    if (game->map[x - 1][y] == '1')
        left++;
    if (game->map[x + 1][y] == '1')
        right++;
    if (game->map[x][y - 1] == '1')
        top++;
    if (game->map[x][y + 1] == '1')
        bottom++;
    if (top + bottom + left + right == 4)
    {
        return(0);
    }
    else
    {
        return (0);
    }
    return (1);
}

int ft_iterate_map(t_so_long *game)
{
    int l;
    int k;
    int rows;
    int cols;
    int result;

    l = 1;
    rows = game->rows;
    cols = game->cols;
    result = 0;
    while (l < rows)
    {
        k = 1;
        while (k < cols)
        {
            result = ft_find_path(game, l, k);
            if (result == 0)
            {
                printf("Player is blocked at position (%d, %d)\n", l, k);
                return (0);
            }
            k++;
        }
        l++;
    }
    return (1);
}






void ft_full_fill(t_so_long *test, int x, int y)
{
    while(test->map[x][y])
    {
        if(x < 1 || x >= test->cols -1 || y < 1 || y >= test->rows -1 || test->map[x][y] == 'X' || test->map[x][y] == '1' )
            printf("cazzo\n");
        if(test->map[x][y] == '0' || test->map[x][y] == 'P')
            test->map[x][y] = 'X';
        else if(test->map[x][y] == 'C')
        {
            test->collect_count--;
            test->map[x][y] = 'X';
        }
        else if(test->map[x][y] == 'E')
        {
            test->exit_count--;
            test->map[x][y] = 'X';
        }
        ft_full_fill(test, x, y - 1);
        ft_full_fill(test, x, y + 1);
        ft_full_fill(test, x - 1, y);
        ft_full_fill(test, x + 1, y);
    }
    printf("napoli\n");
}

void ft_fill(t_so_long *test)
{
	ft_full_fill(test, test->x, test->y);
	if(test->collect_count != 0 || test->exit_count != 0)
	{
		printf("napoli\n");
	}
}

void	ft_find_p_test(t_so_long *test, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (test->map[a])
	{
		b = 0;
		while (test->map[a][b])
		{
			if (test->map[a][b] == c)
			{
				test->x = a;
				test->y = b;
				return ;
			}
			b++;
		}
		a++;
	}
	return ;
}

int	ft_read_test(char *map, t_so_long *test)
{
	int			fd1;
	char		*line;

	fd1 = open(map, O_RDONLY);
	if (fd1 == -1)
		return (0);
	line = get_next_line(fd1);
	test->rows = ft_get_height(line);
	test->map = ft_split(line, '\n');
	test->cols = (int)ft_strlen(test->map[0]);
	free (line);
	if (!test->map)
		return (0);
    ft_find_p_test(test, 'P');
    ft_fill(test);
	return (0);
}

void	ft_init_test(t_so_long *test)
{
    test->stats.player = 0;
	test->stats.escape = 0;
	test->stats.enemies = 0;
	test->stats.coins = 0;
	test->flag = 0;
	test->time = 0;
	test->moves = 0;
}

int	ft_check_path(char *map)
{
    t_so_long test;

	ft_init_test(&test);
	ft_read_test(map, &test);
    return (0);
}

*/



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