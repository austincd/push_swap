/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psldup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:38:39 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 20:37:42 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_psldup_helper(t_pscell *new, t_pscell *old, uintmax_t size)
{
	uintmax_t	counter;

	counter = 0;
	while (counter < size)
	{
		new[counter] = old[counter];
		++counter;
	}
}

t_pscell	**ft_psldup(t_pscell **ablist, uintmax_t size)
{
	t_pscell	**new;

	new = NULL;
	if (ablist)
	{
		new = (t_pscell**)ft_memalloc(sizeof(t_pscell*) * 2);
		if (new)
		{
			new[0] = (t_pscell*)ft_memalloc(sizeof(t_pscell) * size + 1);
			new[1] = (t_pscell*)ft_memalloc(sizeof(t_pscell) * size + 1);
//			printf("new0 is %p\n", new[0]);
//			printf("new1 is %p\n", new[1]);
			ft_psldup_helper(new[0], ablist[0], size);
			ft_psldup_helper(new[1], ablist[1], size);
		}
	}
	return (new);
}
