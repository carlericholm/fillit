/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 22:11:38 by kgricour          #+#    #+#             */
/*   Updated: 2017/12/14 15:12:44 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_nbr_bind(char **str, int *i, int *j, int *b)
{
	(*i >= 0 && *i < 20 && str[*j][*i + 1] == '#') ? *b += 1 : *b;
	(*i >= 0 && str[*j][*i - 1] == '#') ? *b += 1 : *b;
	(*i < 20 && str[*j][*i + 5] == '#') ? *b += 1 : *b;
	(*i >= 5 && str[*j][*i - 5] == '#') ? *b += 1 : *b;
}

int				ft_check_form(char **str)
{
	int	i;
	int	j;
	int	k;
	int	bind;

	j = 0;
	k = 0;
	if (str == NULL)
		return (0);
	while (str[j])
	{
		bind = 0;
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == '#')
				ft_nbr_bind(str, &i, &j, &bind);
			i++;
		}
		(bind == 6 || bind == 8) ? k++ : k;
		j++;
	}
	return ((k == j) ? 1 : 0);
}

static void		ft_init_var(int *i, int *j, int *k, int *l)
{
	*i = 0;
	*j = 0;
	*k = 0;
	*l = 2;
}

int				ft_check(char *s)
{
	int	i;
	int	j;
	int	k;
	int	l;

	ft_init_var(&i, &j, &k, &l);
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[0] == '\n' || (s[i] != '.' && s[i] != '#' && s[i] != '\n'))
			return (0);
		if (s[i] == '\n' && s[i + 1] == '\n' && s[i + 2] != '\n' &&
		s[i - 1] != '\n' && s[i + 2] != '\0')
			l = 0;
		if (l > 21)
			return (0);
		(s[i] == '.') ? j++ : j;
		(s[i] == '#') ? k++ : k;
		i++;
		l++;
	}
	if (((j + k) % 16) == 0 && (j % 12) == 0 && (k % 4) == 0)
		return (1);
	return (0);
}
