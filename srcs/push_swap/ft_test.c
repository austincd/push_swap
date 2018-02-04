/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:03:55 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 20:55:18 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static intmax_t	ft_first_viable(t_pscell **ablist, int which_list, uintmax_t correct)
{
	intmax_t	first;
	intmax_t	remainder;
	uintmax_t	length;

	length = ft_psllength(ablist[which_list]);
	first = ft_sifting_edge(ablist, which_list);
//	printf("first is %ji, length is %ju\n", first, length);
//	printf("correct is %ju\n", correct);
	remainder = first;
	if (correct < (first ? ablist[which_list][first - 1].correct : ablist[which_list][length - 1].correct))
		return (first);
	while (first < (intmax_t)length)
	{
		if (correct > ablist[which_list][first].correct)
			return (first);
		++first;
	}
	if (remainder)
		first = 0;
	while (first < remainder)
	{
		if (correct > ablist[which_list][first].correct)
			return (first);
		++first;
	}
	return (-1);
}

intmax_t	ft_find_right_spot(t_pscell **ablist, intmax_t element)
{
	int			which_list;
	uintmax_t	index;
	uintmax_t	correct_spot;
	intmax_t	first_viable;

	first_viable = -1;
	index = element ? ft_absval(element) - 1 : 0;
	which_list = element < 0 ? 1 : 0;
	if (ft_psllength(ablist[which_list ? 0 : 1]) < 2)
		return (0);
	if (ablist && element && index < ft_psllength(ablist[which_list ? 1 : 0]))
	{
//		printf("hello\n");
		correct_spot = ablist[which_list][index].correct;
//		printf("correct is %ju\n", correct_spot);
		first_viable = ft_first_viable(ablist, which_list ? 0 : 1, correct_spot);
	}
//	printf("first viable is %ji\n", first_viable);
	return (first_viable);
}
