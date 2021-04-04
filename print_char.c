#include "ft_printf.h"

static	void	flag_c(t_info *info)
{
	if (info->width <= 1)
		info->width = 0;
	if (info->flag_zero == 1)
		info->flag_zero = 0;
}

void			print_char(t_info *info)
{
	char	c;

	c = va_arg(info->ap, int);
	flag_c(info);
	if (info->flag_minus == 1)
	{
		info->total_written += ft_putnchar(c, 1);
		print_width(info, 1);
	}
	else
	{
		print_width(info, 1);
		info->total_written += ft_putnchar(c, 1);
	}
	info->format++;
}
