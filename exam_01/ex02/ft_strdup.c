/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 20:32:07 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/19 20:34:02 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *s)
{
	return(*s ? ft_strlen(++s) + 1 : 0);
}

char	*ft_strdup(char *s)
{
	char *ss;
	char *d;

	d = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	ss = d;
	while ((*d++ = *s++))
		;
	return (ss);
}
