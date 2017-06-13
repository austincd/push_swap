/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 01:56:02 by adaly             #+#    #+#             */
/*   Updated: 2017/06/13 04:27:28 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap_ab(t_pscell **ablist)
{
	if (ablist)
	{
		ft_swap_a(ablist);
		ft_swap_b(ablist);
	}
}

void	ft_swap_a(t_pscell **ablist)
{
	t_pscell temp;

	temp.value = 0;
	temp.current = 0;
	temp.correct = 0;
	temp.next = 0;
	if (ablist)
	{
		temp = ablist[0][0];
		ablist[0][0] = ablist[0][1];
		ablist[0][0].current = 0;
		ablist[0][1] = temp;
		ablist[0][1].current = 1;
	}
}

void	ft_swap_b(t_pscell **ablist)
{
	t_pscell temp;

	temp.value = 0;
	temp.current = 0;
	temp.correct = 0;
	temp.next = 0;
	if (ablist)
	{
		temp = ablist[1][0];
		ablist[1][0] = ablist[1][1];
		ablist[1][1] = temp;
		ablist[1][0].current = 0;
		ablist[1][1].current = 1;
	}
}
