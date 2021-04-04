#include "libft.h"

int	ft_putnchar(char c, int n)
{
	int	total_written;

	total_written = 0;
	while (n-- > 0)
	{
		ft_putchar_fd(c, 1);
		total_written++;
	}
	return (total_written);
}
