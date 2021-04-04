#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy_s;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	copy_s = (char *)malloc(sizeof(char) * len + 1);
	if (!copy_s)
		return (NULL);
	while (i < len)
	{
		copy_s[i] = s[i + start];
		i++;
	}
	copy_s[i] = '\0';
	return (copy_s);
}
