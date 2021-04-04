#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_info
{
	va_list		ap;
	const char	*format;
	int			flag_minus;
	int			flag_zero;
	int			width;
	int			prec;
	int			extra_zero;
	int			null;
	int			negative;
	int			total_written;
}					t_info;

int					ft_printf(const char *format, ...);
void				check_spec(t_info *info);
void				null_flags(t_info *info);
void				check_flag(t_info *info);
void				check_width(t_info *info);
void				print_width(t_info *info, int length);
void				check_prec(t_info *info);
void				is_minus(char *str, t_info *info);
void				not_minus(char *str, t_info *info);
void				print_char(t_info *info);
void				print_string(t_info *info);
void				print_str_prec(t_info *info, char *str, int prec);
void				print_int(t_info *info);
void				print_unsigned(t_info *info);
void				print_hex(t_info *info);
void				print_percent(t_info *info);
void				print_ptr(t_info *info);

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

#endif
