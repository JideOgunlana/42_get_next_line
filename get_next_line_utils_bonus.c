/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:08:44 by bogunlan          #+#    #+#             */
/*   Updated: 2022/06/01 20:11:35 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (len > (size_t)strlen(s))
		len = strlen(s);
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

int	ft_word_count(char const *s, char c)
{
	int				in_word;
	int				word_count;
	unsigned int	i;

	i = 0;
	word_count = 0;
	while (i < strlen(s))
	{
		if (s[i] != c)
		{
			in_word = TRUE;
			while ((in_word) && (++i))
			{
				if ((s[i] == c) || s[i] == '\0')
				{
					word_count++;
					in_word = FALSE;
				}
			}
		}
		i++;
	}
	return (word_count);
}

char	**ft_gen(const char *s, char c, char **res, int res_s_i)
{
	unsigned int	i;
	// int				in_word;
	// int				word_start;

	i = 0;
	while (i < strlen(s))
	{
		if (s[i] == c)
		{
			res[res_s_i] = ft_substr(s, 0, i + 1);
			// if (res[res_s_i] == NULL)
			// 	return (ft_free(res_s_i, res));
			res_s_i++;
			break;
		}
		i++;
	}
	//abcdabc
	// if (s)
	// {
	if (strchr(s, '\n'))
	{
		res[res_s_i] = ft_substr(s, i + 1, strlen(s) - (i + 1));
		
	}
	else
	{
		res[res_s_i++] = ft_substr(s, 0, strlen(s));
	}
	// }
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
	sarray = (char **) malloc(sizeof(char *) * (2 + 1));
	if (!sarray)
		return (NULL);
	sarray = ft_gen(s, c, sarray, sarray_start_index);
	return (sarray);
}
