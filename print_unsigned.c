#include "ft_printf.h"

static	void	flag_unsigned(int len, char *str, t_info *info)
{
	if (info->prec != -1 && info->prec < len && *str != '0')
		info->prec = len;
	if (info->flag_zero == 1 && info->flag_minus == 1)
		info->flag_zero = 0;
	if (info->flag_zero == 1 && info->prec >= 0)
		info->flag_zero = 0;
}

void			print_unsigned(t_info *info)
{
	char	*str;
	int		len;

	str = ft_utoa(va_arg(info->ap, unsigned int));
	len = ft_strlen(str);
	if (info->prec > len)
		info->extra_zero = info->prec - len;
	flag_unsigned(len, str, info);
	if (info->flag_minus == 1)
		is_minus(str, info);
	else
		not_minus(str, info);
	free(str);
	info->format++;
}
