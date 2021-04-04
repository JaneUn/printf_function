#include "ft_printf.h"

void	check_prec(t_info *info)
{
	if (*info->format == '.')
	{
		info->format++;
		if (*info->format == '*')
		{
			info->prec = va_arg(info->ap, int);
			info->format++;
		}
		else if (*info->format >= '0' && *info->format <= '9')
		{
			info->prec = 0;
			while (*info->format >= '0' && *info->format <= '9')
			{
				info->prec = (info->prec * 10) + (*info->format - '0');
				info->format++;
			}
		}
		else
			info->prec = 0;
	}
}

void	print_str_prec(t_info *info, char *str, int prec)
{
	int i;

	i = 0;
	while (str[i] && i < prec)
	{
		ft_putchar_fd(str[i], 1);
		i++;
		info->total_written++;
	}
}
