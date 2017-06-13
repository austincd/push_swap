/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psldup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:38:39 by adaly             #+#    #+#             */
/*   Updated: 2017/06/12 17:38:41 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

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

t_pscell	**ft_psldup(t_pscell **ablist)
{
	uintmax_t	asize;
	uintmax_t	bsize;
	t_pscell	**new;

	new = NULL;
	if (ablist)
	{
		new = (t_pscell**)ft_memalloc(sizeof(t_pscell*) * 2);
		asize = ft_pslsize(alist);
		bsize = ft_pslsize(blist);
		if (new)
		{
			new[0] = (t_pscell*)ft_memalloc(sizeof(t_pscell) * asize);
			new[1] = (t_pscell*)ft_memalloc(sizeof(t_pscell) * bsize);
			ft_psldup_helper(new[0], ablist[0], asize);
			ft_psldup_helper(new[1], ablist[1], bsize);
		}
	}
	return (new);
}
