/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 00:29:31 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 22:47:40 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	*ft_readin_nums(char *nums)
{
	char		valid[5];
	int			counter;

	counter = -1;
	ft_bzero(valid, sizeof(char) * 5);
	valid[0] = ' ';
	valid[1] = '-';
	valid[2] = '+';
	valid[3] = '\n';
	if (nums)
	{
		if (ft_longest_num(nums) > 20)
			return (NULL);
		while (nums[++counter])
		{
			if (!ft_isdigit(nums[counter]) && !ft_strchr(valid, nums[counter]))
				return (NULL);
		}
		if (counter)
			return (ft_atoi_array(nums));
	}
	return (NULL);
}

static int	ft_validate_nums(int *nums)
{
	int			size;
	int			countera;
	int			counterb;
	int			current;

	countera = 0;
	counterb = 0;
	if (nums)
	{
		size = nums[0];
		while (++countera <= size)
		{
			current = nums[countera];
			while (++counterb <= size)
			{
				if (current == nums[counterb] && counterb != countera)
					return (0);
			}
		}
		return (1);
	}
	return (0);
}

static int	ft_create_pslist(t_pscell **ablist, int *nums)
{
	int	size;
	char		ret;

	size = 0;
	ret = 0;
	if (ablist && nums)
	{
		size = nums[0];
		if (size && ft_validate_nums(nums))
		{
			ablist[0] = (t_pscell*)ft_memalloc(sizeof(t_pscell) * (size + 1));
			ablist[1] = (t_pscell*)ft_memalloc(sizeof(t_pscell) * (size + 1));
			if (ablist[0] && ablist[1])
				ret = 1;
			else
			{
				if (ablist[0])
					free (ablist[0]);
				if (ablist[1])
					free (ablist[1]);
				ft_bzero(ablist, sizeof(t_pscell*) * 2);
			}
		}
	}
	return (ret);
}

static void	ft_populate_list(t_pscell **ablist, int *nums)
{
	int	counter;
	int	size;

	counter = -1;
	if (ablist && nums)
	{
		size = nums[0];
		while (++counter < size)
		{
			ablist[0][counter].value = nums[counter + 1];
			ablist[0][counter].current = counter;
			ablist[0][counter].active = 1;
		}
	}
}

int		ft_readin(t_pscell **ablist, char *input)
{
	int			ret;
	int	*nums;

	ret = 0;
	nums = NULL;
	nums = ft_readin_nums(input);
	if (nums)
	{
		if (ft_create_pslist(ablist, nums))
		{
			ft_populate_list(ablist, nums);
			ret = 1;
		}
		free(nums);
	}
	return (ret);
}
