#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*copy_s;
	unsigned char	*copy_d;

	if (dst == NULL && src == NULL)
		return (NULL);
	copy_d = (unsigned char*)dst;
	copy_s = (unsigned char*)src;
	if (copy_d < copy_s)
	{
		while (len--)
			*copy_d++ = *copy_s++;
	}
	else
	{
		copy_s = copy_s + len;
		copy_d = copy_d + len;
		while (len--)
			*--copy_d = *--copy_s;
	}
	return (dst);
}
