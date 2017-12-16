/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:47:29 by cholm             #+#    #+#             */
/*   Updated: 2017/12/14 17:48:58 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_move_points(char **new_tetri, int *j, int *l, int **x)
{
	int i;

	i = 0;
	while (new_tetri[i][*j] == '.')
	{
		*j = *j + 1;
		*l = *l + 1;
		**x -= 1;
	}
}

void		ft_add_tetri_in_tab(char **new_tetri, char **tab, int *x, int *y)
{
	int i;
	int j;
	int l;

	i = 0;
	j = 0;
	l = 0;
	ft_move_points(new_tetri, &j, &l, &x);
	while (new_tetri[i])
	{
		if (i == 0)
			j = l;
		else
			j = 0;
		while (new_tetri[i][j])
		{
			while (new_tetri[i][j] == '.')
				j++;
			if (ft_isalpha(new_tetri[i][j]))
				tab[i + *y][j + *x] = new_tetri[i][j];
			j++;
		}
		i++;
	}
}

void		ft_check_points(char **new_tetri, int *s, int *t, int *x)
{
	int i;

	i = 0;
	while (new_tetri[i][*s] == '.')
	{
		*s = *s + 1;
		*t = *t + 1;
		*x -= 1;
	}
}

void		ft_point_condition(int *i, int *s, int *t)
{
	if (i == 0)
		*s = *t;
	else
		*s = 0;
}

int			ft_check_write(char **tab, char **new_tetri, int x, int y)
{
	int i;
	int s;
	int t;

	i = 0;
	s = 0;
	t = 0;
	ft_check_points(new_tetri, &s, &t, &x);
	while (new_tetri[i])
	{
		ft_point_condition(&i, &s, &t);
		while (new_tetri[i][s])
		{
			while (new_tetri[i][s] == '.')
				s++;
			if (y + i >= (int)ft_strlen(tab[0]))
				return (0);
			if (tab[y + i][x + s] != '.')
				return (0);
			s++;
		}
		i++;
	}
	return (1);
}
