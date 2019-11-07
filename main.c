/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.inter                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngontjar <ngontjar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:50:00 by ngontjar          #+#    #+#             */
/*   Updated: 2019/11/03 11:35:13 by ngontjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int			main(int argc, char **argv)
{
	char	*line;
	int		inter = open("files/timmy_test_interleave.txt", O_RDONLY);
	int		poem2 = open("files/timmy_test_b.txt", O_RDONLY);
	int		poem1 = open("files/timmy_test_a.txt", O_RDONLY);
	int		para = open("files/10k lorem ipsum.txt", O_RDONLY);
	int		dead = open("files/empty.txt", O_RDONLY);
	int		thic = open("files/10100.txt", O_RDONLY);
	int		null = open("files/test_null_cases.txt", O_RDONLY);

	// if (argc == 2)
	// {
	// 	int		eval = open(argv[1], O_RDONLY);
	// 	while (get_next_line(eval, &line))
	// 	{
	// 		ft_putendl(line);
	// 	}
	// }

	// if (argc >= 3)
	// {
	// 	int		eval = open(argv[1], O_RDONLY);
	// 	char i = '0';
	// 	while (++i <= argv[2][0]
	// 		&& get_next_line(eval, &line))
	// 	{
	// 		ft_putendl(line);
	// 	}
	// 	// ft_putendl(line);
	// }

	if (argc == 1)
	{
		// char *line = NULL;
		// int ret;
		while ((ret = get_next_line(dead, &line)) > 0)
		{
			ft_putendl(line);
		}
		// ft_putendl("end");
		// ft_putnbr(ret); ft_putchar('\n');
		// ft_putnbr(ret); ft_putchar('\n');
		// ft_putendl(line);
		// free(line);

		// ret = get_next_line(dead, &line);
		// ft_putnbr(ret);
		// ft_putendl(line);


		// ft_putendl("test:");
		// ft_putendl(line);
		// get_next_line(poem1, &line);
		// ft_putendl(line);

		// get_next_line(eval, &line);
		// ft_putendl(line);
		// get_next_line(eval, &line);
		// ft_putendl(line);
		// get_next_line(para, &line);
		// ft_putendl(line);

		// 	while (get_next_line(para, &line))
		// 		ft_putendl(line);
		// free(line);

		// int i = 0;
		// // main file
		// while (++i < 5 && (get_next_line(inter, &line) >= 0))
		// 	ft_putendl(line);

		// // poem
		// while (get_next_line(poem1, &line) > 0)
		// 	ft_putendl(line);

		// // main file
		// get_next_line(inter, &line);
		// ft_putendl(line);

		// // poem
		// while (get_next_line(poem2, &line) > 0)
		// 	ft_putendl(line);

		// // main file
		// while (get_next_line(inter, &line) > 0)
		// 	ft_putendl(line);
	}
}
