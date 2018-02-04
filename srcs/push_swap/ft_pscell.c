/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pscell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 18:42:51 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 17:09:30 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void		ft_psczero(t_pscell *target)
{
	if (target)
	{
		(*target).value = 0;
		(*target).correct = 0;
		(*target).current = 0;
		(*target).active = 0;
		(*target).locked = 0;
	}
}

void		ft_pslcpy(t_pscell *src, t_pscell *dst, uintmax_t size)
{
	uintmax_t	counter;

	counter = 0;
	if (src && dst)
	{
		while (counter < size)
		{
			dst[counter] = src[counter];
			++counter;
		}
	}
}

void		ft_ablist_cpy(t_pscell **src, t_pscell **dst, uintmax_t size)
{
	if (src && dst)
	{
		ft_pslcpy(src[0], dst[0], size);
		ft_pslcpy(src[1], dst[1], size);
	}
}
