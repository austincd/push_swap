/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 19:55:42 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 17:13:35 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_apply_pushswap(t_pscell **ablist, char c)
{
	if (c == '1')
		ft_push_a(ablist);
	else if (c == '2')
		ft_push_b(ablist);
	else if (c == '3')
		ft_swap_a(ablist);
	else if (c == '4')
		ft_swap_b(ablist);
	else if (c == '5')
		ft_swap_ab(ablist);
}

static void	ft_apply_rotate(t_pscell **ablist, char c)
{
	if (c == '6')
		ft_rotate_a(ablist);
	else if (c == '7')
		ft_rotate_b(ablist);
	else if (c == '8')
		ft_revrotate_a(ablist);
	else if (c == '9')
		ft_revrotate_b(ablist);
}

static void	ft_apply_rotadeux(t_pscell **ablist, char c)
{
	if (c == 'A')
		ft_rotate_ab(ablist);
	else if (c == 'B')
		ft_revrotate_ab(ablist);
}

t_pscell	**ft_apply_moves(t_pscell **ablist, char *str)
{
	if (ablist)
	{
		while (*str)
		{
			if (*str >= '1' && *str <= '5')
				ft_apply_pushswap(ablist, *str);
			else if (*str >= '6' && *str <= '9')
				ft_apply_rotate(ablist, *str);
			else if (*str == 'A' || *str == 'B')
				ft_apply_rotadeux(ablist, *str);
			++str;
		}
	}
	return (ablist);
}
