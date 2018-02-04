/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keep_gaps_equal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 05:15:39 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 21:04:41 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_opush_select(t_pscell **ablist, uintmax_t size, intmax_t *locations, intmax_t *bests)
{
	uintmax_t	predecessor;
	uintmax_t	successor;
	uintmax_t	indexes[2];
	uintmax_t	val[2];
	int		which_list;

	if (ablist && size && locations && bests)
	{
		which_list = (locations[1] < 0) ? 1 : 0;
		indexes[1] = (ft_absval(locations[1]) - 1);
		indexes[0] = locations[0];
		predecessor = ablist[which_list][indexes[1]].correct;
		successor = ablist[which_list][(indexes[1] ? (indexes[1] - 1) : (ft_psllength(ablist[which_list] - 1)))].correct;
		if ((successor < predecessor && which_list) || (successor > predecessor && !which_list))
			successor += size;
		val[0] = ablist[(which_list ? 0 : 1)][indexes[0]].correct;
		val[1] = ft_diff(ft_mean(predecessor, successor), val[0]);
		if ((intmax_t)val[1] < bests[2] || bests[2] == -1)
		{
			bests[0] = indexes[0];
			bests[1] = val[0];
			bests[2] = val[1];
		}
	}
}
