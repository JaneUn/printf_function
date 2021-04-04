#include "ft_printf.h"

char			*utoa_hex(unsigned int n, t_info *info)
{
	char					*str;
	unsigned int			len;
	unsigned int			param;

	len = 1;
	param = n;
	while (param >= 16)
	{
		len++;
		param /= 16;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (n)
	{
		param = n % 16;
		str[--len] = param < 10 ? param + 48 : param % 10 + *info->format - 23;
		n /= 16;
	}
	return (str);
}

static	void	flag_hex(int len, char *str, t_info *info)
{
	if (info->prec != -1 && info->prec < len && *str != '0')
		info->prec = len;
	if (info->flag_zero == 1 && info->flag_minus == 1)
		info->flag_zero = 0;
	if (info->flag_zero == 1 && info->prec >= 0)
		info->flag_zero = 0;
}

void			print_hex(t_info *info)
{
	char				*str;
	int					len;
	unsigned int		num;

	num = va_arg(info->ap, unsigned int);
	if (num == 0)
	{
		str = "0";
		info->null = 1;
	}
	else
		str = utoa_hex(num, info);
	len = ft_strlen(str);
	if (info->prec > len)
		info->extra_zero = info->prec - len;
	flag_hex(len, str, info);
	if (info->flag_minus == 1)
		is_minus(str, info);
	else
		not_minus(str, info);
	if (info->null == 0)
		free(str);
	info->format++;
}
