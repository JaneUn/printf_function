#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	int				len;
	char			*str;
	unsigned int	param;

	len = 1;
	param = n;
	while (param >= 10)
	{
		len++;
		param /= 10;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (n >= 10)
	{
		str[--len] = n % 10 + 48;
		n /= 10;
	}
	str[--len] = n % 10 + 48;
	return (str);
}
