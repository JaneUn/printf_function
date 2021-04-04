#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size_s1;
	char	*result_str;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_s1 = ft_strlen(s1);
	while (size_s1 && ft_strchr(set, s1[size_s1]))
		size_s1--;
	result_str = ft_substr((char *)s1, 0, size_s1 + 1);
	return (result_str);
}
