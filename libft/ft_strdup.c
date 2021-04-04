#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*duplicate;
	size_t	size;

	size = ft_strlen(str) + 1;
	duplicate = (char *)malloc(sizeof(char) * size);
	if (duplicate == NULL)
		return (NULL);
	ft_memcpy(duplicate, str, size);
	return (duplicate);
}
