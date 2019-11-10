/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:11:47 by aapricot          #+#    #+#             */
/*   Updated: 2019/11/10 19:37:22 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matfree(char **str)
{
	int x;

	x = 0;
	while (str[x])
		free(str[x++]);
	free(str[x]);
	free(str);
	str = NULL;
}
