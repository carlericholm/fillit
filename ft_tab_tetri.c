/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:06:43 by cholm             #+#    #+#             */
/*   Updated: 2017/12/14 15:18:26 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_new_tetri(char *tetri)
{
	char	**tab;

	tab = ft_strsplit(tetri, '\n');
	return (tab);
}

char		**ft_swap_tetri(char **new_tetri)
{
	int		i;
	char	*temp;

	i = 0;
	while (new_tetri[i] && (ft_strcmp(new_tetri[0], "....") == 0))
	{
		temp = new_tetri[i];
		new_tetri[i] = new_tetri[i + 1];
		new_tetri[i + 1] = new_tetri[i + 2];
		new_tetri[i + 2] = new_tetri[i + 3];
		new_tetri[i + 3] = temp;
	}
	return (new_tetri);
}

void		ft_cut_tetri(char **new_tetri)
{
	int		i;
	int		j;

	i = 0;
	while (new_tetri[i])
	{
		j = 0;
		new_tetri = ft_swap_tetri(new_tetri);
		while (new_tetri[i][j])
		{
			if (new_tetri[i][j] == '.' && new_tetri[i][j - 1] == '#')
			{
				new_tetri[i][j] = '\0';
				break ;
			}
			j++;
		}
		if (ft_strcmp(new_tetri[i], "....") == 0)
			ft_strdel(&new_tetri[i]);
		i++;
	}
}

char		**ft_create_tab(int i)
{
	char	**tab;
	int		size_sqrt;
	int		ligne;

	size_sqrt = 2 + i;
	ligne = 0;
	tab = (char **)malloc(sizeof(char*) * (size_sqrt + 1));
	tab[size_sqrt] = NULL;
	while (ligne < size_sqrt)
	{
		tab[ligne] = (char *)malloc(sizeof(char) * (size_sqrt + 1));
		tab[ligne][size_sqrt] = '\0';
		ft_memset(tab[ligne], '.', size_sqrt);
		ligne++;
	}
	return (tab);
}

void		ft_del_tetri_in_tab(char **tab, int x, int y, int k)
{
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == 'A' + k)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
}
