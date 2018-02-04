/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:20:23 by adaly             #+#    #+#             */
/*   Updated: 2017/06/12 16:59:54 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

static uintmax_t	ft_score_placement(t_pscell *list, uintmax_t size)
{
	uintmax_t	counter;
	uintmax_t	score;
	uintmax_t	diff;

	score = 0;
	while (counter < size)
	{
		diff = ft_absval(list[counter].correct - list[counter].current);
		score += size - diff;
		++counter;
	}
	return (score);
}

static uintmax_t	ft_arrangement_chain(t_pscell *list, uintmax_t size)
{
	uintmax_t	current;

	counter = 1;
	current = list->correct;
	while (counter < size)
	{
		if (list->next->correct = list->correct + 1)
			++counter;
		else
			return (counter);
	}
	return (size);
}

static uintmax_t	ft_score_arrangement(t_pscell *list, uintmax_t size;)
{
	uintmax_t	counter;
	uintmax_t	score;
	uintmax_t	chain;
	uintmax_t	factor;

	factor = size;
	counter = 0;
	score = 0;
	while (counter < size)
	{
		chain = ft_arrangement_chain(list + counter, size);
		score += ft_power(chain, factor);
		counter += chain;
	}
	return (score);
}

uintmax_t	ft_score(t_pscell **ablist, uintmax_t size)
{
	uintmax_t	score;
	t_pscell	*alist;
	t_pscell	*blist;

	score = 0;
	if (ablist)
	{
		alist = ablist[0];
		blist = ablist[1];
		score += ft_score_arrangement(alist);
		score += ft_score_arrangement(blist);
		score += ft_score_placement(alist);
		score += ft_score_placement(blist);
	}
	return (score);
}
