/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfuentes <yfuentes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:24:14 by yfuentes          #+#    #+#             */
/*   Updated: 2022/07/27 12:57:49 by yfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//calculate the length of a string.
size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

/*locates the first instance of c in the string pointed to by s. 
returns a pointer to the located character, or null if it does not exist*/
char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

// Returns a new string, formed by the concatenation of 's1' and 's2'.
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ((ft_strlen_gnl(s1) + ft_strlen_gnl(s2))
				+ 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen_gnl(s1) + ft_strlen_gnl(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_get_line(char *str_concat)
{
	int		i;
	char	*line;

	i = 0;
	if (!str_concat[i])
		return (NULL);
	while (str_concat[i] && str_concat[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str_concat[i] && str_concat[i] != '\n')
	{
		line[i] = str_concat[i];
		i++;
	}
	if (str_concat[i] == '\n')
	{
		line[i] = str_concat[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_str(char *str_concat)
{
	int		i;
	int		j;
	char	*str_new;

	i = 0;
	while (str_concat[i] && str_concat[i] != '\n')
		i++;
	if (!str_concat[i])
	{
		free(str_concat);
		return (NULL);
	}
	str_new = (char *)malloc(sizeof(char) * (ft_strlen_gnl(str_concat) - i
				+ 1));
	if (!str_new)
		return (NULL);
	i++;
	j = 0;
	while (str_concat[i])
		str_new[j++] = str_concat[i++];
	str_new[j] = '\0';
	free(str_concat);
	return (str_new);
}
