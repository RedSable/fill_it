/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:13:12 by aapricot          #+#    #+#             */
/*   Updated: 2019/11/10 21:18:38 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print_map(int size, t_list **list)
{
	char	**map;
	int		i;
	int		j;
	uint64_t tmp;

	j = -1;
	i = -1;
	tmp = 0;
	map = (char **)malloc(sizeof(char *) * size + 1);
	while (++i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * (size + 2));
		map[i][size + 1] = '\0';
		map[i][size] = '\n';
	}
	i = -1;
	while (++i < size)
	{
		while (++j < size)
			map[i][j] = '.';
		j = -1;
	}
	map[i] = NULL;
	ft_putalpha(list, size, tmp, map);
}

uint16_t		*get_map(int size)
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

int		ft_puttetra(uint16_t *map, t_list **list, int size)
{
	int			i;
	int			y;
	int			x;
	t_list		*node;

	i = 0;
	y = 0;
	x = 0;
	node = get_node(list, 0, 0);
	while (node)
	{
		while (node)
		{
			if (*(uint64_t *)(map + y) & (uint64_t)node->content >> x)
			{
				x++;
				if (x >= size)
					break ;
			}
			else
			{
				*(uint64_t *)(map + y) ^= ((uint64_t)node->content >> x);
				node->pos_x = x;
				node->pos_y = y;
				x = 0;
				y = 0;
				node = node->next;
			}
		}
		x = 0;
		y++;
		if (y == size && node)
		{
			if (node->content_size != 0)
			{
				node = get_node(list, node->content_size - 1, 0);
				*(uint64_t *)(map + node->pos_y) ^= ((uint64_t)node->content >> node->pos_x);
				x = node->pos_x + 1;
				y = node->pos_y;
			}
			else if (node->content_size == 0)
			{
				size++;
				map = get_map(size);
				y = 0;
				node = get_node(list, 0, 0);
			}
		}
	}
	return (size);
}

void	ft_solution(t_list **list, int i)
{
	t_list			*node;
	int				size;
	int				x;
	uint16_t				*map;

	x = 0;
	node = *list;
	size = ft_sqrt(i * 4);
	map = get_map(size);
	x = ft_puttetra(map, list, size);
	ft_print_map(x, list);
}
