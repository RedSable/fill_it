void		ft_print_map(int size, t_list **list)
{
	char	**map;
	t_list	*node;
	uint64_t tmp;
	int		i;
	int		j;
	int		o;
	int		k;

	o = 63;
	j = 0;
	i = 0;
	k = 0;
	node = get_node(list, 0, 0);
	map = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
		map[i][size] = '\0';
		i++;
	}
	i = 0;
	while (i < size)
	{
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	map[i] = NULL;
	while (node)
	{
		k = 0;
		i = 3;
		o = 63;
		tmp = (uint64_t)node->content >> node->pos_x;
		while (i >= 0)
		{
			j = 0;
			while (j < size)
			{
				if (tmp & (1ULL << o))
					map[node->pos_y + i][j] = node->content_size + 'A';
				j++;
				o--;
			}
			k++;
			o = 63 - (16 * k);
			i--;
		}
		node = node->next;
	}
	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
	ft_matfree(map);
}