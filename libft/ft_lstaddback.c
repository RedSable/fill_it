/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:39:14 by aapricot          #+#    #+#             */
/*   Updated: 2019/10/16 13:38:48 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list		**tmp;

	if (!new || !alst)
		return ;
	tmp = alst;
	while (*tmp)
	{
		tmp = &(*tmp)->next;
	}
	new->next = *tmp;
	*tmp = new;
}
