/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pslprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 00:54:49 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 17:14:16 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

static void	ft_pslprint_helper(t_pscell *list)
{
	uintmax_t	counter;
	uintmax_t	length;

	counter = 0;
	length = 0;
	if (list)
	{
		length = ft_psllength(list);
		printf("len = %ju\n", length);
		while (counter < length)
		{
//			printf("LIST MEMBER %ju\nMEMBER CORRECT %ju\nPROXSCORE: %ju\nPLACESCORE: %ju\n VAL=%ji\n", \
//					counter, list[counter].correct, ft_scoreone_proximity(ablist, size, counter, aorb), ft_scoreone_placement(ablist, size, counter, aorb), list[counter].value);
			printf("Spot %ju: %ju\n", counter, list[counter].correct);
			++counter;
		}
	}
}

void	ft_pslprint(t_pscell **ablist)
{
	if (ablist)
	{
		printf("___________PRINTING LIST A!___________\n");
		ft_pslprint_helper(ablist[0]);
		printf("___________PRINTING LIST B!___________\n");
		ft_pslprint_helper(ablist[1]);
		printf("______DONE!______\n");
//		printf("TOTAL SCORE = %ju\n", ft_score(ablist, size));
	}
}
