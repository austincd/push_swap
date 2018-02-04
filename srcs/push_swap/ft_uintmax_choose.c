/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmax_choose.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 02:37:53 by adaly             #+#    #+#             */
/*   Updated: 2017/10/02 23:02:57 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <stdio.h>

/*uintmax_t	ft_uintmax_ilowsel(uintmax_t *elements, uintmax_t num_elements, char *selstr, uintmax_t offset)
{
	uintmax_t	counter;
	uintmax_t	lowest;

	counter = offset;
	lowest = 0;
	if (elements && num_elements && selstr)
	{
		while (counter < num_elements && selstr[counter])
		{
			if ((counter == offset || elements[counter] < lowest) && selstr[counter] == '1')
				lowest = counter;
			++counter;
		}
	}
	return (lowest);
}

uintmax_t	ft_uintmax_lowsel(uintmax_t *elements, uintmax_t num_elements, char *selstr, uintmax_t offset)
{
	uintmax_t	counter;
	uintmax_t	lowest;

	counter = 0;
	lowest = 0;
	if (elements && num_elements && selstr)
	{
		while (counter < num_elements && selstr[counter])
		{
			if ((counter == offset || elements[counter] < lowest) && selstr[counter] == '1')
				lowest = elements[counter];
			++counter;
		}
	}
	return (lowest);
}*/

/*
**ft_jusel_highest is intended to select the greatest out of an array of unsigned integer values,
with some parameters for filtering purposes. char *selstr is a string intended to be composed
entirely of '0' and '1' characters, representing false and true respectively. It should be the
same length in chars as elements is in uintmaxes, and the function only selects from the values in
elements that corrospond to 'true'/'1' values in selstr, checking the same index for both arrays.

locations is a container for some other data. The first element is the offset, or how far in to
the array we should be looking. The second is the number of elements, which will be used as the limit
on the number of iterations our while loop goes through.

bounds is a similar pair of numbers representing the possibility to filter out elements with some
lower and upper bound. the lower bound is the first element of bounds, and the upper element is the
second element. the function will only select the highest number that is in the range established by
the two bounds.
*/

uintmax_t	ft_jusel_highest(uintmax_t *elements, uintmax_t *locations, uintmax_t *bounds, char *selstr)
{
	uintmax_t	counter;
	uintmax_t	highest;
	uintmax_t	offset;
	uintmax_t	num_elements;

	offset = locations[0];
	num_elements = locations[1];
	counter = offset;
	while (elements[counter] < bounds[0] || elements[counter] > bounds[1])
		++counter;
	highest = counter;
	if (elements && num_elements && selstr)
	{
//		printf("selstr = %s\n", selstr);
		while ((counter - offset) < num_elements && selstr[counter])
		{
			if ((counter == offset || (elements[counter] > elements[highest])) && selstr[counter] == '1' && elements[counter] <= bounds[1] && elements[counter] >= bounds[0])
				highest = counter;
			++counter;
		}
	}
	return (highest);
}

/*uintmax_t	ft_uintmax_highsel(uintmax_t *elements, uintmax_t num_elements, char *selstr, uintmax_t offset)
{
	uintmax_t	counter;
	uintmax_t	highest;

	counter = offset;
	highest = 0;
	if (elements && num_elements && selstr)
	{
		while ((counter == offset || counter < num_elements) && selstr[counter])
		{
			if (elements[counter] > highest && selstr[counter] == '1')
				highest = elements[counter];
			++counter;
		}
	}
	return (highest);
}*/
