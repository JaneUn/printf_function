#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*s;
	size_t	i2;
	size_t	i1;

	if (*s2 == '\0')
		return ((char *)s1);
	s = (char *)s1;
	while (*s && len >= ft_strlen(s2))
	{
		i2 = 0;
		i1 = 0;
		while (s2[i2] && s[i1] == s2[i2])
		{
			i2++;
			i1++;
		}
		if (s2[i2] == '\0')
			return (s);
		s++;
		len--;
	}
	return (NULL);
}
