#include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char    *ft_read_file(int fd, char *stash)
{
    char *buff;
    int     check;

    check = 1;
    buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    while(!ft_strchr(stash, '\n') && check != 0)
    {
        check = read(fd, buff, BUFFER_SIZE);
        if (check == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[check] = '\0';
        stash = ft_strjoin(stash, buff);
    }
    free(buff);
    return (stash);
}

char    *ft_before_next_line(char *stash)
{
    int len;
    int i;
    char *to_return;

    i = -1;
    len = ft_strlen(stash);
    while(len > 0)
    {
        if(stash[len] == '\n')
            break;
        len --;
    }
    to_return = malloc(len * sizeof(char));
    if(!to_return)
        return (NULL);
	while (stash[++i] && stash[i] != '\n')
		to_return[i] = stash[i];
	if (stash[i] == '\n')
	{
		to_return[i] = stash[i];
		i++;
	}
	to_return[i] = '\0';
    return(to_return);
}

char    *get_next_line(int fd)
{
    static char *stash;
    char    *to_return;

    stash = ft_read_file(fd, stash);
    to_return = ft_before_next_line(stash);
    return(to_return);
}


int main()
{
    int fd = open("asd.txt", O_RDWR | O_CREAT, 0777);
    char a[] ="";
    printf("%s", get_next_line(fd));
}