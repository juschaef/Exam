/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   island.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:01:52 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/10 12:08:15 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

void	mark_map(char **grid, int i, int j, char mark)
{
	if (i < 0 || j < 0)
		return ;
	if (!grid[i])
		return ;
	if (grid[i][j] != 'x')
		return ;
	grid[i][j] = mark;
	mark_map(grid, i - 1, j, mark);
	mark_map(grid, i + 1, j, mark);
	mark_map(grid, i, j - 1, mark);
	mark_map(grid, i, j + 1, mark);
}

void	travel(char **grid)
{
	int		i;
	int		j;
	char	mark;

	i = 0;
	mark = '0';
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j] != '\0')
		{
			if (grid[i][j] == 'x')
			{
				mark_map(grid, i, j, mark);
				mark++;
			}
			j++;
		}
		i++;
	}
}

char	**resolve(char *str)
{
	char **grid;

	grid = parsing(str);
	travel(grid);
	return (grid);
}

int		main(int argc, char **argv)
{
	char	**grid;
	int		i;

	if (argc != 2)
		return (1);
	grid = (char **)malloc(10000);
	grid = resolve(argv[1]);
	i = 0;
	while (grid[i] != NULL)
	{
		ft_putstr(grid[i]);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
