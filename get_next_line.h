#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 0
#endif

int	ft_strlen(char *s);
char *buffer_appender(char *buffer, char *storage);
char	*ft_strchr(char *s, int c);
char    *linemaker(char *buffer, int c);
char *get_next_line(int fd);
int new_line_checker(char *buffer);

#endif