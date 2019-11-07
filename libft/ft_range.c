/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:28:10 by ngontjar          #+#    #+#             */
/*   Updated: 2019/10/29 20:05:42 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int *array;
	int i;

	if (min >= max || !(array = (int *)malloc((max - min) * sizeof(int))))
	{
		return (NULL);
	}
	i = 0;
	while (min < max)
	{
		array[i] = min;
		++i;
		++min;
	}
	return (array);
}
