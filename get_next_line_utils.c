/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 17:40:01 by bogunlan          #+#    #+#             */
/*   Updated: 2022/06/01 20:26:06 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	j = 0;
	while ((s[i] != '\0') && (j != len))
	{
		while (i == start &&	 j < len)
		{
			substr[j] = s[j + i];
			j++;
		}
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

char	**ft_free(int res_st_i, char **res)
{
	while (0 <= res_st_i)
	{
		free(res[res_st_i]);
		res_st_i--;
	}
	free(res);
	return (NULL);
}

char	**ft_gen(const char *s, char c, char **res, int res_s_i)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c)
		{
			res[res_s_i] = ft_substr(s, 0, i + 1);
			if (res[res_s_i] == NULL)
				return (ft_free(res_s_i, res));
			res_s_i++;
			break;
		}
		i++;
	}
	if (ft_strchr(s, '\n'))
		res[res_s_i] = ft_substr(s, i + 1, ft_strlen(s) - (i + 1));
	else
		res[res_s_i++] = ft_substr(s, 0, ft_strlen(s));
	res[++res_s_i] = NULL;
	return (res);
}


// This split function includes the delimiter too
char	**ft_split(char const *s, char c)
{
	char	**sarray;
	int		sarray_start_index;

	sarray_start_index = 0;
	if (!s)
		return (NULL);
	sarray = (char **) malloc(sizeof(char *) * 3);
	if (!sarray)
		return (NULL);
	sarray = ft_gen(s, c, sarray, sarray_start_index);
	return (sarray);
}
