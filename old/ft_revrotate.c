/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 04:33:57 by adaly             #+#    #+#             */
/*   Updated: 2017/06/13 05:19:04 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_revrotate_ab(t_pscell **ablist, uintmax_t asize, uintmax_t bsize)
{
	if (ablist)
	{
		ft_revrotate_a(ablist, asize);
		ft_revrotate_b(ablist, bsize);
	}
}

void	ft_revrotate_b(t_pscell **ablist, uintmax_t bsize)
{
	t_pscell	temp;

	if (ablist)
	{
		temp = ablist[1][bsize - 1];
		ft_shift_down(ablist, 'b', bsize);
		temp.current = 0;
		temp.next = ablist[1] + 1;
		ablist[1][0] = temp;
		ablist[1][bsize - 1].next = ablist[1];
	}
}


void	ft_revrotate_a(t_pscell **ablist, uintmax_t asize)
{
	t_pscell	temp;

	if (ablist)
	{
		temp = ablist[0][asize - 1];
		ft_shift_down(ablist, 'a', asize);
		temp.current = 0;
		temp.next = ablist[0] + 1;
		ablist[0][0] = temp;
		ablist[0][asize - 1].next = ablist[0];
	}
}
