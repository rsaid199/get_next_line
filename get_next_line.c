
// #include "get_next_line.h"

// int	ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strchr(char *buffer, int c)
// {
// 	int	i;
// 	int	x;
// 	char *storage;

// 	i = 0;
// 	x = ft_strlen(buffer);
// 	while(buffer[i] != c)
// 		i++;
// 	storage = malloc(x - i + 1);
// 	while(++i < x)
// 		storage[i] = buffer[i];
// 	storage[x] = '\0';
// 	return(storage);
// }

// char *get_next_line(int fd)
// {
// 	char *buffer;
// 	static char *storage;
// 	char *line;
// 	int i;
// 	int read_return;

// 	buffer = malloc(BUFFER_SIZE);
// 	read_return = read(fd, buffer, BUFFER_SIZE);
// 	buffer[read_return + 1] = '\0';
// 	storage = strchr(buffer, '\n');
// 	printf("%c", storage[0]);
// 	printf("%d", strlen(storage));
// 	return(0);
// }

// int main()
// {
// 	int fd = open("000.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	//char *line = malloc(100);
// 	get_next_line(fd);
// 	//free(line);
// }