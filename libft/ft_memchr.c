#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*copy_str;

	i = 0;
	copy_str = (unsigned char*)str;
	while (i < n)
	{
		if (copy_str[i] == (unsigned char)c)
			return ((char *)str + i);
		else
			i++;
	}
	return (NULL);
}
