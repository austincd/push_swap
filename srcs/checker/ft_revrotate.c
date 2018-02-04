/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 04:33:57 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 17:05:53 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_revrotate_ab(t_pscell **ablist)
{
	if (ablist)
	{
		ft_revrotate_a(ablist);
		ft_revrotate_b(ablist);
	}
}

void	ft_revrotate_b(t_pscell **ablist)
{
	t_pscell	temp;
	uintmax_t	blen;

	blen = ft_psllength(ablist[1]);
	if (ablist)
	{
		temp = ablist[1][blen - 1];
		ft_shift_down(ablist, 'b');
		temp.current = 0;
		ablist[1][0] = temp;
		ft_psczero(ablist[1] + blen);
	}
}


void	ft_revrotate_a(t_pscell **ablist)
{
	t_pscell	temp;
	uintmax_t	alen;

	alen = ft_psllength(ablist[0]);
	if (ablist)
	{
		temp = ablist[0][alen - 1];
		ft_shift_down(ablist, 'a');
		temp.current = 0;
		ablist[0][0] = temp;
		ft_psczero(ablist[0] + alen);
	}
}
