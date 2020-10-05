/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:13:12 by aapricot          #+#    #+#             */
/*   Updated: 2019/11/12 22:36:00 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list			*ft_else1(uint16_t **map, t_param *p, t_list *node)
{
	*(uint64_t *)(*map + p->y) ^= ((uint64_t)node->content >> p->x);
	node->pos_x = p->x;
	node->pos_y = p->y;
	p->x = 0;
	p->y = 0;
	node = node->next;
	return (node);
}

void			ft_print_map(int size, t_list **list)
{
	char		**map;
	int			i;
	int			j;
	uint64_t	tmp;

	j = -1;
	i = -1;
	tmp = 0;
	map = (char **)malloc(sizeof(char *) * (size + 1));
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
	map[size] = NULL;
	ft_putalpha(list, size, tmp, map);
}

t_list			*ft_func(t_list *node, t_list **list,\
						t_param *p, uint16_t **map)
{
	if (++p->y == p->size && node)
	{
		if (node->content_size != 0)
		{
			node = get_node(list, node->content_size - 1, 0);
			*(uint64_t *)(*map + node->pos_y) ^=
				((uint64_t)node->content >> node->pos_x);
			p->x = node->pos_x + 1;
			p->y = node->pos_y;
		}
		else if (node->content_size == 0)
		{
			p->size++;
			*map = get_map(p->size);
			p->y = 0;
			node = get_node(list, 0, 0);
		}
	}
	return (node);
}

int				ft_puttetra(uint16_t *map, t_list **list, int size)
{
	t_list		*node;
	t_param		p;

	p.y = 0;
	p.x = 0;
	p.size = size;
	node = get_node(list, 0, 0);
	while (node)
	{
		while (node)
		{
			if (*(uint64_t *)(map + p.y) & (uint64_t)node->content >> p.x)
			{
				if (++p.x >= p.size)
					break ;
			}
			else
				node = ft_else1(&map, &p, node);
		}
		p.x = 0;
		node = ft_func(node, list, &p, &map);
	}
	return (p.size);
}

void			ft_solution(t_list **list, int i)
{
	t_list		*node;
	int			size;
	int			x;
	uint16_t	*map;

	x = 0;
	node = *list;
	size = ft_sqrt(i * 4);
	map = get_map(size);
	x = ft_puttetra(map, list, size);
	ft_print_map(x, list);
}
