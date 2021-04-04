#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i_dst;
	size_t	i_src;

	i_dst = 0;
	i_src = 0;
	while (dst[i_dst] && i_dst < size)
		i_dst++;
	while ((src[i_src]) && ((i_dst + i_src + 1) < size))
	{
		dst[i_dst + i_src] = src[i_src];
		i_src++;
	}
	if (i_dst != size)
		dst[i_dst + i_src] = '\0';
	return (i_dst + ft_strlen(src));
}
