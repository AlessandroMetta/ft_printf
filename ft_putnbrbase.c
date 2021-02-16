void    ft_putchar(char c);

void ft_putnumbase(int nbr, int base, int ESA)
{
	int rem;

	rem = 0;
	if (nbr == 0)
		return;
	else
	{
		rem = nbr % base;
		ft_putnumbase(nbr/base, base, ESA);
		if (base == 16 && rem >= 10 && ESA == 1)
			ft_putchar(rem+55);
		else if (base == 16 && rem >= 10)
			ft_putchar(rem+87);
		else
			ft_putchar(rem+'0');
	}
}
