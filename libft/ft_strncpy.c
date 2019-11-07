/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:25:02 by ngontjar          #+#    #+#             */
/*   Updated: 2019/10/29 21:45:47 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *str, size_t n)
{
	size_t i;

	if (dst && str)
	{
		i = 0;
		while (str[i] && (i < n))
		{
			dst[i] = str[i];
			++i;
		}
		if (str[i] == '\0')
		{
			while (i < n)
			{
				dst[i] = '\0';
				++i;
			}
		}
	}
	return (dst);
}
