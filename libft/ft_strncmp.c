#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	if (*str1 == '\0' || *str2 == '\0')
		return ((unsigned char)*str1 - (unsigned char)*str2);
	while (n > 0 && (*str1 || *str2))
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
