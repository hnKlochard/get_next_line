#include "get_next_line.h"

int ft_chr_nl(char *buffer)
{
    int i;

    i = 0;
    if (buffer == NULL)
        return (1);
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        return (0);
    return (1);
}

void    ft_cut_buffer(char *buffer)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        i++;
    while (buffer[i] != '\0')
     {
        buffer[j] = buffer[i];
        i++;
        j++;
     }
     buffer[j] = '\0';
}

char    *ft_strjoin(char *s1, char *buffer)
{
    char    *dest;
    int i;
    int j;

    i = 0;
    j = 0;
    dest = malloc(sizeof(char) * (ft_strlen(s1, '\n') + ft_strlen(buffer, '\n') + 2));

    if (dest != NULL)
    {
        while (s1 && s1[i])
        {
            dest[i] = s1[i];
            i++;
        }
        while (buffer && buffer[j] && buffer[j] != '\n')
        {
            dest[i + j] = buffer[j];
            j++;             
        }
        dest[i + j] = '\n';
        j += (buffer[j] == '\n');
        dest[i + j] = '\0';
    }
    return (ft_strjoin_2(s1, dest));
}

char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1] = {0};
    int bytes_read;
    char    *dest;

    bytes_read = 1;
    dest = NULL;
    if (BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    if (ft_chr_nl(buffer) == 0) //si y'a un retour a la ligne 
    {
        ft_cut_buffer(buffer);
        dest = ft_strjoin(dest, buffer);
    }
    while (bytes_read > 0 && ft_chr_nl(buffer) == 1) //si y'a pas de retour a la ligne 
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
            return (NULL);
        if (bytes_read == 0)
            return (dest);
        buffer[bytes_read] = '\0';
        dest = ft_strjoin(dest, buffer);
    }
    return (dest);
}

int main(void)
{
 int  fd;
 char *line;
 int  count;

 count = 0;
 fd = open("example.txt", O_RDONLY);
 if (fd == -1)
 {
  printf("Error opening file");
  return (1);
 }
 while (1)
 {
  line = get_next_line(fd);
  if (line == NULL)
   break ;
  count++;
  printf("[%d]:%s\n", count, line);
  free(line);
  line = NULL;
 }
 close(fd);
 return (0);
}