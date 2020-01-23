
#include "ft_printf.h"

/*
**	FLAGS:
**	'-'	- 00001
**	'+'	- 00010
**	' '	- 00100
**	'#'	- 01000
**	'0'	- 10000
*/

void 	up_to_low(char **s)
{
	int		i;
	int		len;
	char	*str;

	str = *s;
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		str[i] = (str[i] >= 'A' && str[i] <= 'Z') ? str[i] + 32 : str[i];
		i++;
	}
}

char 	*handler_flags(char *str, t_format_sp spec)
{
	int 	len_s;
	int 	len;
	char 	*s;

	len_s = (int)ft_strlen(str);
	len = max(len_s, spec.width);
	if (!(s = ft_strfill(' ', len)))
		return (0);
	if (spec.flags & 1)
		ft_memcpy(s, str, len_s);
	else
		ft_memcpy(s + len - len_s, str, len_s);
	if (spec.flags & 16 && spec.accur == -1 && !(spec.flags & 1))
	{
		ft_memset(s, '0', len - len_s);
		if (ft_strlen(spec.sign))
		{
			ft_memcpy(s + len - len_s, "00", ft_strlen(spec.sign));
			ft_memcpy(s, spec.sign, ft_strlen(spec.sign));
		}
	}
	if (spec.type == 'x' || spec.type == 'p')
		up_to_low(&s);
	free(str);
	return (s);
}
