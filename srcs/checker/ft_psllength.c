/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psllength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:34:24 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 16:37:36 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

uintmax_t	ft_psllength(t_pscell *list)
{
	uintmax_t	size;

	size = 0;
	if (list)
	{
		while (list[size].active)
			++size;
	}
	return (size);
}
