/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 14:42:12 by adaly             #+#    #+#             */
/*   Updated: 2017/10/03 00:02:43 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_checker(t_pscell **ablist, char *moves)
{
	uintmax_t	size;

	size = 0;
	if (ablist && moves)
	{
		size = ft_psllength(ablist[0]);
		if (size)
		{
			ft_find_correct_positions(ablist);
			ft_apply_moves(ablist, moves);
//			printf("moves are %s\n", moves);
//			ft_pslprint(ablist);
			if (ft_done(ablist))
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
		}
	}
}

int main(int argc, char **argv)
{
	char		*input;
	char		*moves;
	t_pscell	*ablist[3];

	moves = NULL;
	ft_bzero(ablist, sizeof(t_pscell*) * 3);
	input = NULL;
	if (argc == 2)
	{
		input = ft_strdup(argv[1]);
		if (input)
		{
			if (!ft_readin(ablist, input))
				ft_printf("Error\n");
			else
			{
				if ((moves = ft_contract(0)))
				{
					ft_checker(ablist, moves);
					ft_strdel_plus(&moves);
				}
				else
					ft_printf("Error\n");
			}
			ft_strdel_plus(&input);
		}
	}
	return (1);
}
