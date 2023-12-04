#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_strlen(char *src, char c);
char	*ft_strjoin_2(char *s1, char *dest);
char	*ft_strjoin(char *s1, char *buffer);
int		ft_chr_nl(char *buffer);
void	ft_cut_buff(char *buffer);
char	*get_next_line(int fd);

#endif