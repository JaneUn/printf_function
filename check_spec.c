#include "ft_printf.h"

void	check_spec(t_info *info)
{
	info->format++;
	null_flags(info);
	check_flag(info);
	check_width(info);
	check_prec(info);
	if (*info->format == 'c')
		print_char(info);
	else if (*info->format == 's')
		print_string(info);
	else if (*info->format == 'p')
		print_ptr(info);
	else if (*info->format == 'd' || *info->format == 'i')
		print_int(info);
	else if (*info->format == 'u')
		print_unsigned(info);
	else if (*info->format == 'x' || *info->format == 'X')
		print_hex(info);
	else if (*info->format == '%')
		print_percent(info);
}
