/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 03:22:16 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 17:10:06 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_shift_down(t_pscell **ablist, char aorb)
{
	int n;
	intmax_t size;

	size = 0;
	n = 0;
	if (ablist)
	{
		if (aorb == 'b')
			n = 1;
		size = ft_psllength(ablist[n]);
		while (size > 0)
		{
			ablist[n][size] = ablist[n][size - 1];
			ablist[n][size].current += 1;
			--size;
		}
		ft_psczero(ablist[n]);
		ablist[n][0].active = 1;
	}
}

void	ft_shift_up(t_pscell **ablist, char aorb)
{
	uintmax_t	counter;
	uintmax_t	size;
	int n;

	n = 0;
	counter = 0;
	size = 0;
	if (ablist)
	{
		if (aorb == 'b')
			n = 1;
		size = ft_psllength(ablist[n]);
		while (counter + 1 < size)
		{			
			ablist[n][counter] = ablist[n][counter + 1];
			if (ablist[n][counter].current)
				ablist[n][counter].current -= 1;
			++counter;
		}
//		ablist[n][counter] = ablist[n][counter + 1];
//			if (ablist[n][counter].current)
//				ablist[n][counter].current -= 1;
		 ft_psczero(ablist[n] + size - 1);
	}
}
