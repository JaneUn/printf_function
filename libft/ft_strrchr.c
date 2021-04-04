#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	last;

	last = 0;
	while (str[last] != '\0')
		last++;
	if ((char)c == 0)
		return ((char *)str + last);
	while (last)
	{
		last--;
		if (str[last] == (char)c)
			return ((char *)str + last);
	}
	return (NULL);
}
