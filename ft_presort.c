/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 05:36:10 by adaly             #+#    #+#             */
/*   Updated: 2017/06/14 05:49:20 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

uintmax_t	*ft_presort(uintmax_t *list, uintmax_t length)
{
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
}

void		ft_record_correct_sorting(t_pscell **ablist, \
uintmax_t *correct, uintmax_t size)
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
				while (counter < size && \
				correct[counter] != ablist[0][listindex].value)
				{
					++counter;
				}
				if (correct[counter] == ablist[0][listindex].value)
				{
					ablist[0][listindex].correct = counter;
					++listindex;
					counter = 0;
				}
			}
		}
	}
}
