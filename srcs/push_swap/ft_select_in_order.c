/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_in_order.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 03:04:50 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 20:56:29 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static uintmax_t	ft_highest(t_pscell **ablist, int which_list)
{
	uintmax_t	length;
	uintmax_t	counter;
	intmax_t	bests[2];

	bests[0] = -1;
	bests[1] = -1;
	counter = 0;
	if (ablist && ablist[which_list] && (length = ft_psllength(ablist[which_list])))
	{
		while (counter < length)
		{
            if ((intmax_t)ablist[which_list][counter].correct > bests[1] || bests[1] == -1)
			{
				bests[0] = counter;
				bests[1] = ablist[which_list][counter].correct;
			}
			++counter;
		}
	}
	return (bests[0]);
}

static uintmax_t	ft_lowest(t_pscell **ablist, int which_list)
{
	uintmax_t	length;
	uintmax_t	counter;
	intmax_t	bests[2];

	bests[0] = -1;
	bests[1] = -1;
	counter = 0;
	if (ablist && ablist[which_list] && (length = ft_psllength(ablist[which_list])))
	{
	    while (counter < length)
        {
            if ((intmax_t)ablist[which_list][counter].correct < bests[1] || bests[1] == -1)
            {
                bests[0] = counter;
                bests[1] = ablist[which_list][counter].correct;
            }
            ++counter;
        }
	}
	return (bests[0]);
}

intmax_t	ft_sifting_edge(t_pscell **ablist, int which_list)
{
	uintmax_t	length;
	intmax_t	lowest;
	intmax_t	highest;
	intmax_t	ret;

	ret = -1;
	if (ablist && ablist[which_list] && (length = ft_psllength(ablist[which_list])))
	{
		lowest = ft_lowest(ablist, which_list);
		highest = ft_highest(ablist, which_list);
		if (highest == (lowest < (intmax_t)length - 1 ? lowest + 1 : 0))
			ret = highest;
		if (!which_list && highest == (intmax_t)(lowest ? lowest - 1 : length - 1))
			ret = lowest;
	}
	return (ret);
}

intmax_t	ft_orderedpush(t_pscell **ablist, uintmax_t size, uintmax_t radius, int which_list)
{
	uintmax_t	length;
	uintmax_t	leftover;
	uintmax_t	counter;
	intmax_t	right_spot;
	intmax_t	bests[5];

	right_spot = -1;
	counter = 0;
	bests[0] = -1;
	bests[1] = -1;
	bests[2] = -1;
	if (ablist && size)
	{
		length = ft_psllength(ablist[which_list]);
		while (counter < length)
		{
//			printf("counter is %ju\n", counter);
			if (counter < radius || length - counter < radius)
			{
				if ((right_spot = ft_find_right_spot(ablist, (counter + 1) * (which_list ? -1 : 1))) >= 0)
				{
					leftover = (counter > radius ? radius - (length - counter) : radius - counter);
//					printf("leftover is %ju\n", leftover);
//					printf("right spot is %ju\n", right_spot);
					if (right_spot <= (intmax_t)leftover || ft_psllength(ablist[which_list ? 0 : 1]) - right_spot < leftover)
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

/*char	*ft_radial_search(t_pscell **ablist, intmax_t element, uintmax_t radius)
{
	uintmax_t	usable_range[2];
	uintmax_t	counter;
	uintmax_t	length;
	uintmax_t	leftover;

	leftover = radius;
	if (ft_absval(element) - 1 < radius || (ft_psllength(ablist[which_list]) - ft_absval(element) < radius))
	{
		leftover -= (ft_absval(element) - 1 < radius) ? (ft_absval(element) - 1) : ft_psllength(ablist[which_list]) - ft_absval(element);
		if (leftover)
			usable_range[0] = ablist[opp_list][counter]
		while 
	}
}

char	*ft_radial_search(t_pscell **ablist, uintmax_t radius)
{
	if (ablist)
	{
		if (ablist[which_list][0])
	}
}

char	*ft_ordered_select(t_pscell **ablist, uintmax_t size, char *selection, int which_list)
{
	if (ablist && size && selection)
	{
		if ((duplicate = ft_psldup(ablist)))
		{
			while (ft_strchr(selection, '1'))
			{
			}
		}
	}
}*/
