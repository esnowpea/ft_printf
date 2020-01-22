
#include "ft_printf.h"

/*
**	FLAGS:
**	'-'	- 00001
**	'+'	- 00010
**	' '	- 00100
**	'#'	- 01000
**	'0'	- 10000
*/

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
		if (spec.sign)
		{
			*(s + len - len_s) = '0';
			*s = spec.sign;
		}
	}
	free(str);
	return (s);
}
