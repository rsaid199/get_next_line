#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

int new_line_checker(char *buffer)
{
	int i;
	i = 0;
	while(buffer[i])
	{
		if(buffer[i] == '\n')
			return(1);
		i++;
	}
	return(0);
}

char    *linemaker(char *buffer, int c)
{
    int i = 0;
    int x = 0;
    char *line;

	if (!buffer)
		return (NULL);
    while(buffer[i] != '\n')
	{
		if (buffer[i] == '\0')
			break ;
      i++;
	}
	i++;
    line = malloc(i + 1);
    while(x < i)
    {
      line[x] = buffer[x];
      x++;
    }
    line[x] = '\0';
    return(line);
}

char    *ft_strjoin(char  *s1, char  *s2)
{
    int        i;
    int        s2i;
    char    *z;

    i = 0;
    s2i = 0;
    z = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!z)
        return (NULL);
    while (s1[i] != '\0')
    {
        z[i] = s1[i];
        i++;
    }
    while (s2[s2i] != '\0')
    {
        z[i] = s2[s2i];
        i++;
        s2i++;
    }
    z[i] = '\0';
    return (z);
}

char    *ft_strchr(char *buffer, int c)
{
    int    i;
    int    x;
    int z;
    char *storage;

    i = 0;
    z = 0;

	if (!buffer)
		return (NULL);
    x = ft_strlen(buffer);
    while(buffer[i])
	{
		if (buffer[i] == c)
		{
			break ;
		}
		i++;
	}
	storage = malloc(x - i);
	if (i == x)
		return (NULL);
	if (x - i < 1)
		return (NULL);
    while(++i < x)
        storage[z++] = buffer[i];
    storage[z] = '\0';
    return(storage);
}

char *get_next_line(int fd)
{
	char *buffer;
    static char *storage;
    char *line;
	int read_size = 1;
	
	if (BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size == 0)
		line = linemaker(storage, '\0');
	buffer[read_size] = '\0';
    if(storage != NULL)
      buffer = ft_strjoin(storage, buffer);
    storage = ft_strchr(buffer, '\n');
	if(read_size > 0)
    	line = linemaker(buffer, '\n');
    return(line);
}

int main()
{
	char *line;
	int fd = open("000.txt", O_RDONLY);
	// if (fd == -1)
	// 	return (0);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	// 	printf("%s", line);
	// 	free(line);
	// 	sleep(1);
	// 	line = get_next_line(fd);	
	// printf("%s", line);
	// free(line);
	// sleep(1);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	// sleep(1);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	// sleep(1);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	// sleep(1);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	// sleep(1);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
}