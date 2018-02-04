/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 21:55:00 by adaly             #+#    #+#             */
/*   Updated: 2017/10/04 23:31:50 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
intent: create a function that given a pushswap list pair ABLIST, finds a way
to merge two ordered lists in the least possible number of operations. This
is going to also have the capibility to merge two ordered list segments in 
opposite lists even when list A and list B as a whole are not sorted.

Due to the nature of the pushswap operations, the segment to be merged in
list B must be in descending order, and the segment to be merged in list A
must be in ascending order.

The function will return a set of steps consisting of some number of pushes
and rotations, the sum of which will be equal to the higher of the lengths
of each segment;

Because we want to be merging into list A, we're going to start by finding
the shortest sequence of moves that'll bring us to a point where we can push
the topmost element of B back to list A and have it be ordered. After this
is located, we push until we reach a point where the top element of B would
be out of order at the top of list A. At this point, because we can assume
both list segments are sorted, we can just rotate list A until that is no
longer the case. Rinse and repeat until all the elements from segment B
are merged into segment A in an ordered manner;

*/

static int	ft_descent_length(t_pscell **ablist, uintmax_t size)
{
	int				list_length;
	int				descent_length;

	descent_length = -1;
	if (ablist && size && ablist[1] && (list_length = ft_psllength(ablist[1])))
	{
		descent_length = 1;
		while (descent_length < list_length && ablist[1][descent_length].correct < \
				ablist[1][descent_length - 1].correct)
			++descent_length;
//		while (descent_length < list_length && ablist[1][descent_length].correct ==
//			--current)
	}
	return (descent_length);
}

static int	ft_highest(t_pscell **ablist, uintmax_t size)
{
	int		counter;
	int		alen;

	counter = 0;
	if (ablist && size)
	{
		alen = ft_psllength(ablist[0]);
		while (counter < alen)
		{
			if (ablist[0][counter].correct > ablist[1][0].correct)
				return (0);
			++counter;
		}
		return (1);
	}
	return (0);
}

static int	ft_lowest(t_pscell **ablist, uintmax_t size)
{
	int		counter;
	int		alen;

	counter = 0;
	if (ablist && size)
	{
		alen = ft_psllength(ablist[0]);
		while (counter < alen)
		{
			if (ablist[0][counter].correct < ablist[1][0].correct)
				return (0);
			++counter;
		}
		return (1);
	}
	return (0);
}

int			ft_merge_validate(t_pscell **ablist)
{
	int		ret;
	int		alen;
	int		blen;
	int		edge;
	int		size;

	ret = 0;
	if (ablist)
	{
		edge = ft_sifting_edge(ablist, 0);
		alen = ft_psllength(ablist[0]);
		blen = ft_psllength(ablist[1]);
		size = alen + blen;
		if ((ft_lowest(ablist, size) || ft_highest(ablist, size)) && edge == 0)
			ret = 1;
		if (ablist[1][0].correct < ablist[0][0].correct && ablist[1][0].correct > ablist[0][alen - 1].correct)
			ret = 1;
	}
	return (ret);
}

static int	ft_merge_spot(t_pscell **ablist)
{
//	int		where_to;
//	int		lstlen;
//	int		edge;
	t_pscell	**duplicate;
	char	rot[2];
	int		firstlast[2];
	int		counter;

	rot[1] = 0;
	rot[0] = '6';
	counter = 0;
	firstlast[0] = -1;
	firstlast[1] = -1;
	duplicate = ft_psldup(ablist, ft_psllength(ablist[0]) + ft_psllength(ablist[1]));
//	duplicate[1] = ft_psldup(ablist);
	while (counter < (intmax_t)(ft_psllength(ablist[0])))
	{
		if (ft_merge_validate(duplicate))
		{
			if (firstlast[0] < 0)
				firstlast[0] = counter;
			firstlast[1] = counter;
		}
		ft_apply_moves(duplicate, rot);
		++counter;
	}
	if ((intmax_t)ft_psllength(ablist[0]) - firstlast[1] < firstlast[0])
		return (firstlast[1]);
	else
		return (firstlast[0]);
/*	where_to = -1;
	lstlen = ft_psllength(ablist[1]);
	if (ablist[0][edge].correct < ablist[1][0].correct)
		return (edge);
	if (ablist[0][(edge < lstlen - 1) ? edge + 1 : 0].correct > \
		ablist[1][0].correct)
		return ((edge < lstlen - 1) ? edge + 1 : 0);
	while (++where_to < lstlen)
	{
		if (ablist[0][where_to].correct > ablist[1][0].correct && \
			ablist[0][where_to ? where_to - 1 : lstlen - 1].correct < \
			ablist[1][0].correct)
			return (where_to);
	}*/
	return (-1);
}

char		*ft_merge_descent(t_pscell **ablist, uintmax_t size)
{
	int		lstlen;
	int		desclen;
	int		merge_spot;
	int		counter;
	int		edge;
	char	*surfacing;
	char	*full_movement;

	full_movement = NULL;
	counter = 0;
	if (ablist && size && (lstlen = ft_psllength(ablist[1])))
	{
		desclen = ft_descent_length(ablist, size);
		full_movement = ft_strnew(size * 2);
		merge_spot = ft_merge_spot(ablist);
		surfacing = ft_speed_surfacing(ablist, merge_spot, 0);
		printf("desclen is %i\n", desclen);
		if (surfacing && full_movement)
		{
			ft_apply_moves(ablist, surfacing);
			ft_strcat(full_movement, surfacing);
			ft_strdel_plus(&surfacing);
			surfacing = ft_strnew(1);
			while (surfacing && counter < desclen)
			{
				ft_bzero(surfacing, ft_strlen(surfacing));
//				lstlen = ft_psllength(ablist[1]);
				edge = ft_sifting_edge(ablist, 0);
				printf("edge is %i size is %ju\n", edge, size);
				printf("ft_highest? %i\n", ft_highest(ablist, size));
				printf("ft_lowest? %i\n", ft_lowest(ablist, size));
				printf("ablist00 = %ju, ablist01 = %ju, edge = %i\n", ablist[0][0].correct, ablist[1][0].correct, edge);
//				ft_pslprint(ablist);
//				getchar();
//				if ((ablist[0][0].correct > ablist[1][0].correct && ablist[1][0].correct > ablist[0][ft_psllength(ablist[0]) - 1].correct) || (edge == 0 && (ft_highest(ablist, size) || ft_lowest(ablist, size))))
				if (ft_merge_validate(ablist))
				{
					surfacing[0] = '1';
					++counter;
				}
				else
				{
					merge_spot = ft_merge_spot(ablist);
					surfacing = ft_speed_surfacing(ablist, merge_spot, 0);
//					surfacing[0] = '8';
				}
				ft_apply_moves(ablist, surfacing);
				ft_strcat(full_movement, surfacing);
			}
		}
	}
	printf("full_movement is %zu ops\nfull_movement is %s\n", ft_strlen(full_movement), full_movement);
//	getchar();
	return (full_movement);
}
