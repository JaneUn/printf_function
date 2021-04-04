#include "libft.h"

int			ft_atoi(const char *str)
{
	long int	res;
	int			flag;

	res = 0;
	flag = 1;
	while ((*str == '\t' || *str == '\v' || *str == '\n' || \
			*str == '\r' || *str == '\f' || *str == ' ') && *str != '\0')
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ((*str >= '0' && *str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	res = res * flag;
	return (res);
}
