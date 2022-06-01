/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 20:08:47 by bogunlan          #+#    #+#             */
/*   Updated: 2022/06/01 20:09:53 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#define TRUE 1
#define FALSE 0

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char	*get_next_line_bonus(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	**ft_free(int res_st_i, char **res);    


#endif
