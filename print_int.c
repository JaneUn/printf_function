#include "ft_printf.h"

static	void	flag_id(int len, char *str, t_info *info)
{
	if (info->prec > -1 && info->prec < len && *str != '0')
		info->prec = len;
	if (info->flag_zero == 1 && info->flag_minus == 1)
		info->flag_zero = 0;
	if (info->flag_zero == 1 && info->prec >= 0)
		info->flag_zero = 0;
	if (info->width == len && *str != '0')
		info->width = 0;
}

static	int		minus_id(int num, t_info *info)
{
	if (num < 0)
	{
		if (num == -2147483648)
			info->width -= 1;
		else
		{
			info->negative = 1;
			num = num * -1;
			info->width -= 1;
		}
	}
	return (num);
}

void			print_int(t_info *info)
{
	int		num;
	int		len;
	char	*str;

	num = va_arg(info->ap, int);
	num = minus_id(num, info);
	str = ft_itoa(num);
	len = (int)ft_strlen(str);
	if (info->prec > len)
		info->extra_zero = info->prec - len;
	flag_id(len, str, info);
	if (info->flag_minus == 1)
		is_minus(str, info);
	else
		not_minus(str, info);
	free(str);
	info->format++;
}
