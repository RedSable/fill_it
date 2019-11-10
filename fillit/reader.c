/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 20:12:52 by aapricot          #+#    #+#             */
/*   Updated: 2019/11/10 18:54:11 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static uint64_t			ft_move(uint64_t x)
{
	uint64_t			tmp;
	uint64_t			res;
	int					i;

	i = 0;
	res = 0;
	if (x < 16)
		x = x << 12;
	else if (x < 256)
		x = x << 8;
	else if (x < 4096)
		x = x << 4;
	while (!(x & (1 << 15)) && !(x & (1 << 11))
			&& !(x & (1 << 7)) && !(x & (1 << 3)))
		x = x << 1;
	tmp = (x & 15) << 60;
	res = res | tmp;
	tmp = (x & 240) << 40;
	res = res | tmp;
	tmp = (x & 3840) << 20;
	res = res | tmp;
	tmp = (x & 61440);
	res = res | tmp;
	return (res);
}

t_list					*get_node(t_list **list, int c, uint64_t x)
{
	t_list				*node;

	node = *list;
	while (node)
	{
		if (node->content_size == c)
			return (node);
		node = node->next;
	}
	node = ft_lstnew(NULL, 1);
	node->content = (void *)(size_t)x;
	node->content_size = c;
	ft_lstaddback(list, node);
	node = *list;
	return (node);
}

static int				ft_istetr(uint64_t x, int count)
{
	int					i;

	i = 16;
	if (count == -1)
	{
		ft_putstr("error\n");
		exit(0);
	}
	while (--i >= 0)
	{
		if ((x & (1 << i)))
		{
			if ((x & (1 << (i + 1))))
				count++;
			if ((x & (1 << (i - 1))))
				count++;
			if ((x & (1 << (i + 4))))
				count++;
			if ((x & (1 << (i - 4))))
				count++;
		}
	}
	if (count == 6 || count == 8)
		return (1);
	return (-1);
}

static uint64_t			ft_isvalid(char *buff)
{
	uint64_t			x;
	int					i;
	int					j;
	int					count;

	count = 0;
	i = 15;
	j = -1;
	x = 0;
	while (buff[++j])
	{
		if (buff[j] == '#')
		{
			x |= 1 << i;
			count++;
			i--;
		}
		else if (buff[j] == '.')
			i--;
		else if (buff[j] != '\n')
			ft_istetr(1, -1);
	}
	if (count != 4 || i < -1 || ft_istetr(x, 0) < 0)
		ft_istetr(1, -1);
	return (ft_move(x));
}

void					ft_reader(int fd)
{
	static t_list		*list;
	t_list				*node;
	int					i;
	int					read_bytes;
	char				buff[BUFF_SIZE + 1];

	i = 0;
	while ((read_bytes = read(fd, buff, BUFF_SIZE)))
	{
		buff[read_bytes] = 0;
		if (read_bytes < 20 || buff[4] != '\n' || buff[9] != '\n'
			|| buff[14] != '\n' || buff[19] != '\n')
		{
			ft_putstr("error\n");
			exit(0);
		}
		node = get_node(&list, i, ft_isvalid(buff));
		i++;
	}
	if ((ft_strlen(buff) != 20) || i > 26)
	{
		ft_putstr("error\n");
		exit(0);
	}
	ft_solution(&node, i);
}
