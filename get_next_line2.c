
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

char *buffer_appender(char *buffer, char *storage)
{
	int i;
	int buffer_length;
	int storage_length;
	i  = 0;
	buffer_length = ft_strlen(buffer);
	storage_length = ft_strlen(storage);
	buffer = malloc(buffer_length + storage_length);
	//while(i < (buffer_length + storage_length))
	return(0);
}

char	*ft_strchr(char *buffer, int c)
{
	int	i;
	int	x;
	char *storage;

	i = 0;
	x = ft_strlen(buffer);
	while(buffer[i] != c)
		i++;
	storage = malloc(x - i + 1);
	while(++i < x)
		storage[i] = buffer[i];
	storage[x] = '\0';
	return(storage);
}

char	*linemaker(char *buffer, char *line, int i)
{
	int x;

	x = 0;
	//line = malloc(i +  1);
	while (x < i)
	{
		line[x] = buffer[x];
		x++;
	}
	line[i + 1] = '\0';
	//printf("%d\n", strlen(line));
	return (line);
}

char *get_next_line(int fd)
{
	char *buffer;
	static char *storage;
	char *line;
	int index;
	int read_return;

	index = 0;
	read_return = read(fd, buffer, BUFFER_SIZE);
	buffer[read_return] = '\0';
	if(new_line_checker(buffer) == 1)
	{
		while(buffer[index] != '\n')
			index++;
		line = malloc(index + 1);
		line[index + 1] = '\0';
		line = linemaker(buffer, line, index + 1);
		printf("%s", line);
	}
	return(line);
}

int main()
{
	int fd = open("000.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	char *line = malloc(100); 
	line = get_next_line(fd);
	free(line);
}