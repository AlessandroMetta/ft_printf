void    ft_putchar(char c);

void	ft_putadd(int nbr)
{
	int rem;

	rem = 0;
	if (nbr == 0)
		return;
	else
	{
		rem = nbr % 16;
		ft_putadd(nbr/16);
		if (rem+102 >= 'a')
			ft_putchar(rem+102);
		else
			ft_putchar(rem+63);
	}
}
