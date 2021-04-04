#include "ft_printf.h"

void	check_width(t_info *info)
{
	if (*info->format == '*')
	{
		info->width = va_arg(info->ap, int);
		if (info->width < 0)
		{
			info->flag_minus = 1;
			info->width *= -1;
		}
		info->format++;
	}
	else if (*info->format >= '0' && *info->format <= '9')
	{
		info->width = 0;
		while (*info->format >= '0' && *info->format <= '9')
		{
			info->width = (info->width * 10) + (*info->format - '0');
			info->format++;
		}
	}
}

void	print_width(t_info *info, int length)
{
	while (info->width > length && info->width != 0)
	{
		if (info->flag_zero == 1)
		{
			ft_putchar_fd('0', 1);
			info->total_written++;
		}
		else
		{
			ft_putchar_fd(' ', 1);
			info->total_written++;
		}
		info->width--;
	}
}
