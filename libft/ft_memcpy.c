#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*copy_d;
	unsigned char	*copy_s;

	if (dest != src)
	{
		copy_d = (unsigned char *)dest;
		copy_s = (unsigned char *)src;
		while (len--)
			*copy_d++ = *copy_s++;
	}
	return (dest);
}
