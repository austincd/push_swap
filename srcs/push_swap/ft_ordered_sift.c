/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ordered_sift.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 21:04:18 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 20:55:59 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*static char	*ft_generate_makeadj_str(uintmax_t	*pair, char rotation, char pushto)
{
	char		*str;
	char		which_list;
	char		moves[3];
	uintmax_t	highlow[2];

	moves[0] = rotation ? 'B' : 'A';
	moves[1] = rotation ? '8' : '6';
	str = NULL;
	if (pair)
	{
		which_list = pair[0] > pair[1] ? 1 : 0;
		highlow[0] = which_list ? pair[0] : pair[1];
		highlow[1] = which_list ? pair[1] : pair[0];
		moves[1] += which_list;
		moves[2] = pushto ? '2' : '1';
		str = ft_strnew(pair[(which_list ? 0 : 1)] + 1);
		if (str)
		{
			ft_memset(str + ft_strlen(str), moves[0], highlow[1]);
			ft_memset(str + ft_strlen(str), moves[1], highlow[0] - highlow[1]);
			ft_memset(str + ft_strlen(str), moves[2], 1);
		}
	}
	return (str);
}

char	*ft_makeadj_str(uintmax_t *pairs, char pushto)
{
	char		reverse;
	int			counter;
	int			savespot;
	uintmax_t	highest_element;
	char		*str;

	str = NULL;
	counter = 0;
	highest_element = 0;
	if (pairs)
	{
		while (counter < 4)
		{
			if (pairs[counter] > highest_element)
			{
				highest_element = pairs[counter];
				savespot = counter;
			}
			++counter;
		}
		reverse = ((savespot > 1) ? 0 : 1);
		str = ft_generate_makeadj_str(pairs + (reverse * 2), reverse, pushto); 
//		printf("str : %s\n", str);
		//free(pairs);
	}
	return (str);
}*/

char	*ft_iteration_osift(t_pscell **ablist, uintmax_t size, int which_list)
{
	char		*best;
	intmax_t	best_topush;
	intmax_t	pushto;
	intmax_t	radius;
	intmax_t	limit;

//	limit = (intmax_t)((size / 2) + 2);
	limit = 260;
	if ((ft_psllength(ablist[which_list ? 0 : 1]) > (size - (size / 4))))
		 limit = 4;
	pushto = -1;
	best_topush = -1;
	radius = -1;
	best = NULL;
	while ((pushto == -1 || best_topush == -1) && radius < limit)
	{
		++radius;
		best_topush = ft_orderedpush(ablist, size, radius, which_list);
		pushto = ft_find_right_spot(ablist, (best_topush + 1) * (which_list ? -1 : 1));
//		printf("radius is %ji, best_topush is %ji, pushto is %ji\n", radius, best_topush, pushto);
//		getchar();
	}
	if (pushto >= 0 && best_topush >= 0)
	{
		best = ft_speed_surfacing(ablist, best_topush, pushto);
		if (best)
			best[ft_strlen(best)] = which_list ? '1' : '2';
	}
	return (best);
}

char	*ft_ordered_sift(t_pscell **ablist, uintmax_t size, int which_list)
{
	char		*solution;
	char		*moves;
	t_pscell	**duplicate;

	solution = NULL;
	moves = NULL;
	duplicate = ft_psldup(ablist, size);
	if (duplicate && size && ft_psllength(duplicate[which_list]))
	{
		while ((moves = ft_iteration_osift(duplicate, size, which_list)))
		{
			if (moves)
			{
				ft_apply_moves(duplicate, moves);
				ft_restrcat(&solution, moves);
//				printf("ordered sift is now %s\n", solution);
				ft_strdel_plus(&moves);
			}
		}
	}
	return (solution);
}
