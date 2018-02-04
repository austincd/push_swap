/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 02:07:24 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 17:05:23 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_push_a(t_pscell **ablist)
{
	uintmax_t	asize;
	uintmax_t	bsize;

	asize = ft_psllength(ablist[0]);
	bsize = ft_psllength(ablist[1]);
	if (ablist && bsize)
	{
		ft_shift_down(ablist, 'a');
		ablist[0][0] = ablist[1][0];
		ft_shift_up(ablist, 'b');
	}
}

void	ft_push_b(t_pscell **ablist)
{
	uintmax_t	asize;
	uintmax_t	bsize;

	asize = ft_psllength(ablist[0]);
	bsize = ft_psllength(ablist[1]);
	if (ablist && asize)
	{
		ft_shift_down(ablist, 'b');
		ablist[1][0] = ablist[0][0];
		ft_shift_up(ablist, 'a');
	}
}

