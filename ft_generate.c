/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 19:19:02 by adaly             #+#    #+#             */
/*   Updated: 2017/06/13 19:34:14 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	**ft_generate_moves(uintmax_t depth)
{
	uintmax_t	set_limit;
	uintmax_t	counter;
	char		**set;

	counter = 0;
	set = NULL;
	set_limit = ft_power(depth, 12);
	set = (char**)ft_memalloc(sizeof(char*) * set_limit + 1);
	while (counter < set_limit)
	{
		set[counter] = ft_itoa_base(counter, 12);
		printf("set[%ju] = %s\n", counter, set[counter]);
		++counter;
	}
	return (set);
}
