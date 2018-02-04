/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 03:51:17 by adaly             #+#    #+#             */
/*   Updated: 2017/10/03 00:03:03 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void		ft_populate_ops(char **fullops, char *shortops)
{
	int	ctr;

	ctr = -1;
	if (fullops)
	{
		ft_bzero(fullops, sizeof(char*) * 12);
		fullops[0] = ft_strdup("pa");
		fullops[1] = ft_strdup("pb");
		fullops[2] = ft_strdup("sa");
		fullops[3] = ft_strdup("sb");
		fullops[4] = ft_strdup("sab");
		fullops[5] = ft_strdup("ra");
		fullops[6] = ft_strdup("rb");
		fullops[7] = ft_strdup("rra");
		fullops[8] = ft_strdup("rrb");
		fullops[9] = ft_strdup("rab");
		fullops[10] = ft_strdup("rrab");
	}
	if (shortops)
	{
		ft_bzero(shortops, sizeof(char) * 12);
		while (++ctr < 12)
		shortops[ctr] = ((ctr < 9) ? '1' + ctr : 'A' + (ctr - 9));	
	}
}

static void		ft_forget_ops(char **fullops, char *shortops)
{
	int		counter;

	counter = -1;
	while (fullops && fullops[++counter] && counter < 11)
	{
		if (fullops[counter])
			ft_strdel_plus(fullops + counter);
	}
	if (shortops)
		ft_bzero(shortops, sizeof(char) * 11);
}

void	ft_expand_print(char *moveset)
{
	char	*fullops[12];
	char	shortops[12];
	char	*location;
	int		index;

	if (moveset && ft_strlen(moveset))
	{
		ft_populate_ops(fullops, shortops);
		while (*moveset)
		{
			if ((location = ft_strchr(shortops, *moveset)))
			{
				index = location - shortops;
				ft_putendl(fullops[index]);
			}
			++moveset;
		}
		ft_forget_ops(fullops, shortops);
	}
}

static char	ft_contract_helper(int fd, char **fullops, char *shortops)
{
	int		index;
	char	*line;

	index = -1;
	line = NULL;
	if (fullops && shortops)
	{
		if (get_next_line(fd, &line) == 1 && line)
		{
			index = ft_strequ_multi(line, fullops, 11);
			if (ft_strequ(line, fullops[9]))
				index = 9;
			else if (ft_strequ(line, fullops[10]))
				index = 10;
			else if (ft_strequ(line, fullops[2]))
				index = 2;
			else if (ft_strequ(line, fullops[3]))
				index = 3;
			else if (ft_strequ(line, fullops[4]))
				index = 4;
//			printf("index is %i, line is %s\n", index, line);
			ft_strdel_plus(&line);
			if (index >= 0)
				return (shortops[index]);
		}
	}
	return (0);
}

char	*ft_contract(int fd)
{
	char	*fullops[12];
	char	shortops[12];
	char	*moveset;
	char	padding[10001];
	int		counter;

	counter = 0;
	ft_bzero(padding, 10001);
	ft_memset(padding, '0', 10000);
	moveset = NULL;
	ft_populate_ops(fullops, shortops);
	if (fd >= 0 && (moveset = ft_strnew(10000)))
	{
		while (1)
		{
			moveset[counter] = ft_contract_helper(fd, fullops, shortops);
			if (!moveset[counter])
			{
				ft_forget_ops(fullops, shortops);
				return (moveset);
			}
			++counter;
			if (counter > 10000)
			{
				ft_restrcat(&moveset, padding);
				ft_bzero(ft_strchr(moveset, '0'), 10000);
			}
		}
	}
	ft_forget_ops(fullops, shortops);
	return (moveset);
}
