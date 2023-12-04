#include "get_next_line.h"

int	ft_strlen(char *src, char c)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0' && src[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin_2(char *s1, char *dest)
{
	if (dest == NULL)
		return (NULL);
	if (s1 != NULL)
		free(s1);
	if (dest[0] == '\0')
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}