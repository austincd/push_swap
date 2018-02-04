/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pslfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 22:26:17 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 20:39:49 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

intmax_t		ft_pslfind(t_pscell **ablist, uintmax_t value)
{
	intmax_t	length;
	intmax_t	counter;

	counter = 0;
	length = ft_psllength(ablist[0]);
	while (counter < length)
	{
		if (ablist[0][counter].correct == value)
			return (counter + 1);
		++counter;
	}
	counter = 0;
	length = ft_psllength(ablist[1]);
	while (counter < length)
	{
		if (ablist[1][counter].correct == value)
			return ((counter + 1) * -1);
		++counter;
	}
	return (0);
}
