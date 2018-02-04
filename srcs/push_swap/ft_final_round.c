/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_round.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:25:25 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 23:10:12 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int		ft_ready_to_rotate(t_pscell **ablist)
{
	int			ret;
	intmax_t	alen;
	intmax_t	locations[3];
	intmax_t	counter;

	ret = 0;
	ft_bzero(locations, sizeof(intmax_t) * 3);
	alen = ft_psllength(ablist[0]);
	if (ablist && !ft_psllength(ablist[1]))
	{
		counter = 0;
		while (counter < alen - 1)
		{
			locations[0] = ft_pslfind(ablist, counter);
			locations[1] = ft_pslfind(ablist, counter + 1);
			if (locations[1] != locations[0] + 1)
			{
				if (locations[0] != alen || locations[1] != 1)
					return (0);
			}
			++counter;
		}
		if (counter == alen - 1)
			ret = 1;
	}
	return (ret);
}

char	*ft_final_round(t_pscell **ablist, uintmax_t size)
{
	char		*final_rotation;
	intmax_t	zero;

	final_rotation = NULL;
	if (ablist && size)
	{
		if (ft_ready_to_rotate(ablist))
		{
			zero = ft_pslfind(ablist, 0);
			if (zero > 1)
			{
				final_rotation = ft_speed_surfacing(ablist, zero - 1, 0);
			}
		}
	}
	return (final_rotation);
}
