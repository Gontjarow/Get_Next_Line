/*
** > norminette main.c
** main.c: Error!
** Error: TOO_MANY_LINES       (line: 103, col:   1):      Function has more than 25 lines
** > gcc main.c -lft -L. -g -Wall -Wextra -Werror && valgrind ./a.out main.c
*/

#include "libft.h"
#include "fcntl.h"
#include "stdio.h"
#include "assert.h"

#define FD_BUFFER 1024
#define BUFFER_SIZE 128

#define END_OF_FILE 0
#define READ_ERROR -1
#define USER_ERROR -2

/*
** Main function.
** - First checks file-content buffer for additional newlines,
**   to avoid unnecessary reads when the file contains
**   mostly lines shorter than BUFFER_SIZE.
**
** - Reads a block of characters into a buffer and later into file-content buffer.
**
** - If newline is not found, another block of characters is read
**   until newline is found, or the file ends.
**
** - If the file ends without newline, that file's buffer is given as output.
*/
ssize_t			ft_read_line(int fd, char **out);

/*
** Utility function.
** - Gets the next full line from the file-content buffer.
** - If newline is found, all characters before it are duplicated as output.
**   - If newline is followed by text, they are kept in the file-content buffer.
**   - If newline is not followed by text, that file's buffer is nulled. (EOF)
*/
static ssize_t	line_from_buffer(char **buffer, char *newline, char **out);

/*
** Norminette helper.
** 1. Calls read()
** 2. Terminates the string
** 3. Adds to the total bytes read
*/
static ssize_t	read_more(int fd, char *buffer, ssize_t *total_bytes_read);

/*
** Norminette helper.
** 1. Initializes file-content buffer.
** 2. Joins newly read content to any existing content.
*/
static void		append_to_file_content(char **content, char *buffer);

/*
** Norminette helper.
** 1. Frees destination
** 2. Assigns another pointer over it
*/
static void		str_override(char **dest, char *ptr);



ssize_t	ft_read_line(int fd, char **out)
{
	static char	*content[FD_BUFFER];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	ssize_t		total_bytes_read;

	if (out == NULL || (fd < 0 || FD_BUFFER <= fd))
		return (USER_ERROR);
	total_bytes_read = 0;
	while (TRUE)
	{
		if (content[fd] != NULL)
			if (ft_strchr(content[fd], '\n'))
				return (line_from_buffer(&content[fd],
						ft_strchr(content[fd], '\n'), out));
		bytes_read = read_more(fd, buffer, &total_bytes_read);
		*out = content[fd];
		if (bytes_read < 0)
			return (READ_ERROR);
		else if (bytes_read == 0 && content[fd] == NULL)
			return (END_OF_FILE);
		else if (bytes_read == 0 && content[fd] != NULL)
			return (total_bytes_read);
		append_to_file_content(&content[fd], buffer);
	}
}

static ssize_t	line_from_buffer(char **buffer, char *newline, char **out)
{
	size_t	strlen;

	strlen = newline - (*buffer);
	*out = ft_strsub(*buffer, 0, strlen);
	if (newline[1] == '\0')
		ft_strdel(buffer);
	else
		str_override(buffer, ft_strdup(newline + 1));
	return (strlen);
}

static ssize_t	read_more(int fd, char *buffer, ssize_t *total_bytes_read)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	*total_bytes_read += bytes_read;
	return (bytes_read);
}

static void	append_to_file_content(char **content, char *buffer)
{
	if (*content == NULL)
		*content = ft_strnew(0);
	str_override(content, ft_strjoin(*content, buffer));
}

static void	str_override(char **dest, char *ptr)
{
	ft_strdel(dest);
	*dest = ptr;
}



/*
** Just a little test-driver. Reads a fixed amount of lines.
*/
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	ssize_t	bytes;
	int		i;

	argc = argc;
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	i = 1;
	while (i < 170)
	{
		bytes = ft_read_line(fd, &line);
		assert(bytes == (ssize_t)ft_strlen(line));
		printf("read: %3i %s\n", i, line);
		free(line);
		++i;
	}
}
