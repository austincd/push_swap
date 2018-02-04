/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_done.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:58:16 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 17:03:30 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
**Checks to see that all elements of the list are sorted properly.
*/

int	ft_done(t_pscell **ablist)
{
	uintmax_t	counter;
	uintmax_t	size;

	counter = 0;
	if (ablist)
	{
		size = ft_psllength(ablist[0]);
		if (ft_psllength(ablist[1]))
			return (0);
		while (counter < size)
		{
			if (ablist[0][counter].correct != counter)
				return (0);
			++counter;
		}
		return (1);
	}
	return (0);
}
