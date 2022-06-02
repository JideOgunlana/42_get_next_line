/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:36:10 by bogunlan          #+#    #+#             */
/*   Updated: 2022/06/02 20:00:53 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	newstr = (char *) malloc(sizeof(*s1) * (ft_strlen(s1)+ ft_strlen(s2) + 1));
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

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	const char		*p;

	i = 0;
	p = NULL;
	while (1)
	{
		if (s[i] == (unsigned char) c)
		{
			p = &s[i];
			break ;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return ((char *)(p));
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
        if (ft_strchr(stash, '\n'))
            break ;
    }
	free(str);
	str = NULL;
    return (stash);
}

// void	*check_stash(char *stash)
// {
//     char            **split_string;
// 	char			*result;

// 	if (!stash)
// 	{
//         return (NULL);
// 	}

// 	if (ft_strchr(stash, '\n'))
// 	{
// 		split_string = ft_split(stash, '\n');
// 		if (ft_strlen(split_string[0]) < 1)
// 			result = "\n";
// 		else
// 			result = split_string[0];
// 		stash = NULL;
// 		free(stash);
// 		stash = split_string[1];
// 		free(split_string);
// 	}
// 	return (result);
// }

char	*check_stash(int fd, char *stash[], char *str, char *temp_str)
{
	char	**split_string;
	char	*result;

	stash[fd] = ft_read(fd, str, temp_str, stash[fd]);
    if (!stash[fd] || ft_strlen(stash[fd]) < 1)
		return (NULL);
	if (ft_strchr(stash[fd], '\n'))
	{
		split_string = ft_split(stash[fd], '\n');
		if (ft_strlen(split_string[0]) < 1)
			result = "\n";
		else
			result = split_string[0];
		free(stash[fd]);
		stash[fd] = split_string[1];
		free(split_string);
		return (result);
	}
	// if (ft_strlen(stash[fd]) < 1)
	// {
	// 	free(stash[fd]);
	// 	stash[fd] = NULL; 
	// 	return (NULL);
	// }
	result = stash[fd];
	stash[fd] = NULL;
	return (result);
}

char    *get_next_line(int fd)
{
    char            *str;
    static char     *stash[256];
    char            **split_string;
    char            *temp_str;
	char			*result;

    temp_str = NULL;
    if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
        return NULL;
    str = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!str)
	{
		return NULL;
	}
	result = check_stash(fd, &stash[fd], str, temp_str);
	return result;
}


// void	check(void)
// {
// 	system("leaks a.out");
// }

int main(void)
{
	int		fd1;
	int		fd2;
	// asdf

	// atexit(check);
	fd1 = open("text_1", O_RDONLY);
	fd2 = open("text_2", O_RDONLY);
	printf(":%s:",get_next_line(fd1));
	printf(":%s:",get_next_line(fd2));
	printf(":%s:",get_next_line(fd1));
	printf(":%s:",get_next_line(fd1));
	printf(":%s:",get_next_line(fd1));
	printf(":%s:",get_next_line(fd1));
	printf(":%s:",get_next_line(fd1));
	printf(":%s:\n",get_next_line(fd1));
	printf(":%s:\n",get_next_line(fd1));
	printf(":%s:\n",get_next_line(fd2));
	return (99);
}