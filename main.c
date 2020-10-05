/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:12:30 by aapricot          #+#    #+#             */
/*   Updated: 2019/11/12 22:47:57 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_finalprint(int size, char **map)
{
	int				i;

	i = -1;
	while (++i < size)
		ft_putstr(map[i]);
	ft_matfree(map);
}

uint16_t			*get_map(int size)
{
	uint16_t		temp;
	int				i;
	static uint16_t	map[16];

	i = 0;
	temp = 65535;
	temp = temp >> size;
	while (i < size)
	{
		map[i] = temp;
		i++;
	}
	while (i < 16)
	{
		map[i] = 65535;
		i++;
	}
	return (map);
}

void				ft_putalpha(t_list **list, int size,\
								uint64_t tmp, char **map)
{
	t_list			*node;
	int				k;
	int				o;
	int				i;
	int				j;

	node = get_node(list, 0, 0);
	while (node)
	{
		k = 0;
		i = 4;
		o = 64;
		tmp = (uint64_t)node->content >> node->pos_x;
		while (--i >= 0)
		{
			j = -1;
			while (++j < size)
				if (tmp & (1ULL << --o))
					map[node->pos_y + i][j] = node->content_size + 'A';
			o = 64 - (16 * ++k);
		}
		node = node->next;
	}
	ft_finalprint(size, map);
}

int					main(int argc, char **argv)
{
	int				fd;

	if (argc == 1)
	{
		ft_putstr("usage: ./fillit source_file target_file\n");
		exit(0);
	}
	if (argc > 2)
	{
		ft_putstr("usage: ./fillit source_file target_file\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	ft_reader(fd);
	close(fd);
	return (0);
}
