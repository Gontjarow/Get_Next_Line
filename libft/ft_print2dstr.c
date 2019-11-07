/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2dstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:22:09 by ngontjar          #+#    #+#             */
/*   Updated: 2019/10/29 19:56:21 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print2dstr(char **array, int count)
{
	int i;

	if (array != NULL)
	{
		i = 0;
		while (i < count)
		{
			ft_putstr(array[i]);
			ft_putchar('\n');
			++i;
		}
	}
}
