#include "ft_printf.h"

void	check_flag(t_info *info)
{
	while (*info->format == '0' || *info->format == '-')
	{
		if (*info->format == '-')
		{
			info->flag_minus = 1;
			info->format++;
		}
		if (*info->format == '0')
		{
			info->flag_zero = 1;
			info->format++;
		}
	}
}
