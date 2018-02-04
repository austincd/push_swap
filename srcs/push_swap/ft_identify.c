/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:52:49 by adaly             #+#    #+#             */
/*   Updated: 2017/10/05 07:32:37 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

char	*ft_find_best_ascent(t_pscell **ablist)
{
	uintmax_t	*counts;
	uintmax_t	size;
	char		*best;
	char		**ascents;

	best = NULL;
	if (ablist)
	{
		size = ft_psllength(ablist[0]);
		ascents = ft_identify_ascent(ablist, size, 0);
		counts = ft_count_ascent(ablist, size, 0, ascents);
		best = ft_best_ascent(size, ascents, counts);
	}
	return (best);
}

char	*ft_best_ascent(uintmax_t length, char **ascents, uintmax_t *counts)
{
	uintmax_t	current;
//	char	*best;

	current = 0;
//	best = ft_strnew(length);
	if (length && counts)// && best
	{
//		ft_memset(best, '0', length);
		current = ft_ihighest_ju(counts, length);
/*		while (current < length - 1)
		{
			params[1] = length - current;
			params[0] = current + 1;
			params[3] = counts[current] - 1;
			next = ft_jusel_highest(counts, params, params + 2, ascents[current]);
			best[current] = '1';
//			printf("best is: %s\n", best);
//			printf("ascents[current]:%s\n", ascents[current]);
//			printf("current spot is : %ju count = %ju\n", current, counts[current]);
//			printf("next is : %ju count = %ju\\n", next, counts[next]);
//			getchar();
			if (current && ascents[current][current - 1] == '1' && counts[current - 1] >= counts[next])
			{
				best[current - 1] = '2';
				params[3] = counts[current - 1];
				next = ft_jusel_highest(counts, params, params + 2, ascents[current - 1]);
			}
			if (current < next && counts[current])
				current = next;
			else
				break;*/
	}
	return (ascents[current]);
}

uintmax_t	*ft_count_ascent(t_pscell **ablist, uintmax_t size, int which_list, char **ascents)
{
	uintmax_t	length;
	uintmax_t	counter;
	uintmax_t	*counts;

	counts = NULL;
	counter = 0;
	if (ablist && size && ascents)
	{
		length = ft_psllength(ablist[which_list]);
		if (length)
			counts = (uintmax_t*)ft_memalloc(sizeof(uintmax_t) * (length + 1));
		while (counts && counter < length)
		{
			counts[counter] = ft_charcount((ascents[counter] + counter), '1');
//			printf("ascents[%ju] is %s\nascents[%ju] + %ju is %s\n", counter, ascents[counter], counter, counter, ascents[counter] + counter);
//			printf("counts[%ju] is %ju\n", counter, counts[counter]);
			++counter;
		}
	}
	return (counts);
}

char	**ft_identify_ascent(t_pscell **ablist, uintmax_t size, int which_list)
{
	char		**strs;
	uintmax_t	length;
	uintmax_t	counter;

	strs = NULL;
	counter = 0;
	if (ablist && size)
	{
		length = ft_psllength(ablist[which_list]);
		if (length)
			strs = (char**)ft_memalloc(sizeof(char*) * (length + 1));
		while (strs && counter < length)
		{
			
			strs[counter] = ft_identify_bymin(ablist, size, which_list, counter);
//			printf("strs[ctr] is %s\n", strs[counter]);
			if (strs[counter])
				++counter;
		}
	}
	return (strs);
}

char	*ft_identify_bymin(t_pscell **ablist, uintmax_t size, int which_list, uintmax_t min)
{
	char		*str;
	uintmax_t	counter;
	uintmax_t	beta;
	uintmax_t	length;
	uintmax_t	start;

	counter = 0;
	str = NULL;
	beta = 0;
	start = 0;
	if (ablist && size)
	{
		length = ft_psllength(ablist[which_list]);
		str = length ? ft_strnew(length) : NULL;
		while (str && counter < length)
		{
			str[counter] = '0';
			if (ablist[which_list][counter].correct == min + beta)
			{
				if (!beta)
					start = counter;
				str[counter] = '1';
				++beta;
			}
			++counter;
		}
		counter = 0;
		while (counter < start)
		{
			if (ablist[which_list][counter].correct == min + beta)
			{
				if (!beta)
					start = counter;
				str[counter] = '1';
				++beta;
			}
			++counter;
		}
	}
	return (str);
}
