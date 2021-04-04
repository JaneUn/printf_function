#include "ft_printf.h"

void	is_minus(char *str, t_info *info)
{
	if (info->prec >= 0)
	{
		info->negative == 1 ? info->total_written += ft_putnchar('-', 1) : 0;
		info->total_written += ft_putnchar('0', info->extra_zero);
		print_str_prec(info, str, info->prec);
		print_width(info, info->prec);
	}
	else
	{
		info->negative == 1 ? info->total_written += ft_putnchar('-', 1) : 0;
		ft_putstr_fd(str, 1);
		info->total_written += ft_strlen(str);
		print_width(info, ft_strlen(str));
	}
}

void	not_minus(char *str, t_info *info)
{
	if (info->prec >= 0)
	{
		if (info->negative == 1 && info->width > 0 && info->flag_zero == 1)
		{
			info->total_written += ft_putnchar('-', 1);
			info->negative = 0;
		}
		print_width(info, info->prec);
		info->negative == 1 ? info->total_written += ft_putnchar('-', 1) : 0;
		info->total_written += ft_putnchar('0', info->extra_zero);
		print_str_prec(info, str, info->prec);
	}
	else
	{
		if (info->negative == 1 && info->width > 0 && info->flag_zero == 1)
		{
			info->total_written += ft_putnchar('-', 1);
			info->negative = 0;
		}
		print_width(info, (int)ft_strlen(str));
		info->negative == 1 ? info->total_written += ft_putnchar('-', 1) : 0;
		ft_putstr_fd(str, 1);
		info->total_written += ft_strlen(str);
	}
}

void	null_flags(t_info *info)
{
	info->flag_minus = 0;
	info->flag_zero = 0;
	info->width = 0;
	info->prec = -1;
	info->extra_zero = 0;
	info->null = 0;
	info->negative = 0;
}
