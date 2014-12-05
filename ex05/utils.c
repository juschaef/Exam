/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:45:28 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 15:50:53 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "count_island.h"

int		ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i] != '\0')
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*get_map(char *str)
{
	int		ret;
	char	buff[501];
	int		fd;
	char	*map;

	fd = open(str, O_RDONLY);
	map = (char *)malloc(1);
	while (ret = read(fd, buff, 500))
	{
		buff[ret] = '\0';
		map = ft_strjoin(map, buff);
	}
	close(fd);
	return (map);
}

char	**parsing(char *str)
{
	char	**grid;
	int		i;
	int		j;
	char	*map;

	j = 0;
	map = get_map(str);
	grid = (char **)malloc(1000000);
	grid[0] = (char *)malloc(1024);
	i = 0;
	while (*map)
	{
		grid[i][j] = *map;
		j++;
		if (*map == '\n')
		{
			grid[i][j] = '\0';
			i++;
			grid[i] = (char *)malloc(1024);
			j = 0;
		}
		map++;
	}
	grid[i] = NULL;
	return (grid);
}
