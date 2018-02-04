/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_in_order.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 03:04:50 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 22:58:56 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

static uintmax_t	ft_highestselstr(t_pscell **ablist, int which_list, char *selstr)
{
	uintmax_t	length;
	uintmax_t	counter;
	intmax_t	bests[2];

	bests[0] = -1;
	bests[1] = -1;
	counter = 0;
	if (ablist && ablist[which_list] && selstr)
	{
		length = ft_psllength(ablist[which_list]);
		while (counter < length)
		{
            if (selstr[counter] == '1' && ((intmax_t)ablist[which_list][counter].correct > bests[1] || bests[1] == -1))
			{
				bests[0] = counter;
				bests[1] = ablist[which_list][counter].correct;
			}
			++counter;
		}
	}
	return (bests[0]);
}

static uintmax_t	ft_lowestselstr(t_pscell **ablist, int which_list, char *selstr)
{
	uintmax_t	length;
	uintmax_t	counter;
	intmax_t	bests[2];

	bests[0] = -1;
	bests[1] = -1;
	counter = 0;
	if (ablist && ablist[which_list] && selstr)
	{
		length = ft_psllength(ablist[which_list]);
//		printf("selstr: %s\nlength:%ju\n", selstr, length);
	    while (counter < length)
        {
            if (selstr[counter] == '1' && ((intmax_t)ablist[which_list][counter].correct < bests[1] || bests[1] == -1))
            {
                bests[0] = counter;
                bests[1] = ablist[which_list][counter].correct;
            }
			++counter;
        }
	}
	return (bests[0]);
}

intmax_t	ft_sifting_sedge(t_pscell **ablist, int which_list, char *selstr)
{
	uintmax_t	length;
	intmax_t	lowest;
	intmax_t	highest;
	intmax_t	ret;
	int			ledge;

	ledge = 0;
	ret = -1;
	ledge = ft_strrchr(selstr, '1') - selstr;
	if (ablist && ablist[which_list])
	{
		length = ft_psllength(ablist[which_list]);
		lowest = ft_lowestselstr(ablist, which_list, selstr);
		highest = ft_highestselstr(ablist, which_list, selstr);
//		printf("highest is %ji, lowest is %ji\n", highest, lowest);
//		printf("ledge is %i\n", ledge);
//		printf("sedge selstr = %s\n", selstr);
//		getchar();
//		if ((lowest == ledge && highest == ft_strchr(selstr, '1') - selstr) || (highest == ledge && lowest == ft_strchr(selstr, '1') - selstr))
		if (((ft_strchr((selstr + lowest + 1), '1') - selstr) == highest) || ((ft_strrchr(selstr, '1') - selstr) == lowest && (ft_strchr(selstr, '1') - selstr) == highest))
			ret = highest;
		else if (highest == (lowest < (intmax_t)length - 1 ? lowest + 1 : 0))
			ret = highest;
	}
	return (ret);
}

intmax_t	ft_orderedpushselstr(t_pscell **ablist, uintmax_t size, uintmax_t radius, int which_list, char *selstr, char *placement)
{
	uintmax_t	length;
	intmax_t	leftover;
	uintmax_t	counter;
	intmax_t	right_spot;
	intmax_t	bests[5];

	right_spot = -1;
	counter = 0;
	bests[0] = -1;
	bests[1] = -1;
	bests[2] = -1;
	if (ablist && size && selstr && placement)
	{
		length = ft_psllength(ablist[which_list]);
//		printf("length found!\n");
		while (counter < length)
		{
			if (selstr[counter] == '1' && (counter < radius || length - counter < radius))
			{
//				printf("counter is %ju, radius is %ju\n", counter, radius);
				if ((right_spot = ft_find_right_spot_selstr(ablist, size, (counter + 1) * (which_list ? -1 : 1), placement)) >= 0)
				{
					leftover = (counter > radius ? radius - (length - counter) : radius - counter);
//					printf("leftover is %ju\n", leftover);
//					printf("right spot is %ju\n", right_spot);
					if (leftover >= 0 && (right_spot <= leftover || ft_psllength(ablist[which_list ? 0 : 1]) - right_spot < (uintmax_t)leftover))
					{
						bests[4] = right_spot;
						bests[3] = counter;
						ft_opush_select(ablist, size, bests + 3, bests);
//						printf("bests = %ju, %ju, %ju, %ju, %ju\n", bests[0], bests[1], bests[2], bests[3], bests[4]);
//						getchar();
//						bests[0] = ((ablist[which_list][counter].correct < bests[1]) || bests[1] == -1) ? counter : bests[0];
//						bests[1] = ((ablist[which_list][counter].correct < bests[1]) || bests[1] == -1) ? ablist[which_list][counter].correct : bests[1];
					}
				}
			}
			++counter;
		}
	}
	return (bests[0]);
}
