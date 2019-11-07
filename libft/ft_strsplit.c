/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:08:59 by ngontjar          #+#    #+#             */
/*   Updated: 2019/10/23 00:07:42 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	int count;
	int reading;

	count = 0;
	reading = FALSE;
	while (*str)
	{
		if ((!reading && *str != c) && ++count)
			reading = TRUE;
		else if (reading && *str == c)
			reading = FALSE;
		++str;
	}
	return (count);
}

static void	split2array(char **data, const char *str, char c)
{
	int			reading;
	const char	*end;
	size_t		length;

	reading = FALSE;
	while (*str)
	{
		if (!reading && *str != c)
		{
			reading = TRUE;
			end = ft_strchr(str, c);
			length = (end ? end - str : ft_strlen(str));
			*data++ = ft_strsub(str, 0, length);
		}
		else if (reading && *str == c)
			reading = FALSE;
		++str;
	}
}

char		**ft_strsplit(const char *str, char c)
{
	char		**data;
	size_t		bytes;

	if (!str)
		return (NULL);
	bytes = (word_count(str, c) + 1) * sizeof(char *);
	if (!(data = (char **)malloc(bytes)))
		return (NULL);
	ft_memset((void *)data, '\0', bytes);
	if (bytes == sizeof(char *))
		return (data);
	split2array(data, str, c);
	return (data);
}
