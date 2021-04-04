#include "ft_printf.h"

char			*itoa_hex(unsigned long long int num)
{
	char					*str;
	unsigned int			len;
	unsigned long long int	param;

	len = 1;
	param = num;
	while (param >= 16)
	{
		param /= 16;
		len++;
	}
	len += 2;
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	str[len] = '\0';
	while (len > 2)
	{
		param = num % 16;
		str[--len] = param < 10 ? param + 48 : param % 10 + 'a';
		num /= 16;
	}
	return (str);
}

void			print_ptr(t_info *info)
{
	char		*str;
	void		*address;

	address = va_arg(info->ap, void *);
	if (!address)
	{
		if (IS_MACOS)
			str = "0x0";
		else
			str = "(nil)";
       	info->null = 1;
	}
	if (info->null == 0)
		str = itoa_hex((unsigned long long int)address);
	if (info->width < ((int)ft_strlen(str) - 2))
		info->width = 0;
	if (info->flag_minus == 1)
		is_minus(str, info);
	else
		not_minus(str, info);
	if (info->null == 0)
		free(str);
	info->format++;
}
