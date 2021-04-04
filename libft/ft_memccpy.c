#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*copy_d;
	unsigned char	*copy_s;
	size_t			i;

	i = 0;
	copy_d = (unsigned char *)dest;
	copy_s = (unsigned char *)src;
	while (i < n)
	{
		copy_d[i] = copy_s[i];
		if (copy_s[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
