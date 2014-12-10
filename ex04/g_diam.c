/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 14:48:16 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/10 22:24:58 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_diam.h"

int	ft_atoi(const char *str)
{
	int	value;

	while (*str >= '0' && *str <= '9')
	{
		value *= 10;
		value += (int)(*str - '0');
		str++;
	}
	return (value);
}


void	ft_bzero(void *b, size_t len)
{
	char *copy;

	copy = b;
	while (len)
	{
		*copy++ = 0;
		len--;
	}
}

char	**ft_strsplit(char *str, char c)
{
	int		i;
	int		j;
	char	**split;

	split = (char **)malloc(sizeof(char *) * 10000);
	i = 0;
	j = 0;
	split[i] = (char *)malloc(1000);
	while (*str)
	{
		split[i][j] = *str;
		j++;
		if (*str == c)
		{
			split[i][j] = '\0';
			i++;
			split[i] = (char *)malloc(1000);
			j = 0;
		}
		str++;
	}
	split[i + 1] = NULL;
	return (split);
}

int		*split_2(char *str)
{
	int *grid;
	char **splits;

	splits = ft_strsplit(str, '-');
	grid = (int *)malloc(sizeof(int) * 2);
	grid[0] = ft_atoi(splits[0]);
	grid[1] = ft_atoi(splits[1]);
	return (grid);
}

t_point	*create_point(int i)
{
	t_point *point;

	point = (t_point *)malloc(sizeof(t_point));
	point->value = i;
	return (point);
}

t_point	*get_or_create_point(t_point **array, int i)
{
	if (!(array[i]))
		return (create_point(i));
	return (array[i]);
}

void	create_link(t_point *p1, t_point *p2)
{
	int i;

	if (!p1->links)
	{
		p1->links = (t_point **)malloc(sizeof(t_point) * 10000);
		p1->links[0] = NULL;
	}
	i = 0;
	while (p1->links[i])
		i++;
	p1->links[i] = p2;
	p1->links[i + 1] = NULL;
}

t_point	**parsing(char *str)
{
	char	**split;
	t_point **points;
	t_point *p1;
	t_point *p2;
	int		i;

	points = (t_point **)malloc(sizeof(t_point *) * 10000);
	i = 0;
	split = ft_strsplit(str, ' ');
	while (split[i])
	{
		p1 = get_or_create_point(points, (split_2(split[i]))[0]);
		p2 = get_or_create_point(points, (split_2(split[i]))[1]);
		create_link(p1, p2);
		i++;
	}
	return (points);
}

void	g_diam(char *str)
{
	t_point **points;

	points = (t_point **)malloc(sizeof(t_point *));
	points = parsing(str);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		g_diam(argv[1]);
	write(1, "\n", 1);
	return (0);
}