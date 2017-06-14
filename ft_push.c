/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 02:07:24 by adaly             #+#    #+#             */
/*   Updated: 2017/06/13 18:40:32 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_push_a(t_pscell **ablist, uintmax_t asize)
{
	uintmax_t	bsize;

	bsize = ft_pslsize(ablist[1]);
	if (ablist && bsize)
	{
		ft_shift_down(ablist, 'a', asize);
		ablist[0][0] = ablist[1][0];
		ft_shift_up(ablist, 'b', bsize);
	}
}

void	ft_push_b(t_pscell **ablist, uintmax_t bsize)
{
	uintmax_t	asize;

	asize = ft_pslsize(ablist[0]);
	if (ablist && ft_pslsize(ablist[0]))
	{
		ft_shift_down(ablist, 'b', bsize);
		ablist[1][0] = ablist[0][0];
		ft_shift_up(ablist, 'a', asize);
	}
}

