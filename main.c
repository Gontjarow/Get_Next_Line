/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:05:19 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/07 16:13:58 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void	cat_file(const char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_putendl(line);
			free(line);
		}
	}
	else
	{
		ft_putstr("Could not open file \"");
		ft_putstr(file);
		ft_putendl("\"");
	}
}

int		main(int argc, char **argv)
{
	int		file;

	if (argc == 1)
	{
		cat_file("files/10100.txt");
	}
	else if (argc >= 2)
	{
		file = 0;
		while (argv[++file])
		{
			cat_file(argv[file]);
		}
	}
}
