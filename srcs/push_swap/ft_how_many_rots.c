/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_many_rots.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 16:13:49 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 22:51:53 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A simple function that can be used many times. It takes in an index, the
length of a list, and the index of an existing element and returns how
many rotations are necessary to move that element to said index.

For example, if we want to move element 0 to element 50 in a 51 element list
, that would take 50 reverse-rotations, but just 1 rotation.
*/

#include "../../push_swap.h"
#include <stdio.h>

uintmax_t	ft_how_many_rots(uintmax_t element, uintmax_t destination, uintmax_t length)
{
	uintmax_t	rots;

	rots = 0;
	if (length > element && length > destination)
	{
		if (destination < element)
			rots = element - destination;
		else if (destination > element)
			rots = element + (length - destination);
	}
	return (rots);
}

uintmax_t	ft_how_many_revrots(uintmax_t element, uintmax_t destination, uintmax_t length)
{
	uintmax_t	rots;

	rots = 0;
	if (length > element && length > destination)
	{
		if (destination > element)
			rots = destination - element;
		else if (destination < element)
			rots = destination + (length - element);
	}
	return (rots);
}

static char	ft_speed_surfacing_helper(uintmax_t *rots, uintmax_t *lengths, uintmax_t *elements)
{
	uintmax_t	*revrots;
	uintmax_t	totals[4];

	revrots = rots ? rots + 2 : NULL;
	if (lengths && elements && rots && revrots)
	{
		rots[0] = ft_how_many_rots(elements[0], 0, lengths[0]);
		rots[1] = ft_how_many_rots(elements[1], 0, lengths[1]);
		revrots[0] = ft_how_many_revrots(elements[0], 0, lengths[0]);
		revrots[1] = ft_how_many_revrots(elements[1], 0, lengths[1]);
		totals[0] = (rots[0] >= rots[1]) ? rots[0] : rots[1];
		totals[1] = (revrots[0] >= revrots[1]) ? revrots[0] : revrots[1];
		totals[2] = rots[0] + revrots[1];
		totals[3] = rots[1] + revrots[0];
//		printf("totals = %ju %ju %ju %ju", totals[0], totals[1], totals[2], totals[3]);
		return (ft_ilowest_ju(totals, 4));
	}
	return (-1);
}

static char	*ft_speed_surfacing_helpertwo(uintmax_t *lengths, uintmax_t *rotations, uintmax_t *rotns)
{
	char		*str;
	uintmax_t	rot_ops[2];

	str = NULL;
	if (lengths && rotns && rotations)
	{
		rot_ops[0] = rotations[0] ? rotns[2] : rotns[0];
		rot_ops[1] = rotations[1] ? rotns[3] : rotns[1];
//		printf("rot ops = %ju, %ju\n", rot_ops[0], rot_ops[1]);
		str = ft_strnew((rot_ops[0] + rot_ops[1]) * 2);
		if (str)
		{
			if (rotations[0] == rotations[1])
			{
				ft_memset(str + ft_strlen(str), 'A' + rotations[0], ft_lowest_ju(rot_ops, 2));
				ft_memset(str + ft_strlen(str), ((rotations[0] ? '8' : '6') + ft_ihighest_ju(rot_ops, 2)), ft_absval(rot_ops[0] - rot_ops[1]));
			}
			else
			{
				ft_memset(str + ft_strlen(str), '6' + (2 * rotations[0]), rot_ops[0]);
				ft_memset(str + ft_strlen(str), '7' + (2 * rotations[1]), rot_ops[1]);
			}
		}
	}
//	printf("done with that\n");
	return (str);
}

char	*ft_speed_surfacing(t_pscell **ablist, uintmax_t alpha, uintmax_t beta)
{
	uintmax_t	lengths[2];
	uintmax_t	rot_ops[4];
	uintmax_t	elements[2];
	uintmax_t	rotations[2];
	char		*str;
	/*finds the most efficient way to get one element from each list to spot 0 of that list*/
	
	elements[0] = alpha;
	elements[1] = beta;
	ft_bzero(lengths, sizeof(uintmax_t) * 2);
//	ft_bzero(elements, sizeof(uintmax_t) * 2);
	ft_bzero(rotations, sizeof(uintmax_t) * 2);
	ft_bzero(rot_ops, sizeof(uintmax_t) * 4);
	str = NULL;
	if (ablist)
	{
		lengths[0] = ft_psllength(ablist[0]);
		lengths[1] = ft_psllength(ablist[1]);
		alpha = '0' +  ft_speed_surfacing_helper(rot_ops, lengths, elements);
		if (alpha >= '0')
		{
//			printf("alpha is %ju beta is %ju\n", alpha, beta);
//			printf("rotops = %ju, %ju, %ju, %ju\n", rot_ops[0], rot_ops[1], rot_ops[2], rot_ops[3]);
			if (alpha == '0' || alpha == '2')
				rotations[0] = 0;
			else
				rotations[0] = 1;
			if (alpha == '1' || alpha == '2')
				rotations[1] = 1;
			else
				rotations[1] = 0;
//			printf("rotations = %ju %ju\n", rotations[0], rotations[1]);
			str = ft_speed_surfacing_helpertwo(lengths, rotations, rot_ops);
		}
	}
	return (str);
}
