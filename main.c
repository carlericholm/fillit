/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:06:01 by kgricour          #+#    #+#             */
/*   Updated: 2017/12/14 20:23:27 by kgricour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int		ft_nbr_parts(char *str)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (str[i++])
		if ((str[i] == '\n' && str[i - 1] != '\n') && (str[i + 1] == '\n'
		|| str[i + 1] == '\0'))
			j++;
	if (i > 20)
		return (j);
	else
		return (0);
}

static char		**ft_create_the_tab(char *str)
{
	int			i;
	int			j;
	char		**tetri;

	i = 0;
	j = 0;
	j = ft_nbr_parts(str);
	if (str == NULL || (str[0] != '.' && str[0] != '#') || j < 1)
		return (NULL);
	i = 0;
	tetri = (char **)malloc(sizeof(char *) * (j + 1));
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			tetri[j] = ft_strsub(str, i - 19, 19);
			j++;
		}
		i++;
	}
	tetri[j] = 0;
	return (tetri);
}

int				main(int argc, char **argv)
{
	char		buf[2];
	int			ret;
	int			fd;
	char		*str;

	if (argc == 2)
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_putstr_fd("usage: file not open\n", 1);
		else
		{
			ret = read(fd, buf, 1);
			str = ft_strdup(buf);
			while ((ret = read(fd, buf, 1)) > 0)
				str = ft_strjoin(str, buf);
			buf[ret] = '\0';
			if (ft_check(str) == 1 &&
				ft_check_form(ft_create_the_tab(str)) == 1)
				ft_resolv(ft_create_the_tab(str), ft_nbr_parts(str));
			else
				ft_putendl("error");
			close(fd);
		}
	else
		ft_putstr("usage: file not found\n");
	return (0);
}
