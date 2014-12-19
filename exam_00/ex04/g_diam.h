/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juschaef <juschaef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:54:25 by juschaef          #+#    #+#             */
/*   Updated: 2014/12/10 22:22:57 by juschaef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_DIAM_H
# define G_DIAM_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define BOOL int

typedef struct	s_point
{
	BOOL				check;
	int					value;
	struct	s_point		**links;
}						t_point;

#endif