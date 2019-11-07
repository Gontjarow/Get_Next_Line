/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:37:32 by ngontjar          #+#    #+#             */
/*   Updated: 2019/10/29 21:41:32 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *str, size_t n)
{
	size_t end;
	size_t bytes;

	if (dst && str)
	{
		end = ft_strlen(dst);
		bytes = 0;
		while (str[bytes] && (bytes < n))
		{
			dst[end + bytes] = str[bytes];
			++bytes;
		}
		dst[end + bytes] = '\0';
	}
	return (dst);
}
