#include "ft_printf.h"

static	void	flag_s(int len, char *str, t_info *info)
{
	if (info->width <= (int)ft_strlen(str - info->prec))
		info->width = 0;
	if (info->prec > len)
		info->prec = len;
	if (info->flag_zero == 1)
		info->flag_zero = 0;
}

void			print_string(t_info *info)
{
	char		*str;
	int			len;

	str = va_arg(info->ap, char *);
	if (!str)
	{
		str = "(null)";
		if (!(IS_MACOS) && info->prec < 6 && info->prec >= 0)
			str = "";
	}
	if (info->prec == 0)
		str = "";
	len = (int)ft_strlen(str);
	flag_s(len, str, info);
	if (info->flag_minus == 1)
		is_minus(str, info);
	else
		not_minus(str, info);
	info->format++;
}
