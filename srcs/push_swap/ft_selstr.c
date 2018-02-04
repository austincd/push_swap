/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 08:18:17 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 20:40:12 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_selstr_invert(char *selstr)
{
	int	counter;

	counter = -1;
	while (selstr && selstr[++counter])
	{
		if (selstr[counter] == '1')
			selstr[counter] = '0';
		else if (selstr[counter] == '0')
			selstr[counter] = '1';
	}
}

static char	*ft_highlight_halves(t_pscell **ablist, uintmax_t size, char *selstr)
{
	int		value;
	int		counter;
	char	*halves;
	int		upto;
	int		index;

	counter = 0;
	halves = NULL;
	if (ablist && selstr)
	{
		value = -1;
		upto = (ft_charcount(selstr, '1') / 2) + 1;
		halves = ft_strnew(ft_strlen(selstr));
		if (halves)
		{
			ft_memset(halves, '0', ft_strlen(selstr));
			while (++value < (intmax_t)size)
			{
				if (ft_pslfind(ablist, value) > 0)
				{
					index = ft_absval(ft_pslfind(ablist, value)) - 1;
					if (selstr[index] == '1')
					{
						halves[index] = counter >= upto ? '2' : '1';
						++counter;
					}
				}
			}
		}
	}
	return (halves);
}

char		*ft_halfsel_by_dest(t_pscell **ablist, uintmax_t size, char *selstr, char which_half)
{
	char	*highlighted;
	int		counter;

	counter = -1;
	highlighted = NULL;
	if (ablist && size && selstr && (!which_half || which_half == 1))
	{
		highlighted = ft_highlight_halves(ablist, size, selstr);
		while (highlighted && highlighted[++counter])
		{
			if (highlighted[counter] != '1' + which_half)
				highlighted[counter] = '0';
			else if (highlighted[counter] == '2')
				highlighted[counter] = '1';
		}
	}
	return (highlighted);
}
