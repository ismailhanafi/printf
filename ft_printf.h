#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_strlen(const char *s);
int	ft_putnbr_base(unsigned long n, char *base, unsigned long len);
int	ft_putnbr(int n);
int	ft_putptr(void *p);

#endif
