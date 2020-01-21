#include "ft_printf.h"

static int						ft_len_n(unsigned long long int n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

static unsigned long long int	ft_prov(long long int n, int *minus)
{
	unsigned long long int	num;

	if (n < 0)
	{
		*minus = 1;
		num = (unsigned long long int)(-1 * n);
	}
	else
		num = (unsigned long long int)n;
	return (num);
}

char							*ft_itoa_base_long(long long int n, int base)
{
	char					*str;
	int						minus;
	int						i;
	unsigned long long int	num;

	i = 0;
	minus = 0;
	num = ft_prov(n, &minus);
	if (!(str = (char*)malloc(ft_len_n(num, base) + minus + 1)))
		return (0);
	i = ft_len_n(num, base) + minus;
	str[i--] = '\0';
	if (num == 0)
		str[i--] = '0';
	while (num)
	{
		str[i--] = (num % base < 10) ? num % base + '0' : num % base + 'A' - 10;
		num /= base;
	}
	if (minus)
		str[i--] = '-';
	return (str);
}