#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	n1;

	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * (-1);
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	n1 = (n % 10 + '0');
	ft_putchar_fd(n1, fd);
}
