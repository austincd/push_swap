/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftintmerge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 06:00:06 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 22:51:23 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int		ft_validate(int **ablist, int *lengths, int alpha, int beta)
{
	if (ablist && lengths && alpha < lengths[0] && beta < lengths[1])
	{
		if (ablist[1][beta] < ablist[0][alpha] && ablist[1][beta] > ablist[0][alpha ? alpha - 1 : (lengths[1] - 1)])
			return (1);
	}
	return (0);
}

static t_quadi	ft_align(int **ablist, int *lengths)
{
	t_quadi	alignment;
	int		distance;
	int		status;
	int		limit;

	status = 0;
	distance = 0;
	ft_bzero(&alignment, sizeof(alignment));
	alignment.a = -1;
//	printf("aligning\n");
	if (ablist && lengths)
	{
		limit = lengths[1] > lengths[0] ? lengths[0] : lengths[1];
		while (!status && distance < limit)
		{
//			printf("status : %i\nlimit : %i\ndistance : %i\n", status, limit, distance);
			status = ft_validate(ablist, lengths, distance, limit - distance);
			if (!status)
				status = ft_validate(ablist, lengths, limit - distance, distance);
			else
			{
				alignment.a = distance;
				alignment.b = limit - distance;
			}	
			if (!status)
				++distance;
			else
			{
				alignment.a = limit - distance;
				alignment.b = distance;
			}
		}
	}
//	printf("a = %ji b = %ji\n", alignment.a, alignment.b);
	return (alignment);
}

int	**ft_integerize(t_pscell **ablist, uintmax_t size, int *lengths)
{
	int			**array;
	int			counter;
	uintmax_t	alen;
	uintmax_t	blen;

	array = NULL;
	counter = -1;
	if (ablist && size && lengths)
	{
		alen = ft_psllength(ablist[0]);
		blen = ft_psllength(ablist[1]);
		array = ft_memalloc(sizeof(int*) * 3);
		if (array)
		{
			array[0] = ft_memalloc(sizeof(int) * alen);
			array[1] = ft_memalloc(sizeof(int) * blen);
			while (array[0] && array[1] && ++counter < (intmax_t)size)
			{
				(counter < (intmax_t)alen) ? (array[0][counter] = ablist[0][counter].correct) : 1;
				(counter < (intmax_t)blen) ? (array[1][counter] = ablist[1][counter].correct) : 1;
			}
			lengths[0] = alen;
			lengths[1] = blen;
		}
	}
	return (array);
}

char *ft_merge_surfacing(t_pscell **ablist, uintmax_t size)
{
	t_quadi	alignment;
	int		**converted;
	int		lengths[3];
	char	*surfacing;

	surfacing = NULL;
	ft_bzero(lengths, sizeof(int) * 3);
	converted = NULL;
	if (ablist)
	{
		lengths[0] = ft_psllength(ablist[0]);
		lengths[1] = ft_psllength(ablist[1]);
		converted = ft_integerize(ablist, size, lengths);
		alignment = ft_align(converted, lengths);
		if (alignment.a != -1)
		{
			surfacing = ft_speed_surfacing(ablist, alignment.a, alignment.b);
//			printf("surfacing = %s\n", surfacing);
		}
	}
	(converted && converted[0]) ? free(converted[0]) : 1;
	(converted && converted[1]) ? free(converted[1]) : 1;
	converted ? free(converted) : 1;
	return (surfacing);
}

char	*ft_merge_push(t_pscell **ablist, uintmax_t size)
{
	char	*pushall;
	char	current[2];
	int		counter;
	int		first;

	pushall = NULL;
	current[1] = 0;
	counter = -1;
	if (ablist && size)
	{
		pushall = ft_strnew(size * 2);
		if (pushall)
		{
			while (ft_psllength(ablist[1]))
			{
//				ft_pslprint(ablist);
				first = ft_sifting_edge(ablist, 0);
//				printf("first is %i", first);
//				getchar();
				if (ablist[1][0].correct < ablist[0][0].correct && ((ablist[1][0].correct > ablist[0][ft_psllength(ablist[1]) -  1].correct) || first == 0))
					current[0] = '1';
				else
					current[0] = '6';
				ft_apply_moves(ablist, current);
				ft_strcat(pushall, current);
			}
		}
	}
	return (pushall);
}

char	*ft_merge_ordered(t_pscell **ablist, uintmax_t size)
{
	char	*surface;
	char	*pushall;
	char	*fullmerge;
	t_pscell **testbed;

	testbed = NULL;
	surface = NULL;
	pushall = NULL;
	fullmerge = NULL;
	if (ablist && size)
	{
		testbed = ft_psldup(ablist, size);
//		surface = ft_merge_surfacing(ablist, size);
//		if (surface && testbed)
//		{
//
//		}
		pushall = ft_merge_push(testbed, size);
//		printf("pushall = %s\n", pushall);
		ft_apply_moves(testbed, surface);
//		ft_pslprint(testbed);
//		getchar();
//		fullmerge = pushall ? ft_strjoin(surface, pushall) : NULL;
//		ft_strdel_plus(&surface);
//		ft_strdel_plus(&pushall);
	}
	return (fullmerge);
}
