/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgricour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:33:22 by kgricour          #+#    #+#             */
/*   Updated: 2017/12/14 15:21:54 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int		ft_resolv(char **tetri, int nbr_part);
void	ft_diese_to_alpha(char **tetri, int k);
int		ft_check_form(char **str);
int		ft_check(char *str);
void	ft_move_points(char **new_tetri, int *j, int *l, int **x);
void	ft_add_tetri_in_tab(char **new_tetri, char **tab, int *x, int *y);
void	ft_check_points(char **new_tetri, int *s, int *t, int *x);
void	ft_point_condition(int *i, int *s, int *t);
int		ft_check_write(char **tab, char **new_tetri, int x, int y);
char	**ft_new_tetri(char *tetri);
char	**ft_swap_tetri(char **new_tetri);
void	ft_cut_tetri(char **new_tetri);
char	**ft_create_tab(int i);
void	ft_del_tetri_in_tab(char **tab, int x, int y, int k);

#endif
