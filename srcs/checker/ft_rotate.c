/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 04:33:57 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 17:05:43 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_rotate_ab(t_pscell **ablist)
{
	if (ablist)
	{
		ft_rotate_a(ablist);
		ft_rotate_b(ablist);
	}
}

void	ft_rotate_b(t_pscell **ablist)
{
	t_pscell	temp;
	uintmax_t	blen;

	blen = 0;
	if (ablist)
	{
		blen = ft_psllength(ablist[1]);
		if (blen >= 2)
		{
			temp = ablist[1][0];
			ft_shift_up(ablist, 'b');
			temp.current = blen - 1;
//			ablist[1][blen - 2] = ablist[1][blen - 1];
			ablist[1][blen - 1] = temp;
		}
	}
}

void	ft_rotate_a(t_pscell **ablist)
{
	t_pscell	temp;
	uintmax_t	alen;

	alen = 0;
	if (ablist)
	{
		alen = ft_psllength(ablist[0]);
		if (alen >= 2)
		{
			temp = ablist[0][0];
			ft_shift_up(ablist, 'a');
			temp.current = alen - 1;
//			ablist[0][alen - 2] = ablist[0][alen - 1];
			ablist[0][alen - 1] = temp;
		}
	}
}
