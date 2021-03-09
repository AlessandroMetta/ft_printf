#include "ft_printf.h"

char 	*ft_itoa_base(unsigned long long int nbr, char *ref_base)
{
	int						size;
	char					*str_nbr;
	unsigned long long int	cp;
	int						base;

	cp = nbr;
	base = ft_strlen(ref_base);
	size = 1;
	while (cp / base)
	{
		size++;
		cp /= base;
	}
	if (!(str_nbr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str_nbr[size--] = '\0';
	str_nbr[0] = '0';
	while (nbr > 0)
	{
		str_nbr[size--] = ref_base[nbr % base];
		nbr /= base;
	}
	return (str_nbr);
}

int		fill(char c, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
