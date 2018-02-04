/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 19:55:42 by adaly             #+#    #+#             */
/*   Updated: 2017/06/14 05:18:19 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_apply_pushswap(t_pscell **ablist, char c, uintmax_t *sizes)
{
	if (c == '1')
		ft_push_a(ablist, sizes[1]);
	else if (c == '2')
		ft_push_b(ablist, sizes[2]);
	else if (c == '3')
		ft_swap_a(ablist);
	else if (c == '4')
		ft_swap_b(ablist);
	else if (c == '5')
		ft_swap_ab(ablist);
}

static void	ft_apply_rotate(t_pscell **ablist, char c, uintmax_t *sizes)
{
	if (c == '6')
		ft_rotate_a(ablist, sizes[1]);
	else if (c == '7')
		ft_rotate_b(ablist, sizes[2]);
	else if (c == '8')
		ft_revrotate_a(ablist, sizes[1]);
	else if (c == '9')
		ft_revrotate_b(ablist, sizes[2]);
}

static void	ft_apply_rotadeux(t_pscell **ablist, char c, uintmax_t *sizes)
{
	if (c == 'A')
		ft_rotate_ab(ablist, sizes[1], sizes[2]);
	else if (c == 'B')
		ft_revrotate_ab(ablist, sizes[1], sizes[2]);
}

t_pscell	**ft_apply_moves(t_pscell **input_list, char *str, uintmax_t size)
{
	t_pscell	**duplicate;
	uintmax_t	sizes[3];

	sizes[0] = size;
	printf("trying out one\n");
	sizes[1] = ft_pslsize(input_list[0]);
	printf("trying out two\n");
	sizes[2] = ft_pslsize(input_list[1]);
	printf("trying out three\n");
	duplicate = NULL;
	duplicate = ft_psldup(input_list, sizes[0]);
	printf("trying out four\n");
	if (duplicate && str)
	{
		while (*str)
		{
			if (*str >= '1' && *str <= '5')
				ft_apply_pushswap(duplicate, *str, sizes);
			else if (*str >= '6' && *str <= '9')
				ft_apply_rotate(duplicate, *str, sizes);
			else if (*str == 'A' || *str == 'B')
				ft_apply_rotadeux(duplicate, *str, sizes);
			++str;
		}
	}
	return (duplicate);
}
