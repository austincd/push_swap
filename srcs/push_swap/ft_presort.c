/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 05:36:10 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 16:49:31 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

intmax_t	*ft_presort(intmax_t *list, uintmax_t length)
{
	uintmax_t	index;
	uintmax_t	counter;
	uintmax_t	temp;
	
	temp = 0;
	index = 0;
	counter = 0;
	if (list)
	{
		while (counter <= length)
		{
			while (index < (length - 1))
			{
				if (list[index] > list[index + 1])
				{
					temp = list[index];
					list[index] = list[index + 1];
					list[index + 1] = temp;
				}
				++index;
			}
			++counter;
			index = 0;
		}
	}
	return (list);
}

static int			ft_already_taken(t_pscell **ablist, uintmax_t cor, uintmax_t index)
{
	uintmax_t	counter;
	uintmax_t	length;

	counter = 0;
	length = ft_psllength(ablist[0]);
	while (counter < index)
	{
//		printf("ab[0][%ju] is %ju\ncor is %ju\n", counter, ablist[0][counter].correct, cor);
		if (ablist[0][counter].correct == cor)
			return (1);
		++counter;
	}
	return (0);
}

void		ft_record_correct_sorting(t_pscell **ablist, \
intmax_t *correct, uintmax_t size)
{
	uintmax_t	counter;
	uintmax_t	listindex;

	counter = 0;
	listindex = 0;
	if (ablist && correct)
	{
		if (ablist[0])
		{
			while (listindex < size)
			{
//				printf("ablist[0][%ju] = %ji\nsize = %ju\n", listindex, ablist[0][listindex].value, size);
				while (counter < size && \
				(correct[counter] != ablist[0][listindex].value || ft_already_taken(ablist, counter, listindex)))
				{
//					printf("correct[%ju] is %ji \n", counter, correct[counter]);
					++counter;
				}
				if (correct[counter] == ablist[0][listindex].value)
				{
					ablist[0][listindex].correct = counter;
					++listindex;
					counter = 0;
				}
//				getchar();
			}
		}
	}
}

void		ft_find_correct_positions(t_pscell **ablist)
{
	intmax_t	*unsorted_values;
	intmax_t	*sorted_values;
	uintmax_t	how_many_values;
	uintmax_t	counter;

	counter = 0;
	unsorted_values = NULL;
	sorted_values = NULL;
	how_many_values = ft_psllength(ablist[0]);
	unsorted_values = (intmax_t*)ft_memalloc(sizeof(intmax_t) * how_many_values);
	while (counter < how_many_values)
	{
		unsorted_values[counter] = ablist[0][counter].value;
		++counter;
	}
	sorted_values = ft_presort(unsorted_values, how_many_values);
	ft_record_correct_sorting(ablist, sorted_values, how_many_values);
	free(sorted_values);
}
