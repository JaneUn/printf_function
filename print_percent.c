#include "ft_printf.h"

static	void	flag_percent(t_info *info)
{
	if (info->width <= 1)
		info->width = 0;
	if (info->flag_zero == 1 && info->flag_minus == 1)
		info->flag_zero = 0;
}

void			print_percent(t_info *info)
{
	if (IS_MACOS)
	{
		flag_percent(info);
		if (info->flag_minus == 1)
		{
			info->total_written += ft_putnchar('%', 1);
			print_width(info, 1);
		}
		else
		{
			print_width(info, 1);
			info->total_written += ft_putnchar('%', 1);
		}
	}
	else
		info->total_written += ft_putnchar('%', 1);
	info->format++;
}
