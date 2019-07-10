/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:13:24 by hbruvry           #+#    #+#             */
/*   Updated: 2018/10/02 13:16:32 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rtv1.h"

/*
** Return string after removing spaces
*/

static char	*ft_strcln(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		{
			while (str[++i] != '\0')
				str[i - 1] = str[i];
			str[i - 1] = '\0';
			i = -1;
		}
	}
	return (str);
}

/*
** Check if file's brackets are well open and closed
*/

int			ft_checkbrack(char **fcopy)
{
	int		i;
	int		j;
	int		k;
	char	str[4096];

	i = -1;
	j = -1;
	k = -1;
	while (fcopy[++i] != NULL)
	{
		while (fcopy[i][++j] != '\0')
		{
			fcopy[i][j] == '{' ? str[++k] = '{' : 0;
			if (fcopy[i][j] == '}' && str[k] != '{')
				return (0);
			else if (fcopy[i][j] == '}' && str[k] == '{')
				str[k--] = '\0';
		}
		if ((!ft_strcmp(fcopy[i], "scene") || !ft_strcmp(fcopy[i], "camera")
			|| !ft_strcmp(fcopy[i], "light") || !ft_strcmp(fcopy[i], "object"))
			&& str[k] != '\0')
			return (0);
		j = -1;
	}
	return (str[k] ? 0 : 1);
}

/*
** Copy file into a char** table
*/

char		**ft_filecopy(char *file)
{
	int		fd;
	char	b[1];
	int		len;
	char	**fcopy;
	char	*line;

	fcopy = NULL;
	if ((fd = open(file, O_RDONLY)) == -1 || !read(fd, b, 1) || close(fd) == -1)
	{
		ft_putstr("error: bad file\n");
		return (0);
	}
	if ((len = ft_filecheck(file)) != 0)
	{
		if (!(fcopy = ft_memalloc((len + 1) * sizeof(char*)))
			|| (fd = open(file, O_RDONLY)) == -1)
			return (0);
		len = -1;
		while (get_next_line(fd, &line) == 1)
		{
			fcopy[++len] = ft_strdup(ft_strcln(line));
			free(line);
		}
	}
	return (fcopy);
}
