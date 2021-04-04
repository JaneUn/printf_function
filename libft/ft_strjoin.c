#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*sum_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	sum_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (sum_str == NULL)
		return (NULL);
	while (i < len_s1)
	{
		sum_str[i] = s1[i];
		i++;
	}
	while (j < len_s2)
		sum_str[i++] = s2[j++];
	sum_str[i] = '\0';
	return (sum_str);
}
