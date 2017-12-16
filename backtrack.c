/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 07:14:18 by kgricour          #+#    #+#             */
/*   Updated: 2017/12/14 15:32:40 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void		ft_display_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void		ft_swap(int *i, int y, int *j, int x)
{
	*i = y;
	*j = x;
}

int			ft_scroll_tab(char **tab, char ***alltetris, int n, int i)
{
	int x;
	int j;
	int y;

	y = -1;
	if (!alltetris[n])
		return (0);
	while (y++ < (int)ft_strlen(tab[0]) && tab[y])
	{
		x = -1;
		while (x++ < (int)ft_strlen(tab[0]) && tab[y][x])
		{
			ft_swap(&i, y, &j, x);
			if (ft_check_write(tab, alltetris[n], x, y) == 1)
			{
				ft_add_tetri_in_tab(alltetris[n], tab, &x, &y);
				if (!(ft_scroll_tab(tab, alltetris, n + 1, i)))
					return (0);
				y = i;
				x = j;
				ft_del_tetri_in_tab(tab, x, y, n);
			}
		}
	}
	return (-1);
}

int			ft_resolv(char **tetri, int nbr_part)
{
	char	**tab;
	char	**new_tetri;
	int		i;
	char	***alltetris;

	i = 0;
	if (!(alltetris = (char ***)malloc(sizeof(char **) * (nbr_part + 1))))
		return (0);
	alltetris[nbr_part] = 0;
	tab = ft_create_tab(0);
	while (i < nbr_part)
	{
		new_tetri = ft_new_tetri(tetri[i]);
		ft_cut_tetri(new_tetri);
		ft_diese_to_alpha(new_tetri, i);
		alltetris[i] = new_tetri;
		i++;
	}
	i = 1;
	while (ft_scroll_tab(tab, alltetris, 0, 0))
		tab = ft_create_tab(i++);
	ft_display_tab(tab);
	return (0);
}
