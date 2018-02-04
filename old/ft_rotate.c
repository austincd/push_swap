/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 04:33:57 by adaly             #+#    #+#             */
/*   Updated: 2017/06/13 04:56:20 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rotate_ab(t_pscell **ablist, uintmax_t asize, uintmax_t bsize)
{
	if (ablist)
	{
		ft_rotate_a(ablist, asize);
		ft_rotate_b(ablist, bsize);
	}
}

void	ft_rotate_b(t_pscell **ablist, uintmax_t bsize)
{
	t_pscell	temp;

	if (ablist)
	{
		temp = ablist[1][0];
		ft_shift_up(ablist, 'b', bsize);
		temp.current = bsize - 1;
		temp.next = ablist[1];
		ablist[1][bsize - 1] = temp;
		ablist[1][bsize - 2].next = ablist[1] + (bsize - 1);
	}
}


void	ft_rotate_a(t_pscell **ablist, uintmax_t asize)
{
	t_pscell	temp;

	if (ablist)
	{
		temp = ablist[0][0];
		ft_shift_up(ablist, 'a', asize);
		temp.current = asize - 1;
		temp.next = ablist[0];
		ablist[0][asize - 1] = temp;
		ablist[0][asize - 2].next = ablist[0] + (asize - 1);
	}
}
