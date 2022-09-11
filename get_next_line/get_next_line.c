/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:30:46 by yfuentes          #+#    #+#             */
/*   Updated: 2022/07/26 13:52:08 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read_str_concat(int fd, char *str_concat)
{
	char	*buf;
	ssize_t	iter;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	iter = 1;
	while (!ft_strchr_gnl(str_concat, '\n') && iter != 0)
	{
		iter = read(fd, buf, BUFFER_SIZE);
		if (iter == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[iter] = '\0';
		str_concat = ft_strjoin_gnl(str_concat, buf);
	}
	free(buf);
	return (str_concat);
}

char	*get_next_line(int fd)
{
	static char	*str_concat;
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	str_concat = get_read_str_concat(fd, str_concat);
	if (!str_concat)
		return (NULL);
	line = ft_get_line(str_concat);
	str_concat = ft_new_str(str_concat);
	return (line);
}

//int main(int ac, char **av)
/*int	main(void)
{
	int		fd;
	char	*line;

	fd = 1;
	//if (ac == 2)
	//{
	//fd = open("file_test/1char.txt", O_RDONLY);
	//fd = open("file_test/empty.txt", O_RDONLY);
	//fd = open("file_test/only_nl.txt", O_RDONLY);
	//fd = open("file_test/one_line_no_nl.txt", O_RDONLY);
	//fd = open("file_test/variable_nls.txt", O_RDONLY);
	//fd = open("file_test/multiple_nl.txt", O_RDONLY);
	fd = open("file_test/lines_around_10.txt", O_RDONLY);
	//fd = open("file_test/giant_line.txt", O_RDONLY);
	//fd = open("file_test/giant_line_nl.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "No existe archivo\n", 18);
		return (-1);
	}
	//}
	line = get_next_line(fd);
	while (line)
	{
		write(1, line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	system("leaks a.out");
}*/
