/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:47:34 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/05 15:49:41 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNT_ISLAND_H
# define COUNT_ISLAND_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*get_map(char *str);
char	**parsing(char *str);

#endif