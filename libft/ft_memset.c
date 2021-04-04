#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*copy_d;

	copy_d = (unsigned char*)dest;
	while (n--)
	{
		*copy_d = (unsigned char)c;
		copy_d++;
	}
	return (dest);
}
