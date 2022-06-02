/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:08:50 by bogunlan          #+#    #+#             */
/*   Updated: 2022/06/02 18:51:46 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	newstr = (char *) malloc(sizeof(*s1) * (strlen(s1)+ strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
	{
		newstr[i] = s1[i];
	}
	j = -1;
	while (s2[++j] != '\0')
	{
		newstr[i++] = s2[j];
	}
	newstr[i] = '\0';
	return (newstr);
}


char    *ft_read(int fd, char *str, char *temp_str, char *stash)
{

    int bytes;

	bytes = 1;
    while (bytes != 0)
    {
        bytes = read(fd, str, BUFFER_SIZE);
        if (bytes == -1)
        {
            free(str);
            return NULL;
        }
        str[bytes] = '\0';
        temp_str = stash;
        if (!temp_str)
        {
            temp_str = malloc(sizeof(char));
            temp_str[0] = '\0';
        }
        stash = ft_strjoin(temp_str, str);
        free(temp_str);
        if (strchr(stash, '\n'))
            break ;
    }
	free(str);
	str = NULL;
    return (stash);
}

char    *get_next_line(int fd)
{
    char            *str;
    static char     *stash[256];
    char            **split_string;
    char            *temp_str;
    char            *result;

    temp_str = NULL;
    if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
        return NULL;
    str = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!str)
	{
        return NULL;
	}
    stash[fd] = ft_read(fd, str, temp_str, stash[fd]);
    if (!stash[fd])
	{
        return (NULL);
	}
	if (strchr(stash[fd], '\n'))
	{
		split_string = ft_split(stash[fd], '\n');
		if (strlen(split_string[0]) < 1)
			result = "\n";
		else
			result = split_string[0];
		free(stash[fd]);
		stash[fd] = split_string[1];
		free(split_string);
		return (result);
	}
	if (strlen(stash[fd]) < 1)
	{
		free(stash[fd]);
		stash[fd] = NULL; 
		return (NULL);
	}
	result = stash[fd];
	stash[fd] = NULL;
    return (result);
}