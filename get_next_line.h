#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#define TRUE 1
#define FALSE 0

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);



#endif
