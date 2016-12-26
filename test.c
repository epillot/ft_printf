#include "ft_printf.h"

int	main()
{
	int a = 2;
	int b = 2;
	float c = -3141.5;
	void *d = &c;
	t_byte *e = d;
	ft_print_memory(d, sizeof(float));
	for (int i = 0; i < 4; i++)
	{
		ft_print_bits(*(e + i));
		ft_putchar(' ');
	}
	ft_putchar('\n');
	ft_printf("Salut Ton flag 'n' marche ? :p%d%n peut etre que oui peut etre que non :pppp %d\n",a, &a, a);
	printf("Salut Ton flag 'n' marche ? :p%d%n peut etre que oui peut etre que non :pppp %d\n",b, &b, b);
	printf("a : %d, b : %d\n", a, b);
	printf("%f\n", c);
	/*printf("%-1$*.*d\n", 30, 20, 55);
	printf("%5.3$d", 10);*/
}
