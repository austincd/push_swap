/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 03:22:16 by adaly             #+#    #+#             */
/*   Updated: 2017/06/13 05:14:50 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_shift_down(t_pscell **ablist, char aorb, uintmax_t size)
{
	int n;

	n = 0;
	if (ablist)
	{
		if (aorb == 'a')
			n = 0;
		else if (aorb == 'b')
			n = 1;
		while (size)
		{
			ablist[n][size + 1] = ablist[n][size];
			ablist[n][size + 1].current += 1;
			ablist[n][size + 1].next += 1;
			--size;
		}
		ablist[n][size + 1] = ablist[n][size];
		ablist[n][size + 1].current += 1;
		ablist[n][size + 1].next += 1;
		ablist[n][0].value = 0;
		ablist[n][0].correct = 0;
		ablist[n][0].current = 0;
		ablist[n][0].next = 0;
	}
}

void	ft_shift_up(t_pscell **ablist, char aorb, uintmax_t size)
{
	uintmax_t	counter;
	int n;

	n = 0;
	counter = 0;
	if (ablist)
	{
		if (aorb == 'a')
			n = 0;
		if (aorb == 'b')
			n = 1;
		while (counter < size)
		{
			ablist[n][counter] = ablist[n][counter + 1];
			ablist[n][counter].current -= 1;
			ablist[n][counter].next -= 1;
			++counter;
		}
		ablist[n][size].value = 0;
		ablist[n][size].correct = 0;
		ablist[n][size].current = 0;
		ablist[n][size].next = 0;
	}
}
