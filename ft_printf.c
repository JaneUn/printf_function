#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_info	*info;
	int		total_written;

	if (!format)
		return (-1);
	info = (t_info *)ft_memalloc(sizeof(t_info));
	va_start(info->ap, format);
	info->format = format;
	while (*info->format)
	{
		while (*info->format && *info->format != '%')
		{
			ft_putchar_fd(*info->format, 1);
			info->total_written++;
			info->format++;
		}
		if (*info->format == '%')
			check_spec(info);
	}
	va_end(info->ap);
	total_written = info->total_written;
	free(info);
	return (total_written);
}
