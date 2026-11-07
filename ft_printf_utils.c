#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putnbr_base(unsigned long n, char *base, unsigned long len)
{
	int	count;

	count = 0;
	if (n >= len)
		count += ft_putnbr_base(n / len, base, len);
	count += ft_putchar(base[n % len]);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		return (count + ft_putnbr_base(-(long)n, "0123456789", 10));
	}
	return (ft_putnbr_base(n, "0123456789", 10));
}

int	ft_putptr(void *p)
{
	if (!p)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x")
			+ ft_putnbr_base((unsigned long)p, "0123456789abcdef", 16));
}
