/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:38:48 by aapricot          #+#    #+#             */
/*   Updated: 2019/11/12 22:42:30 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef	struct		s_param
{
	int				x;
	int				y;
	int				size;
}					t_param;

uint16_t			*get_map(int size);
void				ft_reader(int fd);
void				ft_solution(t_list **list, int i);
int					main(int argc, char **argv);
t_list				*get_node(t_list **list, int c, uint64_t x);
void				ft_putalpha(t_list **list, int size,\
								uint64_t tmp, char **map);

#endif
